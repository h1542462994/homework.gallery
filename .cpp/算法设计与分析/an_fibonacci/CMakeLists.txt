cmake_minimum_required(VERSION 3.15)
project(an_fibonacci)

set(CMAKE_CXX_STANDARD 14)

add_executable(an_fibonacci main.cpp fibonacci.h ubigint.h)