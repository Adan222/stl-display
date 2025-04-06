cmake_minimum_required(VERSION 3.10)

project(stl_display)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

configure_file(${CMAKE_SOURCE_DIR}/src/config.hpp.in ${CMAKE_SOURCE_DIR}/src/config.hpp)

add_subdirectory(deps/glad)
add_subdirectory(deps/stb)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Find all .cpp files in src/ and store them in SRC_FILES
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp src/*.h)

add_executable(stl_display ${SRC_FILES})

target_include_directories(stl_display PRIVATE src/)

target_link_libraries(stl_display PRIVATE OpenGL::GL)
target_link_libraries(stl_display PRIVATE glfw)
target_link_libraries(stl_display PRIVATE glad)
target_link_libraries(stl_display PRIVATE stb)


