cmake_minimum_required(VERSION 3.15)
project(dz04)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dz04
        main.cpp
        String.cpp
        String.h)
