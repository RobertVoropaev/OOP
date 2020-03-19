cmake_minimum_required(VERSION 3.15)
project(task1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(task1
        BigInteger/BigInteger.h
        BigInteger/BigInteger.cpp
        Matrix/Row.h
        Matrix/Row_def.h
        Matrix/Matrix.h
        Matrix/Matrix_def.h
        Matrix/SquareMatrix.h
        Matrix/SquareMatrix_def.h
        Geometry/Geometry.h
        Geometry/Geometry.cpp
        main.cpp)
