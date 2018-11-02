cmake_minimum_required(VERSION 3.3)
project(projecteuler)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic")
set(SRC ${CMAKE_CURRENT_LIST_DIR}/src)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)

add_subdirectory(src)
add_subdirectory(test)