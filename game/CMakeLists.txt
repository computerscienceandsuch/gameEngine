cmake_minimum_required(VERSION 3.2)

project(coffeeGame LANGUAGES CXX)

add_executable(${PROJECT_NAME} source/main.cpp)

target_link_libraries(${PROJECT_NAME} coffeeGameEngine)
target_include_directories(${PROJECT_NAME} PRIVATE coffeeGameEngine)