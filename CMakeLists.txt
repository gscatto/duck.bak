cmake_minimum_required(VERSION 3.14)

project(duck)

include_directories(inc)

file(GLOB_RECURSE DUCK_MAIN_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
add_library(duck OBJECT ${DUCK_MAIN_SOURCES})

file(GLOB_RECURSE DUCK_TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test/*.c)
add_executable(duck_test ${DUCK_TEST_SOURCES})
target_link_libraries(duck_test duck)
