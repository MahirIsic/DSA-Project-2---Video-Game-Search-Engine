cmake_minimum_required(VERSION 4.3)
project(DSAProject2)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSAProject2 main.cpp
        Heap.h Heap.cpp gameNode.cpp gameNode.h driver.h driver.cpp mergeSort.h mergeSort.cpp)
