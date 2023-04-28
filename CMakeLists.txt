cmake_minimum_required(VERSION 3.20)
project(3d-graphics-template)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDC_DEBUG")

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE BOOL "")

include_directories(ThirdParty/glfw/include)

add_subdirectory(ThirdParty/glfw)

include_directories(SharedLib/Source)

add_subdirectory(SharedLib)
add_subdirectory(Examples/01-HelloWorld)
add_subdirectory(Examples/02-Log)
add_subdirectory(Examples/03-CreatingWindow)
