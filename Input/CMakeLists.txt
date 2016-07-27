cmake_minimum_required(VERSION 3.3)

project (OnePunchGame)
set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
add_library(InputLibrary SHARED InputManager.cpp)