cmake_minimum_required(VERSION 3.10)

project(Triangle)

find_package(glfw3 REQUIRED)

add_executable(
    triangle
    src/main.cpp
    src/Shader.cpp
    external/gl.c
)

target_include_directories(
    triangle PRIVATE
    external/include
)

target_link_libraries(
    triangle
    glfw
    GL
)
