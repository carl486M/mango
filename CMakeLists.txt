cmake_minimum_required(VERSION 3.30)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
project("mango")
find_package(OpenGL REQUIRED)
add_subdirectory(lib/GLFW)

add_library(${PROJECT_NAME} SHARED
    src/glad.c
    src/engine.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
)
target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL)

add_subdirectory(example)