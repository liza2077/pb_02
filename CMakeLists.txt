cmake_minimum_required(VERSION 3.22)

project(ch05 LANGUAGES CXX)

add_executable(mod
    mod.cpp
    Grade.cpp
    Median.cpp
    Student_info.cpp
)

add_subdirectory(tests)
