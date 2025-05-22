cmake_minimum_required(VERSION 3.30)
project(example)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} mango)