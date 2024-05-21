cmake_minimum_required(VERSION 3.28)
project(skipList)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -g)

add_executable(skipList main.cpp
        skipList.h
        node.h
        random.h)
