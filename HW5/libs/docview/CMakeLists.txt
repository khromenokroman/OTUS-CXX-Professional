cmake_minimum_required(VERSION 3.6)

project(docview LANGUAGES CXX)

add_library(${PROJECT_NAME}
    include/docview.hpp
    src/docview.cpp
)

# if (${BUILD_TESTING})
#     add_subdirectory(tests)
# endif()

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
    custom-patterns
    graphprim
PRIVATE
    doceditor
)
