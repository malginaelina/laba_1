
#ifndef MAIN_C_FUNCTIONS_H
#define MAIN_C_FUNCTIONS_H

struct Matrix* create(int size, int type); // создание матрицы, заполненной нулями
struct Complex* inputcomplex(); // ввод комплексных чисел

void input(struct Matrix* m1); // ввод матрицы
void output(struct Matrix* m1); // вывод матрицы
void multiply(struct Matrix* m1, struct Matrix* m2, struct Matrix* res); // умножение матрицы на матрицу
void add(struct Matrix* m1, struct Matrix* m2, struct Matrix* res); // сложение матриц
void scalar_multiply(struct Matrix* m1, float scalar, struct Matrix* res); // умножение матрицы на скаляр

#endif //MAIN_C_FUNCTIONS_H
