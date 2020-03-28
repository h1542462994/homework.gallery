cmake_minimum_required(VERSION 3.15)
project(an_bigint_h)

set(CMAKE_CXX_STANDARD 14)

add_executable(an_bigint_h main.cpp big_int.cpp big_int.h)