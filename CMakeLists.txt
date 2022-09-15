cmake_minimum_required(VERSION 3.14)

project(gsobj)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)

file(GLOB_RECURSE GSOBJ_MAIN_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
add_library(gsobj OBJECT ${GSOBJ_MAIN_SOURCES})

file(GLOB_RECURSE GSOBJ_TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test/*.c)
add_executable(test ${GSOBJ_TEST_SOURCES})
target_link_libraries(test gsobj)
