#include <exception>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <set>
#include <sstream>
#include <string>

void ReadFromJson(const cv::FileStorage& dataset, cv::FileNode& roads, cv::FileNode& cars) {
  roads = dataset["roads"];
  if (roads.empty()) {
    throw std::logic_error("Json of roads is empty");
  }
  cars = dataset["cars"];
  if (cars.empty()) {
    throw std::logic_error("Json of cars is empty");
  }
}

cv::Mat ReadImage(const std::string name) {
  cv::Mat image = cv::imread(name);
  if (image.empty()) {
    throw std::logic_error("Image hasn't been found: " + name);
  }
  return image;
}

bool IsWhite(const cv::Mat mask,  int i, const int j) {
  return (255 == mask.at<cv::Vec3b>(i, j)[0]
       && 255 == mask.at<cv::Vec3b>(i, j)[1]
       && 255 == mask.at<cv::Vec3b>(i, j)[2]);
}

std::pair<int, int> HeightOfMask(const cv::Mat mask) {
  std::pair<int, int> height(std::make_pair(-1, -1));
  for (int i = 0; i < mask.rows; ++i) {
    for (int j = 0; j < mask.cols; ++j) {
      if (IsWhite(mask, i, j)) {
        height.second = i;
        if (-1 == height.first) {
          height.first = i;
        }
      }
    }
  }
  return height;
}

int RandomNumber(const std::pair<int, int> number) {
  return (number.first + rand() % (number.second - number.first));
}

std::pair<int, int> WidthOfMask(const cv::Mat mask, const int height) {
  std::pair<int, int> width = std::make_pair(-1, -1);
  for (int j = 0; j < mask.cols; ++j) {
    if (IsWhite(mask, height, j)) {
      width.second = j;
      if (-1 == width.first) {
        width.first = j;
      }
    }
  }
  return width;
}

std::pair<int, int> WidthOfMask(const cv::Mat mask) {
  std::pair<int, int> width = std::make_pair(-1, -1);
  for (int j = 0; j < mask.cols; ++j) {
    for (int i = 0; i < mask.rows; ++i) {
      if (IsWhite(mask, i, j)) {
        width.second = j;
        if (-1 == width.first) {
          width.first = j;
        }
      }
    }
  }
  //for (int i = mask.rows - 1; i > 0 && width.first == -1; --i) {
  //  for (int j = 0; j < mask.cols; ++j) {
  //    if (IsWhite(mask, i, j)) {
  //      width.second = j;
  //      if (-1 == width.first) {
  //        width.first = j;
  //      }
  //    }
  //  }
  //}
  return width;
}

void AlphaBlending(cv::Mat car, cv::Mat car_mask, cv::Mat road, cv::Mat road_mask, int i_out_image) {
  std::pair<int, int> height_of_road = HeightOfMask(road_mask);
  int random_height = RandomNumber(height_of_road);
  std::pair<int, int> width_of_road = WidthOfMask(road_mask, random_height);
  std::pair<int, int> width_of_car = WidthOfMask(car_mask);
  // Convert Mat to float data type
  car.convertTo(car, CV_32FC3);
  road.convertTo(road, CV_32FC3);
  // Normalize the alpha mask to keep intensity between 0 and 1 
  car_mask.convertTo(car_mask, CV_32FC3, 1.0 / 255);

  int r = RandomNumber(std::make_pair(40, 50));
  //std::cout << r << std::endl;
  double coeff = (width_of_car.second - width_of_car.first) * 100.0
    / ((width_of_road.second - width_of_road.first)
      * r);
  cv::Size new_size(car.cols / coeff + 0.5, car.rows / coeff + 0.5);
  resize(car, car, new_size);
  resize(car_mask, car_mask, new_size);
  multiply(car_mask, car, car);
  std::pair<int, int> coordinates_of_car = std::make_pair(random_height 
      - car.rows, (width_of_road.first + width_of_road.second - car.cols) / 2);
  cv::Rect rect_of_car(coordinates_of_car.second, coordinates_of_car.first,
      car.cols, car.rows);
  cv::Mat roi_of_car = road(rect_of_car);
  multiply(cv::Scalar::all(1.0) - car_mask, roi_of_car, roi_of_car);
  add(car, roi_of_car, roi_of_car);
  cv::Mat out_image = road;
  roi_of_car.copyTo(out_image(rect_of_car));

  //imshow("d", out_image / 255);
  //cv::waitKey();
  std::string path = "../result/";
  std::string name = std::to_string(i_out_image);
  std::string type = ".png";
  std::string filename = path + name + type;
  cv::imwrite(filename, out_image);
}

int main() {

  std::cout << "How many images do you want to get?" << std::endl;
  int n_image;
  std::cin >> n_image;
  cv::FileStorage dataset("dataset.json", 0);
  cv::FileNode roads;
  cv::FileNode cars;
  try {
    ReadFromJson(dataset, roads, cars);
  }
  catch (const std::logic_error& exception) {
    std::cout << exception.what() << std::endl;
    return 0;
  }
 
  int n_image_cur = 0;
  std::set<std::string> not_found_images;
  for (int i_car = 0; n_image_cur < n_image; i_car = ++i_car % cars.size()) {
    try {
      cv::Mat car = ReadImage(cars[i_car]["image"]);
      cv::Mat car_mask = cv::imread(cars[i_car]["mask"]);
      for (int i_road = 0; i_road < roads.size(); ++i_road) {
        try {
          cv::Mat road = ReadImage(roads[i_road]["image"]);
          for (int i_mask = 0; i_mask < roads[i_road]["mask"].size(); ++i_mask) {
            try {
              cv::Mat road_mask = ReadImage(roads[i_road]["mask"][i_mask]);
              AlphaBlending(car, car_mask, road, road_mask, n_image_cur);
              ++n_image_cur;
            }
            catch (std::logic_error& except) {
              throw;
            }
          }
        }
        catch (std::logic_error& except) {
          throw;
        }
      }
    }
    catch(std::logic_error& except) {
      not_found_images.insert(except.what());
    }
  }
  for (auto itr = not_found_images.begin(); itr != not_found_images.end(); ++itr) {
    std::cout << *itr << std::endl;
  }

  return 0;
}