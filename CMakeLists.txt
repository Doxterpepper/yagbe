# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.9)

# Project's name
project(yagbe VERSION 0.1)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${yagbe_SOURCE_DIR}/cmake")
include(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

# Set c++ standard to c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

#find_package(SDL2 REQUIRED)
#include_directories(${SDL2_INCLUDE_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}/src" ${SDL2_INCLUDE_DIRS})
#include_directories(${SDL2_INCLUDE_DIRS})

#target_link_libraries(yagbe ${SDL2_LIBRARY})
add_executable(yagbe ${PROJECT_SOURCE_DIR}/main.cpp
  ${PROJECT_SOURCE_DIR}/cpu.cpp
  ${PROJECT_SOURCE_DIR}/gameboy.cpp)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})


set(UNIT_TEST_DIR ${CMAKE_SOURCE_DIR}/tests)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE  ${UNIT_TEST_DIR} ${PROJECT_SOURCE_DIR})
add_executable(my_test ${UNIT_TEST_DIR}/test.cpp
  ${PROJECT_SOURCE_DIR}/cpu.cpp)
target_link_libraries(my_test Catch)
enable_testing()
add_test(NAME YagbeUnitTest COMMAND my_test)
