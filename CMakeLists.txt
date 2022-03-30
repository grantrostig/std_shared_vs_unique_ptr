cmake_minimum_required(VERSION 3.5)

project(std_shared_vs_unique_ptr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options( -Wall -Wextra -pedantic -pedantic-errors -Wno-unused-variable )

add_executable(std_shared_vs_unique_ptr main.cpp)
