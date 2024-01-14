cmake_minimum_required(VERSION 3.6)

project(custom-patterns  LANGUAGES CXX)

add_library(${PROJECT_NAME}
INTERFACE
    include/behavioral/observer.hpp
    include/behavioral/observable.hpp
)

# if (${BUILD_TESTING})
#     add_subdirectory(tests)
# endif()

target_include_directories(${PROJECT_NAME}
INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
