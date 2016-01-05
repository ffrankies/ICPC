cmake_minimum_required(VERSION 3.3)
project(hw07)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES icpc6555.cpp)
add_executable(hw07 ${SOURCE_FILES})