cmake_minimum_required(VERSION 3.20)
project(3d-graphics-template)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(Examples/01-HelloWorld)
