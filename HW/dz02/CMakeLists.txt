cmake_minimum_required(VERSION 3.15)
project(dz2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dz2
        Circle.cpp
        Circle.h
        main.cpp
        Point.cpp
        Point.h
        Square.cpp
        Square.h
        Field.h Field.cpp)
