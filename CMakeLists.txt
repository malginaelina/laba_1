cmake_minimum_required(VERSION 3.17)
project(Clion_project C)

set(CMAKE_C_STANDARD 11)

add_executable(Clion_project main.c tests.c tests.h matrix.h matrix_float.c matrix_complex.c complex_numbers.c complex_numbers.h matrix.c float_numbers.c float_numbers.h)