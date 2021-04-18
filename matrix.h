#ifndef MAIN_C_MATRIX_H
#define MAIN_C_MATRIX_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "complex_numbers.h"

// структура для матрицы
struct Matrix
{
    void* matrix;
    int size;
    int elementSize;
    void *(*sum) (void *m1, void *m2);
    void *(*multi) (void *m1, void *m2);
    void *(*multi_scalar) (void *m1, float scalar);
};

struct Matrix * add_matrix(struct Matrix *m1, struct Matrix *m2);
struct Matrix * multiply_matrix(const struct Matrix *m1, const struct Matrix *m2);
struct Matrix * multiply_matrix_on_scalar(const struct Matrix *m1, float scalar);
float *add_float(const float *a, const float *b);
float *multiply_float(const float *a, const float *b);
float *multiply_on_scalar_float(const float *a, float scalar);

// матрицы вещественных чисел
struct Matrix* createMatrix_float(int size);
void inputMatrix_float(struct Matrix *m1); // ввод матрицы
void outputMatrix_float(struct Matrix *m1); // вывод матрицы
void multiplyMatrix_float(struct Matrix *m1, struct Matrix *m2, struct Matrix *res); // умножение матрицы на матрицу
void addMatrix_float(struct Matrix *m1, struct Matrix *m2, struct Matrix *res); // сложение матриц
void multiplyMatrixOnScalar_float(struct Matrix *m1, float scalar, struct Matrix *res); // умножение матрицы на скаляр

// матрицы комплексных чисел
struct Matrix* createMatrix_complex(int size);
void inputMatrix_complex(struct Matrix *m1); // ввод матрицы
void outputMatrix_complex(struct Matrix *m1); // вывод матрицы
void multiplyMatrix_complex(struct Matrix *m1, struct Matrix *m2, struct Matrix *res); // умножение матрицы на матрицу
void addMatrix_complex(struct Matrix* m1, struct Matrix* m2, struct Matrix* res); // сложение матриц
void multiplyMatrixOnScalar_complex(struct Matrix *m1, float scalar, struct Matrix *res); // умножение матрицы на скаляр


#endif //MAIN_C_MATRIX_H
