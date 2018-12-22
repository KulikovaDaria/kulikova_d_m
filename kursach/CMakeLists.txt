cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(kursach)

find_package(OpenCV REQUIRED)

add_executable(kursach kursach.h kursach.cpp)

target_link_libraries(kursach ${OpenCV_LIBS})
