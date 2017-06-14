cmake_minimum_required(VERSION 3.6)
project(cinAliDetection)

set(OpenCV_FOUND 1)
find_package(OpenCV REQUIRED)
set(SOURCE_FILES main.cpp Frame.cpp Frame.h)
add_executable(cinAliDetection ${SOURCE_FILES})


set(CMAKE_CXX_STANDARD 11)


include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries( cinAliDetection ${OpenCV_LIBS} )