cmake_minimum_required(VERSION 3.15)
project(task2_extra)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(task2_extra
        Radio.cpp
        Radio.h
        Tel_book.h)
