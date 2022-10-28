cmake_minimum_required(VERSION 3.10)
project(my_algorithms)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -lrt")

add_executable(main main.cpp my_algorithms.cpp)