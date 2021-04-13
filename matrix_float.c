#include "matrix.h"
#include <stdio.h>
#include<malloc.h>

struct Matrix* createMatrix_float(int size, int type){
    struct Matrix* mtrx = (struct Matrix*)malloc(sizeof(struct Matrix));
    mtrx->size = size;
    mtrx->type = type;
    mtrx->matrix = malloc(size * size * sizeof(float));
    for (int i = 0; i < size * size; i++)
        *(char*)((char*)mtrx->matrix + i) = 0;
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

void multiplyMatrix_float(struct Matrix* m1, struct Matrix* m2, struct Matrix* res){
    float element;
    for (int i = 0; i < m1->size; i++){
        for (int j = 0; j < m1->size; j++){
            element = 0;
            for (int k = 0; k < m1->size; k++) {
                element += *((float *) m1->matrix+i * m1->size+k) * (*((float *) m2->matrix+k * m2->size+j));
                *((float *) res->matrix+i * res->size+j) = element;

            }
        }
    }

    outputMatrix_float(res);
}

void addMatrix_float(struct Matrix* m1, struct Matrix* m2, struct Matrix* res){
    for (int i = 0; i < res->size * res->size; i++)
        *((float*)res->matrix + i) = *((float*)m1->matrix + i) + *((float*)m2->matrix + i);

    outputMatrix_float(res);
}

void multiplyMatrixOnScalar_float(struct Matrix* m1, float scalar, struct Matrix* res){
    for (int i = 0; i < res->size * res->size; i++)
        if (m1->type == 1)
            *((float*)res->matrix + i) = *((float*)m1->matrix + i) * scalar;

    outputMatrix_float(res);
}
