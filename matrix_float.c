#include "matrix.h"

struct Matrix* createMatrix_float(int size){
    struct Matrix* mtrx = (struct Matrix*)malloc(sizeof(struct Matrix));
    mtrx->size = size;
    mtrx->elementSize = sizeof(float);
    mtrx->matrix = malloc(size * size * sizeof(float));
    mtrx->multi = multiply_float;
    mtrx->sum = add_float;
    mtrx->multi_scalar = multiply_on_scalar_float;
    for (int i = 0; i < size * size; i++)
        *((char*)mtrx->matrix + i) = 0;
    return mtrx;
}

void inputMatrix_float(struct Matrix* m1){
    for (int i = 0; i < m1->size * m1->size; i++)
        scanf_s("%f", ((float*)m1->matrix + i));
}

void outputMatrix_float(struct Matrix* m1){
    for (int i = 0; i < m1->size * m1->size; i++)    {
        printf("%0.2f ", *((float*)m1->matrix + i));
        if ((i + 1) % m1->size == 0)
            printf("\n");
    }
    printf("\n");
}