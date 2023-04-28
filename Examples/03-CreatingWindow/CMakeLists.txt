cmake_minimum_required(VERSION 3.20)

project(03-CreatingWindow)

file(GLOB_RECURSE SOURCES 
    "Source/*.h" 
    "Source/*.cpp")

add_executable(03-CreatingWindow ${SOURCES})

target_link_libraries(03-CreatingWindow PUBLIC SharedLib)