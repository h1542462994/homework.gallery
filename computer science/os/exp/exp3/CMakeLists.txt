cmake_minimum_required(VERSION 3.10)
project(os2)

set(CMAKE_CXX_STANDARD 14)

add_executable(os2 main.cpp re_state.h simple_io.h)