
cmake_minimum_required(VERSION 3.5)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

file(GLOB ${PROJECT_NAME}_SRC
    "*.h"
    "*.cpp"
)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRC} CTriangleTypeChecker.cpp CTriangleTypeChecker.h)


