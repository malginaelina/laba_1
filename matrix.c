#include "matrix.h"

struct Matrix *add_matrix(struct Matrix *m1, struct Matrix *m2){
    struct Matrix *res = (struct Matrix*)malloc(sizeof(struct Matrix));
    res->matrix = malloc(m1->size * m1->size * m1->elementSize);
    res->size = m1->size;
    res->elementSize = m1->elementSize;
    res->multi = m1->multi;
    res->sum = m1->sum;
    res->multi_scalar = m1->multi_scalar;
    for (int i = 0; i < res->size * res->size; i++){
        memcpy((char*)res->matrix + i * res->elementSize,
               (char*)res->sum((char*)m1->matrix + i * m1->elementSize, (char*)m2->matrix + i * m2->elementSize),
               res->elementSize);
    }
    return res;
}

struct Matrix *multiply_matrix(const struct Matrix *m1, const struct Matrix *m2){
    struct Matrix *res = (struct Matrix*)malloc(sizeof(struct Matrix));
    res->matrix = malloc(m1->size * m1->size * m1->elementSize);
    res->size = m1->size;
    res->elementSize = m1->elementSize;
    res->multi = m1->multi;
    res->sum = m1->sum;
    res->multi_scalar = m1->multi_scalar;

    for (int i = 0; i < m1->size; i++){
        for (int j = 0; j < m1->size; j++){
            void *element = calloc(1, m1->elementSize);

            for (int k = 0; k < m1->size; k++) {
                element = (char*)res->sum(element, (char*)res->multi((char*)m1->matrix + i * m1->elementSize * m1->size +
                k * m1->elementSize, (char*)m2->matrix + k * m2->elementSize * m2->size + j * m2->elementSize));
                memcpy((char*)res->matrix + i * res->elementSize * res->size + j * res->elementSize, element, res->elementSize);
            }

        }
    }
    return res;
}

struct Matrix *multiply_matrix_on_scalar(const struct Matrix *m1, float scalar){
    struct Matrix *res = (struct Matrix*)malloc(sizeof(struct Matrix));
    res->matrix = malloc(m1->size * m1->size * m1->elementSize);
    res->size = m1->size;
    res->elementSize = m1->elementSize;
    res->multi = m1->multi;
    res->sum = m1->sum;
    res->multi_scalar = m1->multi_scalar;
    for (int i = 0; i < res->size * res->size; i++){
        memcpy((char*)res->matrix + i * res->elementSize,
               (char*)res->multi_scalar((char*)m1->matrix + i * m1->elementSize, scalar),
               res->elementSize);
    }
    return res;
}

