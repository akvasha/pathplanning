cmake_minimum_required(VERSION 3.12)
project(pathplanning)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O2 -Wall -Wextra")
set(SOURCE_FILES
        main.cpp)

add_executable(pathplanning ${SOURCE_FILES})