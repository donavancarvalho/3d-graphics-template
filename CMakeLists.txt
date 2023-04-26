cmake_minimum_required(VERSION 3.20)
project(3d-graphics-template)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDC_DEBUG")

include_directories(SharedLib/Source)

add_subdirectory(SharedLib)
add_subdirectory(Examples/01-HelloWorld)
add_subdirectory(Examples/02-Log)
