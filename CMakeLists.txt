cmake_minimum_required(VERSION 3.0)

project(project VERSION 0.1.0 LANGUAGES C)
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.c")
add_executable(main ${SOURCES})
