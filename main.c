#include<stdio.h>
#include<malloc.h>
#include "cmake-build-debug/functions.h"
#include "cmake-build-debug/tests.h"

int main()
{
    struct Matrix* mat1, * mat2;
    struct Matrix* res;

    int size, type_1, type_2, type_3, operation;
    float scalar;
    int flag = 1;

    while (flag)
    {
        flag = 0;
        printf("Choose the number of operation:\n1 - add matrix\n2 - multiply matrix\n3 - multiply matrix on scalar\n4 - test\n");
        scanf_s("%d", &operation);
        if (operation != 1 && operation != 2 && operation != 3 && operation != 4)
        {
            printf("Wrong number of operation. Try one more time.\n");
            flag = 1;
        }
    }

    if (operation != 4) {
        printf("Enter size of matrix nxn: ");
        scanf_s("%d", &size);

        flag = 1;
        while (flag) {
            flag = 0;
            printf("Enter type of data (1-float, 2-complex): ");
            scanf_s("%d", &type_1);
            if (type_1 != 1 && type_1 != 2) {
                printf("Wrong type of data. Try one more time.\n");
                flag = 1;
            }
            if (operation != 3) {
                printf("Enter type of data (1-float, 2-complex): ");
                scanf_s("%d", &type_2);
                if (type_2 != 1 && type_2 != 2) {
                    printf("Wrong type of data. Try one more time.\n");
                    flag = 1;
                }
            }

        }


    }

    switch (operation)
    {
        case 1:
            if (type_1 <= type_2)
                type_3 = type_2;
            else type_3 = type_1;
            mat1 = create(size, type_1);
            mat2 = create(size, type_2);
            res = create(size, type_3);
            input(mat1);
            input(mat2);
            printf("Matrix1:\n");
            output(mat1);
            printf("Matrix2:\n");
            output(mat2);
            printf("\n");
            printf("Result of the operation:\n");
            add(mat1, mat2, res);
            free(mat2);
            free(res);
            free(mat1);
            break;
        case 2:
            if (type_1 <= type_2)
                type_3 = type_2;
            else type_3 = type_1;
            mat1 = create(size, type_1);
            mat2 = create(size, type_2);
            res = create(size, type_3);
            input(mat1);
            input(mat2);
            printf("Matrix1:\n");
            output(mat1);
            printf("Matrix2:\n");
            output(mat2);
            printf("Result of the operation:\n");
            multiply(mat1, mat2, res);
            free(mat2);
            free(res);
            free(mat1);
            break;
        case 3:
            mat1 = create(size, type_1);
            printf("Enter scalar: ");
            scanf_s("%f", &scalar);
            res = create(size, type_1);
            input(mat1);
            printf("Matrix1:\n");
            output(mat1);
            printf("Result of the operation:\n");
            scalar_multiply(mat1, scalar, res);
            free(res);
            free(mat1);
            break;
        case 4:
            tests();
            break;
    }

    return 0;
}


