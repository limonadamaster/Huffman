cmake_minimum_required(VERSION 3.27)
project(Huffman)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Huffman
        BinaryTree.cpp
        CBinaryTree.cpp
        Graph.cpp
        Graph.h
        Huffman.cpp
        Huffman.h
        ObjectInTree.cpp
        ObjectInTree.h)
