cmake_minimum_required(VERSION 3.15)

add_library(file_reading file_reading.cpp)

target_include_directories(
    file_reading
    PRIVATE
    ${CMAKE_SOURCE_DIR}/logging
)

target_link_libraries(file_reading logging)
