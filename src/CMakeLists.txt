cmake_minimum_required(VERSION 3.5)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_executable(onegin ${SOURCES} ${HEADERS})

target_include_directories(
    onegin
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/logging
    ${CMAKE_SOURCE_DIR}/file_reading
)

target_link_libraries(onegin file_reading logging)
