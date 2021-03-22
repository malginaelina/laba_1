#include "tests.h"
#include "functions.h"
#include<malloc.h>
#include<stdio.h>


struct Matrix *create_test(int size, int type)
{
    struct Matrix *res;

    res=create(size, type);
    if(type==1)
    {
        for(int i=0;i<size*size;i++)
        {
            *((float*)res->matrix+i)=i;
        }
    }
    else if(type==2)
    {
        for(int i=0;i<size*size;i++)
        {
            ((struct Complex*)res->matrix + i)->x = i;
            ((struct Complex*)res->matrix + i)->y = i;
        }
    }

    return res;

}

void tests() {
    struct Matrix *m1,*m2,*res;
    printf("Matrix1:\n");
    m1 = create_test(2, 1);
    output(m1);
    printf("Matrix2:\n");
    m2 = create_test(2, 2);
    output(m2);
    printf("\n");
    res=create(2,2);
    printf("Multiplication of matrix:\n");
    multiply(m1,m2,res);
    printf("Addition of matrix:\n");
    add(m1,m2,res);
    printf("scalar = 3\n");
    printf("Multiplication of matrix1 on scalar:\n");
    scalar_multiply(m1, 3, res);
    free(m1);
    free(m2);
    free(res);
}