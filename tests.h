
#ifndef MAIN_C_TESTS_H
#define MAIN_C_TESTS_H

// структура для матрицы
struct Matrix
{
    void* matrix;
    int size;
    int type;
};

// структура для комплексных чисел
struct Complex
{
    float x;
    float y;
};

struct Matrix* create_test(int size, int type); // создание матрицы для тестов
void tests(); // тесты

#endif //MAIN_C_TESTS_H
