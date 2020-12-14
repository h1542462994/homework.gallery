cmake_minimum_required(VERSION 3.17)
project(re2dfa)

set(CMAKE_CXX_STANDARD 14)

add_executable(re2dfa main.cpp RegularExpression.h ReUnit.h UnitType.h NfaBuilder.h Edge.h DfaBuilder.h SortedSet.h Set.h ReMatcher.h)