cmake_minimum_required(VERSION 3.5)

project(onegin)

add_definitions(-DDEBUG)
add_subdirectory(src)
add_subdirectory(../common/file_reading ${CMAKE_CURRENT_BINARY_DIR}/file_reading)