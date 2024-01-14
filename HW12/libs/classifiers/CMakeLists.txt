cmake_minimum_required(VERSION 3.6)

project(fashionclassifiers  LANGUAGES CXX)

add_library(${PROJECT_NAME}
    include/ibinaryclassifier.hpp
    include/logregclassifier.hpp
    src/logregclassifier.cpp
    include/utils.hpp
    src/utils.cpp
)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
