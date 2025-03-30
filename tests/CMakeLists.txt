cmake_minimum_required(VERSION 3.20)

add_custom_target(test
    ${CMAKE_CURRENT_LIST_DIR}/test.sh ${CMAKE_CURRENT_LIST_DIR}/studs.txt ${CMAKE_BINARY_DIR}/mod
)
