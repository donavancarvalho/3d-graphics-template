cmake_minimum_required(VERSION 3.20)

project(SharedLib)

file(GLOB_RECURSE SOURCES "Source/*.h" "Source/*.cpp")

add_library(SharedLib ${SOURCES})

target_link_libraries(SharedLib PUBLIC glfw)