cmake_minimum_required(VERSION 3.5)

project(oneg)

set(SOURCES
    main.cpp
    qsort.cpp
    string_reader.cpp
    string_work.cpp
    swap.cpp
    w_file_read.cpp
)

set(HEADERS
    string_reader.h
    qsort.h
    string_work.h
    swap.h
    w_file_read.h
)

add_executable(oneg ${SOURCES})

target_include_directories(
    oneg
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(
    oneg
    PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}
)

include_directories(
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../common/logging
    ${CMAKE_CURRENT_SOURCE_DIR}/../../common/file_reading/src
)

target_link_libraries(oneg file_reading)