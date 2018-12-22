#include <exception>
#include <iostream>
#include <opencv2/opencv.hpp>

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

int CountOfUniquePairs(const cv::FileNode& roads, const cv::FileNode& cars) {
  int n_cars = cars.size();
  int n_roads = 0;
  for (int i = 0; i < roads.size(); ++i) {
    n_roads += roads[i]["mask"].size();
  }
  return n_cars * n_roads;
}

void ChoosePlaceForCar(const cv::Mat& mask) {

}

std::pair<int, int> MeasureHeightOfMask(const cv::Mat mask) {
  std::pair<int, int> height(std::make_pair(-1, -1));
  for (int i = 0; i < mask.rows; ++i) {
    for (int j = 0; j < mask.cols; ++j) {
      if (mask.at<cv::Vec3b>(i, j)[0] == 255
        && mask.at<cv::Vec3b>(i, j)[1] == 255
        && mask.at<cv::Vec3b>(i, j)[2] == 255) {
        height.second = i;
        if (height.first == -1) {
          height.first = i;
        }
      }
    }
  }
  return height;
}

int RandomHeight(const std::pair<int, int> height) {
  return (height.first + rand() % (height.second - height.first));
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
  catch (const std::logic_error& except) {
    std::cout << except.what() << std::endl;
    return 0;
  }

  
  int n_unique_pair = CountOfUniquePairs(roads, cars);
  int n_image_for_pair = n_image / n_unique_pair + 1;
  int n_pair_for_one_more = n_image % n_unique_pair;
  int n_image_cur = 0;

  for (int i_road = 0; i_road < roads.size() && n_image_cur < n_image; ++i_road) {
    cv::Mat road = cv::imread(roads[i_road]["image"]);
    for (int i_mask = 0; i_mask < roads[i_road]["mask"].size() && n_image_cur < n_image; ++i_mask) {
      cv::Mat road_mask = cv::imread(roads[i_road]["mask"][i_mask]);
      for (int i_car = 0; i_car < cars.size() && n_image_cur < n_image; ++i_car) {
        cv::Mat car = cv::imread(cars[i_car]["image"]);
        cv::Mat car_mask = cv::imread(cars[i_car]["mask"]);
        ChoosePlaceForCar(road_mask);
      }
    }
  }

  return 0;
}