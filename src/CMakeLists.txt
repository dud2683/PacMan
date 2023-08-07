cmake_minimum_required(VERSION 3.1)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(ProjectName "PacMan")
project("${ProjectName}" VERSION 0.1 )
add_executable("${ProjectName}" main.cpp)


set_property(TARGET "${ProjectName}" PROPERTY CXX_STANDARD 20)

