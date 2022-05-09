cmake_minimum_required(VERSION 3.14)
project(TopologyAPI)

set(CMAKE_BUILD_TYPE Release)

include_directories(include)

file(GLOB SOURCES "*.cpp")
add_library(TopologyAPI STATIC ${SOURCES})
