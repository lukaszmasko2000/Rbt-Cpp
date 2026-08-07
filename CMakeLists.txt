cmake_minimum_required(VERSION 4.3)
project(red_black_tree)

set(CMAKE_CXX_STANDARD 26)

add_executable(red_black_tree main.cpp
        rbTree.cpp
        rbTree.h)
