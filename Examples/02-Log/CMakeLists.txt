cmake_minimum_required(VERSION 3.20)

project(02-Log)

file(GLOB_RECURSE SOURCES "Source/*.h" "Source/*.cpp")

add_executable(02-Log ${SOURCES})

target_link_libraries(02-Log PUBLIC SharedLib)