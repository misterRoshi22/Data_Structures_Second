cmake_minimum_required(VERSION 3.24)
project(data_structures_practice)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(data_structures_practice
        QueueArray.h main.cpp BST.h)
