cmake_minimum_required(VERSION 3.22)

project(ch06 LANGUAGES CXX)

add_executable(ch06
    main.cpp
    median.cpp
    grade.cpp
    student_info.cpp
    locale_string.cpp
)

set_target_properties(ch06 PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
)


add_subdirectory(tests)
