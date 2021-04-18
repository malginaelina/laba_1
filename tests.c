#include "tests.h"
#include "matrix.h"
#include <malloc.h>
#include <stdio.h>

struct Matrix *create_test(int size, int type)
{
    struct Matrix *test;

    if (type == 1)
    {
        test = createMatrix_float(size);
        for(int i = 0; i < size*size; i++)
        {
            *((float*)test->matrix+i) = i;
        }
    }
    else
    {
        test = createMatrix_complex(size);
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

    printf("Multiplication of Matrix:\n");
    res = multiply_matrix(m1, m2);
    outputMatrix_float(res);

    printf("Addition of Matrix:\n");
    res = add_matrix(m1, m2);
    outputMatrix_float(res);

    printf("Scalar: 3\n");
    printf("Multiplication of Matrix1 on scalar:\n");
    res = multiply_matrix_on_scalar(m1, 3.2);
    outputMatrix_float(res);

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

    printf("Multiplication of Matrix:\n");
    res = multiply_matrix(m1, m2);
    outputMatrix_complex(res);

    printf("Addition of Matrix:\n");
    res = add_matrix(m1, m2);
    outputMatrix_complex(res);

    printf("Scalar: 3\n");
    printf("Multiplication of Matrix1 on scalar:\n");
    res = multiply_matrix_on_scalar(m1, 3);
    outputMatrix_complex(res);

    free(m1);
    free(m2);
    free(res);
}