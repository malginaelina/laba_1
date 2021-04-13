#ifndef MAIN_C_MATRIX_H
#define MAIN_C_MATRIX_H

// структура для матрицы
struct Matrix
{
    void* matrix;
    int size;
    int type;
};

// матрицы вещественных чисел
struct Matrix* createMatrix_float(int size, int type);
void inputMatrix_float(struct Matrix *m1); // ввод матрицы
void outputMatrix_float(struct Matrix *m1); // вывод матрицы
void multiplyMatrix_float(struct Matrix *m1, struct Matrix *m2, struct Matrix *res); // умножение матрицы на матрицу
void addMatrix_float(struct Matrix* m1, struct Matrix* m2, struct Matrix* res); // сложение матриц
void multiplyMatrixOnScalar_float(struct Matrix *m1, float scalar, struct Matrix *res); // умножение матрицы на скаляр

// матрицы комплексных чисел
struct Matrix* createMatrix_complex(int size, int type);
void inputMatrix_complex(struct Matrix *m1); // ввод матрицы
void outputMatrix_complex(struct Matrix *m1); // вывод матрицы
void multiplyMatrix_complex(struct Matrix *m1, struct Matrix *m2, struct Matrix *res); // умножение матрицы на матрицу
void addMatrix_complex(struct Matrix* m1, struct Matrix* m2, struct Matrix* res); // сложение матриц
void multiplyMatrixOnScalar_complex(struct Matrix *m1, float scalar, struct Matrix *res); // умножение матрицы на скаляр

#endif //MAIN_C_MATRIX_H
