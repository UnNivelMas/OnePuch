cmake_minimum_required(VERSION 3.3)

project (OnePunchGame)
set(CMAKE_BUILD_TYPE Release)

find_package(OpenGL)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ ${SDL2_INCLUDE}/)
add_library(RenderLibrary SHARED RenderManager.cpp)