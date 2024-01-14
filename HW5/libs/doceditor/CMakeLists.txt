cmake_minimum_required(VERSION 3.6)

project(doceditor LANGUAGES CXX)

add_library(${PROJECT_NAME}
    include/document.hpp
    include/doceditor.hpp
    src/doceditor.cpp
    src/document.cpp
    src/idocimporter.hpp
    src/svgimporter.hpp
    src/idocexporter.hpp
    src/svgexporter.hpp
    src/docimporterfabric.hpp
    src/docimporterfabric.cpp
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
)
