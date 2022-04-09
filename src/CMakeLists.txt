cmake_minimum_required(VERSION 3.1.0)

project(lib)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(lib freq.cpp)