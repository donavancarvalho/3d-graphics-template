cmake_minimum_required(VERSION 3.20)

project(01-HelloWorld)

file(GLOB_RECURSE SOURCES "Source/*.h" "Source/*.cpp")

add_executable(01-HelloWorld ${SOURCES})