cmake_minimum_required(VERSION 3.28)
project(biList)

set(CMAKE_CXX_STANDARD 20)

add_executable(biList main.cpp
        node.h
        list.h)
