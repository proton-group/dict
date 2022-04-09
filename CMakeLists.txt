cmake_minimum_required(VERSION 3.1.0)

project(fqdict)

add_subdirectory(src)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(fqdict main.cpp)
target_link_libraries(fqdict lib)