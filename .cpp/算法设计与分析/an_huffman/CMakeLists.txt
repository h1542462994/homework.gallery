cmake_minimum_required(VERSION 3.15)
project(an_huffman)

set(CMAKE_CXX_STANDARD 14)

add_executable(an_huffman main.cpp bnode.h HuffmanTree.cpp HuffmanTree.h calculable.h)