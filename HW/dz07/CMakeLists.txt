cmake_minimum_required(VERSION 3.15)
project(dz07)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dz07
        Vector.h
        main.cpp Vector_def.h)
