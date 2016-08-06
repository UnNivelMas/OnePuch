cmake_minimum_required(VERSION 3.3)

project (OnePunchGame)
set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ ${SDL2_INCLUDE}/ ${SDL2_IMAGE_INCLUDE_DIR}/ ${SDL2_INCLUDE_DIR}/ ${SDL2_IMAGE_INCLUDE_DIR}/)
link_directories(${SDL2_LIB}/ ${SDL2_IMAGE_LIBRARIES}/)

add_library(InputLibrary SHARED InputManager.cpp)