cmake_minimum_required(VERSION 3.15)
project(dz11)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dz11
        main.cpp
        Task.h Tasks.h)
