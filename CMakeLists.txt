cmake_minimum_required(VERSION 3.17)
project(Clion_project C)

set(CMAKE_C_STANDARD 99)

add_executable(Clion_project main.c cmake-build-debug/functions.c cmake-build-debug/functions.h cmake-build-debug/tests.c cmake-build-debug/tests.h)