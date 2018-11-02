cmake_minimum_required(VERSION 3.3)
project(projecteuler)

add_subdirectory(googletest)

set(TESTS
    projecteuler-test.cpp
    digits-test.cpp
    intlist-test.cpp
    fractions-test.cpp
    numbers-test.cpp
    primelist-test.cpp)

set(SOURCE_FILES
    ${SRC}/digits.c
    ${SRC}/intlist.c
    ${SRC}/fractions.c
    ${SRC}/errormessages.c
    ${SRC}/numbers.c
    ${SRC}/primelist.c)

add_executable(projecteuler-test ${TESTS} ${SOURCE_FILES})
target_link_libraries(projecteuler-test gtest m)