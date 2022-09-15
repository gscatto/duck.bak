cmake_minimum_required(VERSION 3.14)

project(duck)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)

file(GLOB_RECURSE DUCK_MAIN_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
add_library(duck OBJECT ${DUCK_MAIN_SOURCES})

file(GLOB_RECURSE DUCK_TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test/*.c)
add_executable(test ${DUCK_TEST_SOURCES})
target_link_libraries(test duck)
