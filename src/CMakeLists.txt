cmake_minimum_required(VERSION 3.1)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)

set(ProjectName "PacMan")
project("${ProjectName}" VERSION 0.1 )


add_executable("${ProjectName}" main.cpp)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${ProjectName})

set_property(TARGET "${ProjectName}" PROPERTY CXX_STANDARD 20)

