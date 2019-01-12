#include <exception>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <set>
#include <sstream>
#include <string>

void ReadFromJson(const cv::FileStorage& dataset, cv::FileNode& roads,
    cv::FileNode& cars) {
  roads = dataset["roads"];
  cars = dataset["cars"];
  if (0 == roads.size() && 0 == cars.size()) {
    throw std::logic_error("Json is empty or hasn't been found.");
  }
  if (0 == roads.size()) {
    throw std::logic_error("Json of roads is empty.");
  }
  if (0 == cars.size()) {
    throw std::logic_error("Json of cars is empty.");
  }
}



cv::Mat ReadImage(const std::string name) {
  cv::Mat image = cv::imread(name);
  if (image.empty()) {
    throw std::logic_error("The image hasn't been found or the file has" 
      " an incorrect format: " + name + '.');
  }
  return image;
}



void CheckMask(const cv::Mat& image, const cv::Mat mask,
    const std::string path_to_image, const std::string path_to_mask) {
  if (image.size() != mask.size()) {
    throw std::logic_error("The mask " + path_to_mask + " does not match the image "
        + path_to_mask + '.');
  }
}



bool IsWhite(const cv::Mat mask, const int i, const int j) {
  return (255 == mask.at<cv::Vec3b>(i, j)[0]
       && 255 == mask.at<cv::Vec3b>(i, j)[1]
       && 255 == mask.at<cv::Vec3b>(i, j)[2]);
}



// Returns first and last rows with white pixel
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



// Returns a random number in the specified range
int RandomNumber(const std::pair<int, int> range) {
  return (range.first + rand() % (range.second - range.first));
}



// Returns first and last columns with white pixel
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
  return width;
}



// Returns first and last columns with white pixel in the specified row
std::pair<int, int> WidthOfMask(const cv::Mat mask, const int row) {
  std::pair<int, int> width = std::make_pair(-1, -1);
  for (int j = 0; j < mask.cols; ++j) {
    if (IsWhite(mask, row, j)) {
      width.second = j;
      if (-1 == width.first) {
        width.first = j;
      }
    }
  }
  return width;
}



// Glues the car on the road
void AlphaBlending(cv::Mat car, cv::Mat car_mask, cv::Mat road,
    cv::Mat road_mask, const int i_out_image) {
  // Find a place for the car
  std::pair<int, int> height_of_road = HeightOfMask(road_mask);
  int random_height = RandomNumber(height_of_road);
  // Adjust size of the car to the width of the road
  std::pair<int, int> width_of_road = WidthOfMask(road_mask, random_height);
  std::pair<int, int> width_of_car = WidthOfMask(car_mask);
  double coeff = (width_of_car.second - width_of_car.first) * 100.0
      / ((width_of_road.second - width_of_road.first)
      * RandomNumber(std::make_pair(40, 50)));
  cv::Size new_size(car.cols / coeff + 0.5, car.rows / coeff + 0.5);
  resize(car, car, new_size);
  resize(car_mask, car_mask, new_size);
  // Convert Mat to float data type
  car.convertTo(car, CV_32FC3);
  road.convertTo(road, CV_32FC3);
  // Normalize the alpha mask to keep intensity between 0 and 1
  car_mask.convertTo(car_mask, CV_32FC3, 1.0 / 255);
  multiply(car_mask, car, car);
  // Choose a place for the car and glues the car on the road
  std::pair<int, int> coordinates_of_car = std::make_pair(random_height
      - car.rows, (width_of_road.first + width_of_road.second - car.cols) / 2);
  cv::Rect rect_of_car(coordinates_of_car.second, coordinates_of_car.first,
      car.cols, car.rows);
  cv::Mat roi_of_car = road(rect_of_car);
  multiply(cv::Scalar::all(1.0) - car_mask, roi_of_car, roi_of_car);
  add(car, roi_of_car, roi_of_car);
  cv::Mat out_image = road;
  roi_of_car.copyTo(out_image(rect_of_car));
  // Save image
  std::string path = "result/";
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
  catch(const std::logic_error& exception) {
    std::cout << exception.what() << std::endl;
    return 0;
  }

  int n_image_cur = 0;
  std::set<std::string> not_found_images;
  for (int i_car = 0; n_image_cur < n_image; i_car = ++i_car % cars.size()) {
    try {
      std::string path_to_car = cars[i_car]["image"];
      std::string path_to_car_mask = cars[i_car]["mask"];
      cv::Mat car = ReadImage(path_to_car);
      cv::Mat car_mask = ReadImage(path_to_car_mask);
      CheckMask(car, car_mask, path_to_car, path_to_car_mask);
      for (int i_road = 0; i_road < roads.size() && n_image_cur < n_image; ++i_road) {
        try {
          std::string path_to_road = roads[i_road]["image"];
          cv::Mat road = ReadImage(path_to_road);
          for (int i_mask = 0; i_mask < roads[i_road]["mask"].size()
              && n_image_cur < n_image; ++i_mask) {
            try {
              std::string path_to_road_mask = roads[i_road]["mask"][i_mask];
              cv::Mat road_mask = ReadImage(path_to_road_mask);
              CheckMask(road, road_mask, path_to_road, path_to_road_mask);
              AlphaBlending(car, car_mask, road, road_mask, n_image_cur);
              ++n_image_cur;
            }
            catch(std::logic_error& except) {
              not_found_images.insert(except.what());
            }
          }
        }
        catch(std::logic_error& except) {
          not_found_images.insert(except.what());
        }
      }
    }
    catch(std::logic_error& except) {
      not_found_images.insert(except.what());
    }
  }
  for (auto itr = not_found_images.begin(); itr != not_found_images.end();
      ++itr) {
    std::cout << *itr << std::endl;
  }
  return 0;
}
