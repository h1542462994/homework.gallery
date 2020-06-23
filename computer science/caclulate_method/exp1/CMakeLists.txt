cmake_minimum_required(VERSION 3.15)
project(ProjCal)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjCal main.cpp point_d.cpp point_d.h div_iter.cpp div_iter.h tools.cpp tools.h simple_iter.cpp simple_iter.h pd.h)