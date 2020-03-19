cmake_minimum_required(VERSION 3.15)
project(dz3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(dz3
        main.cpp
        Stack.h
        StackArray.h
        StackList.h
        PolishNotation.cpp
        PolishNotation.h
        StackArray_def.h StackList_def.h main.cpp)
