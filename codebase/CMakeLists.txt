cmake_minimum_required(VERSION 3.21)
project(codebase_wrapper LANGUAGES CXX)

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

include_directories(${CMAKE_SOURCE_DIR})
set(SOURCES codebase_wrapper.i codebase.cpp)

set_property(SOURCE codebase_wrapper.i PROPERTY CPLUSPLUS ON)

swig_add_library(${PROJECT_NAME}
 TYPE SHARED
 LANGUAGE csharp
 OUTPUT_DIR "${CMAKE_SOURCE_DIR}/../codebase-dotnet/Generated"
 OUTFILE_DIR "${CMAKE_CURRENT_BINARY_DIR}/Wrapper"
 SOURCES ${SOURCES}
)

add_custom_target(CleanGenerated ALL
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_SOURCE_DIR}/../codebase-dotnet/Generated"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_SOURCE_DIR}/../codebase-dotnet/Generated"
    COMMAND ${CMAKE_COMMAND} -E remove -f "${CMAKE_SOURCE_DIR}/../codebase-dotnet/${PROJECT_NAME}.dll"
)
add_dependencies(${PROJECT_NAME} CleanGenerated)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:${PROJECT_NAME}>
    "${CMAKE_SOURCE_DIR}/../codebase-dotnet/"
)