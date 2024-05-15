cmake_minimum_required(VERSION 3.5)

project(onegin)

include_directories(
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/common/logging
    ${CMAKE_CURRENT_SOURCE_DIR}/common/file_reading/src
)

add_definitions(-DDEBUG)

add_subdirectory(src)
add_subdirectory(common/file_reading ${CMAKE_CURRENT_BINARY_DIR}/file_reading)
