# cmake_minimum_required(VERSION <specify CMake version here>)
project(os1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pthread")

add_executable(os1 main.cpp)