cmake_minimum_required(VERSION 3.17)
project(Clion_project C)

set(CMAKE_C_STANDARD 99)

add_executable(Clion_project main.c functions.c functions.h tests.c tests.h)
