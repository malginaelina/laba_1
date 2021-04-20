#include "matrix.h"

struct Matrix* createMatrix_complex(int size)
{
    struct Matrix* mtrx = (struct Matrix*)malloc(sizeof(struct Matrix));
    mtrx->size = size;
    mtrx->matrix = malloc(size * size * sizeof(struct Complex));
    mtrx->elementSize = sizeof(struct Complex);
    mtrx->sum = add_complex;
    mtrx->multi = multiply_complex;
    mtrx->multi_scalar = multiply_on_scalar_complex;
    for (int i = 0; i < size * size; i++)
        *((char*)mtrx->matrix + i) = 0;
    return mtrx;
}

void inputMatrix_complex(struct Matrix* m1){
    for (int i = 0; i < m1->size * m1->size; i++)
        *((struct Complex*)m1->matrix + i) = *input_complex();
}

void outputMatrix_complex(struct Matrix* m1){
    for (int i = 0; i < m1->size * m1->size; i++){
        output_complex((struct Complex*)m1->matrix + i);
        if ((i + 1) % m1->size == 0)
            printf("\n");
    }
    printf("\n");
}