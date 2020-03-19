cmake_minimum_required(VERSION 3.15)
project(dz05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dz05
        main.cpp
        Row.h
        Row_def.h
        Matrix.h
        Matrix_def.h
        SquareMatrix.h
        SquareMatrix_def.h)
