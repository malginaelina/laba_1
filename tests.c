#include "tests.h"
#include "matrix.h"
#include<malloc.h>
#include<stdio.h>
#include "complex_numbers.h"

struct Matrix *create_test(int size, int type)
{
    struct Matrix *test;

    test = createMatrix_float(size, type);
    if (type == 1)
    {
        for(int i = 0; i < size*size; i++)
        {
            *((float*)test->matrix+i) = i;
        }
    }
    else
    {
        for(int i = 0; i < size*size; i++)
        {
            ((struct Complex*)test->matrix + i)->x = i;
            ((struct Complex*)test->matrix + i)->y = i;
        }
    }
    return test;
}

void tests() {
    struct Matrix *m1, *m2, *res;
    int size = 2;
    int type_1 = 1, type_2 = 2;
    printf("Tests for float numbers\n");
    printf("Matrix1:\n");
    m1 = create_test(size, type_1);
    outputMatrix_float(m1);

    printf("Matrix2:\n");
    m2 = create_test(size, type_1);
    outputMatrix_float(m2);

    res = createMatrix_float(size, type_1);

    printf("Multiplication of Matrix:\n");
    multiplyMatrix_float(m1, m2, res);

    printf("Addition of Matrix:\n");
    addMatrix_float(m1, m2, res);

    printf("Scalar: 3\n");
    printf("Multiplication of Matrix1 on scalar:\n");
    multiplyMatrixOnScalar_float(m1, 3, res);

    free(m1);
    free(m2);
    free(res);

    printf("Tests for complex numbers\n");
    printf("Matrix1:\n");
    m1 = create_test(size, type_2);
    outputMatrix_complex(m1);

    printf("Matrix2:\n");
    m2 = create_test(size, type_2);
    outputMatrix_complex(m2);

    res = createMatrix_complex(size, type_2);

    printf("Multiplication of Matrix:\n");
    multiplyMatrix_complex(m1, m2, res);

    printf("Addition of Matrix:\n");
    addMatrix_complex(m1, m2, res);

    printf("Scalar: 3\n");
    printf("Multiplication of Matrix1 on scalar:\n");
    multiplyMatrixOnScalar_complex(m1, 3, res);

    free(m1);
    free(m2);
    free(res);
}