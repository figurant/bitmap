cmake_minimum_required(VERSION 3.20)
project(bitmap)

set(CMAKE_CXX_STANDARD 11)

add_executable(bitmap main.cpp source/BitMap.cpp source/BitMap.h)

#为项目引入测试功能
add_subdirectory(test)