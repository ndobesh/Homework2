# cmake_minimum_required(VERSION <specify CMake version here>)
project(Homework2 C)

set(CMAKE_C_STANDARD 99)

add_library(Homework2 library.c library.h Threads.c)