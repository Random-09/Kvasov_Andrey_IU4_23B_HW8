cmake_minimum_required(VERSION 3.24)
project(task1 C)

set(CMAKE_C_STANDARD 11)

add_executable(task1 main.c src/search_tree.c include/search_tree.h)
