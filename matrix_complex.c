#include "matrix.h"
#include <stdio.h>
#include <malloc.h>

struct Matrix* createMatrix_complex(int size)
{
    struct Matrix* mtrx = (struct Matrix*)malloc(sizeof(struct Matrix));
    mtrx->size = size;
    mtrx->matrix = malloc(size * size * sizeof(struct Complex));
    mtrx->elementSize = sizeof(struct Complex);
    mtrx->sum = add_complex;
    mtrx->multi = multiply_complex;
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

void multiplyMatrix_complex(struct Matrix* m1, struct Matrix* m2, struct Matrix* res){
    struct Complex *element = (struct Complex*)malloc(sizeof(struct Complex));
    for (int i = 0; i < m1->size; i++){
        for (int j = 0; j < m1->size; j++){
            element->x = 0;
            element->y = 0;
            for (int k = 0; k < m1->size; k++){
                element = add_complex(element, multiply_complex(((struct Complex*)m1->matrix + i * m1->size + k),
                        ((struct Complex*)m2->matrix + k * m1->size + j)));
                *((struct Complex*)res->matrix+i * res->size+j) = *element;
                }
            }
        }
    outputMatrix_complex(res);
}

void addMatrix_complex(struct Matrix* m1, struct Matrix* m2, struct Matrix* res){
    for (int i = 0; i < res->size * res->size; i++){
        *((struct Complex*)res->matrix + i) = *add_complex(((struct Complex*)m1->matrix + i), ((struct Complex*)m2->matrix + i));
    }
    outputMatrix_complex(res);
}

void multiplyMatrixOnScalar_complex(struct Matrix* m1, float scalar, struct Matrix* res){
    for (int i = 0; i < res->size * res->size; i++)    {
            *((struct Complex*)res->matrix + i) = *multiplyOnScalar_complex(((struct Complex*)m1->matrix + i), scalar);
    }
    outputMatrix_complex(res);
}

