cmake_minimum_required(VERSION 3.14)
project(TopologyAPI)

set(CMAKE_BUILD_TYPE Release)

file(GLOB SOURCES "*.cpp")
add_library(TopologyAPI STATIC ${SOURCES})
target_include_directories(TopologyAPI PRIVATE include)
