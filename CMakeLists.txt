# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Project's name
project(yagbe VERSION 0.1)

# Set c++ standard to c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}"/src)

add_executable(yagbe ${PROJECT_SOURCE_DIR}/main.cpp ${PROJECT_SOURCE_DIR}/cpu.cpp)
