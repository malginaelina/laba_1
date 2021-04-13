#include<stdio.h>
#include<malloc.h>
#include "matrix.h"
#include "tests.h"

int main()
{
    struct Matrix *mat1, *mat2;
    struct Matrix *res;

    int size1, size2;
    int type1, type2, operation;
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

        flag = 1;
        while (flag) {
            flag = 0;
            if (operation != 4) {
                printf("Enter size of Matrix1 nxn:\n");
                scanf_s("%d", &size1);
            printf("Enter type of data (1-float, 2-complex) for Matrix1:\n");
            scanf_s("%d", &type1);
            if (type1 != 1 && type1 != 2) {
                printf("Wrong type of data. Try one more time.\n");
                flag = 1;
            }
            if (operation != 3) {
                printf("Enter size of Matrix2 nxn:\n");
                scanf_s("%d", &size2);
                if (size1 != size2) {
                    printf("Different sizes. Try one more time.\n");
                    flag = 1;
                }
                printf("Enter type of data (1-float, 2-complex) for Matrix2:\n");
                scanf_s("%d", &type2);
                if (type2 != 1 && type2 != 2) {
                    printf("Wrong type of data. Try one more time.\n");
                    flag = 1;
                }
                if (type1 != type2) {
                    printf("Different types. Try one more time.\n");
                    flag = 1;
                }
            }

        }

    }

    switch (operation)
    {
        case 1:
            if (type1 == 1){
                mat1 = createMatrix_float(size1, type1);
                mat2 = createMatrix_float(size1, type1);
                res = createMatrix_float(size1, type1);
                printf("Enter elements of Matrix1:\n");
                inputMatrix_float(mat1);
                printf("Enter elements of Matrix2:\n");
                inputMatrix_float(mat2);
                printf("\n");
                printf("Matrix 1:\n");
                outputMatrix_float(mat1);
                printf("Matrix 2:\n");
                outputMatrix_float(mat2);
                printf("Result of the addition:\n");
                addMatrix_float(mat1, mat2, res);
                free(mat2);
                free(res);
                free(mat1);
            }
            else{
                mat1 = createMatrix_complex(size1, type1);
                mat2 = createMatrix_complex(size1, type1);
                res = createMatrix_complex(size1, type1);
                printf("Enter elements of Matrix1:\n");
                inputMatrix_complex(mat1);
                printf("Enter elements of Matrix2:\n");
                inputMatrix_complex(mat2);
                printf("\n");
                printf("Matrix 1:\n");
                outputMatrix_complex(mat1);
                printf("Matrix 2:\n");
                outputMatrix_complex(mat2);
                printf("Result of the addition:\n");
                addMatrix_complex(mat1, mat2, res);
                free(mat2);
                free(res);
                free(mat1);
            }
            break;
        case 2:
            if (type1 == 1){
                mat1 = createMatrix_float(size1, type1);
                mat2 = createMatrix_float(size1, type1);
                res = createMatrix_float(size1, type1);
                printf("Enter elements of Matrix1:\n");
                inputMatrix_float(mat1);
                printf("Enter elements of Matrix2:\n");
                inputMatrix_float(mat2);
                printf("\n");
                printf("Matrix 1:\n");
                outputMatrix_float(mat1);
                printf("Matrix 2:\n");
                outputMatrix_float(mat2);
                printf("Result of the multiplication:\n");
                multiplyMatrix_float(mat1, mat2, res);
                free(mat2);
                free(res);
                free(mat1);
            }
            else{
                mat1 = createMatrix_complex(size1, type1);
                mat2 = createMatrix_complex(size1, type1);
                res = createMatrix_complex(size1, type1);
                printf("Enter elements of Matrix1:\n");
                inputMatrix_complex(mat1);
                printf("Enter elements of Matrix2:\n");
                inputMatrix_complex(mat2);
                printf("\n");
                printf("Matrix 1:\n");
                outputMatrix_complex(mat1);
                printf("Matrix 2:\n");
                outputMatrix_complex(mat2);
                printf("Result of the multiplication:\n");
                multiplyMatrix_complex(mat1, mat2, res);
                free(mat2);
                free(res);
                free(mat1);
            }
            break;
        case 3:
            if (type1 == 1){
                mat1 = createMatrix_float(size1, type1);
                res = createMatrix_float(size1, type1);
                printf("Enter elements of Matrix:\n");
                inputMatrix_float(mat1);
                printf("\n");
                printf("Matrix:\n");
                outputMatrix_float(mat1);
                printf("Enter scalar:");
                scanf_s("%f", &scalar);
                printf("\n");
                printf("Result of the multiplication on scalar:\n");
                multiplyMatrixOnScalar_float(mat1, scalar, res);
                free(res);
                free(mat1);
            }
            else{
                mat1 = createMatrix_complex(size1, type1);
                res = createMatrix_complex(size1, type1);
                printf("Enter elements of Matrix:\n");
                inputMatrix_complex(mat1);
                printf("\n");
                printf("Matrix:\n");
                outputMatrix_complex(mat1);
                printf("Enter scalar:");
                scanf_s("%f", &scalar);
                printf("\n");
                printf("Result of the multiplication on scalar:\n");
                multiplyMatrixOnScalar_complex(mat1, scalar, res);
                free(res);
                free(mat1);
            }
            break;
        case 4:
            tests();
            break;
        default:
            break;
    }

    return 0;
}
