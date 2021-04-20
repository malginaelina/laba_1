#include "matrix.h"
#include "tests.h"

int dialog (const char *msgs[], int n)
{
    int choice;
    do {
        for (int i = 0; i < n; ++i)
            puts(msgs[i]);
        printf("> ");

        choice = getchar() - '0';
        while (getchar() != '\n');
        if (choice < 0 || choice >= n)
            printf("You're wrong. Try again!\n");

    } while (choice < 0 || choice >= n);

    return choice;
}

const char *MENU[] = {"0 - exit",
                      "1 - add matrix",
                      "2 - multiply matrix",
                      "3 - multiply matrix on scalar",
                      "4 - test"};
const int SIZE_MENU = sizeof(MENU)/sizeof(MENU[0]);

const char *MENU_TYPE[] = {"0 - exit",
                           "1 - float",
                           "2 - complex"};

const int SIZE_MENU_TYPE = sizeof(MENU_TYPE)/sizeof(MENU_TYPE[0]);

int main()
{

    struct Matrix *mat1, *mat2;
    int menu;
    do {
        menu = dialog(MENU, SIZE_MENU);
        switch(menu)
        {
            case 0:
                break;
            case 1:{
                int menu_type;
                do{
                    menu_type = dialog(MENU_TYPE, SIZE_MENU_TYPE);
                    switch(menu_type){
                        case 0:
                            break;
                        case 1:{
                            int size;
                            printf("Input size of matrix:\n");
                            scanf_s("%d", &size);
                            getchar();
                            mat1 = createMatrix_float(size);
                            mat2 = createMatrix_float(size);
                            printf("Enter elements of Matrix1:\n");
                            inputMatrix_float(mat1);
                            printf("Enter elements of Matrix2:\n");
                            inputMatrix_float(mat2);
                            printf("Matrix1:\n");
                            outputMatrix_float(mat1);
                            printf("Matrix2:\n");
                            outputMatrix_float(mat2);
                            struct Matrix *res = add_matrix(mat1, mat2);
                            printf("Result of the addition:\n");
                            outputMatrix_float(res);
                        }
                            break;
                        case 2:{
                            int size;
                            printf("Input size of matrix:\n");
                            scanf_s("%d", &size);
                            getchar();
                            mat1 = createMatrix_complex(size);
                            mat2 = createMatrix_complex(size);
                            printf("Enter elements of Matrix1:\n");
                            inputMatrix_complex(mat1);
                            printf("Enter elements of Matrix2:\n");
                            inputMatrix_complex(mat2);
                            printf("Matrix1:\n");
                            outputMatrix_complex(mat1);
                            printf("Matrix2:\n");
                            outputMatrix_complex(mat2);
                            struct Matrix *res = add_matrix(mat1, mat2);
                            printf("Result of the addition:\n");
                            outputMatrix_complex(res);
                        }
                            break;
                        default:
                            break;
                    }
                } while(menu_type);
            }
                break;
            case 2:{
                int menu_type;
                do{
                    menu_type = dialog(MENU_TYPE, SIZE_MENU_TYPE);
                    switch(menu_type){
                        case 0:
                            break;
                        case 1:{
                            int size;
                            printf("Input size of matrix:\n");
                            scanf_s("%d", &size);
                            getchar();
                            mat1 = createMatrix_float(size);
                            mat2 = createMatrix_float(size);
                            printf("Enter elements of Matrix1:\n");
                            inputMatrix_float(mat1);
                            printf("Enter elements of Matrix2:\n");
                            inputMatrix_float(mat2);
                            printf("Matrix1:\n");
                            outputMatrix_float(mat1);
                            printf("Matrix2:\n");
                            outputMatrix_float(mat2);
                            struct Matrix *res = multiply_matrix(mat1, mat2);
                            printf("Result of the multiplication:\n");
                            outputMatrix_float(res);
                        }
                            break;
                        case 2:{
                            int size;
                            printf("Input size of matrix:\n");
                            scanf_s("%d", &size);
                            getchar();
                            mat1 = createMatrix_complex(size);
                            mat2 = createMatrix_complex(size);
                            printf("Enter elements of Matrix1:\n");
                            inputMatrix_complex(mat1);
                            printf("Enter elements of Matrix2:\n");
                            inputMatrix_complex(mat2);
                            printf("Matrix1:\n");
                            outputMatrix_complex(mat1);
                            printf("Matrix2:\n");
                            outputMatrix_complex(mat2);
                            struct Matrix *res = multiply_matrix(mat1, mat2);
                            printf("Result of the multiplication:\n");
                            outputMatrix_complex(res);
                        }
                            break;
                        default:
                            break;
                    }
                } while(menu_type);
            }
                break;
            case 3:{
                int menu_type;
                do{
                    menu_type = dialog(MENU_TYPE, SIZE_MENU_TYPE);
                    switch(menu_type){
                        case 0:
                            break;
                        case 1:{
                            int size;
                            float scalar;
                            printf("Input size of matrix:\n");
                            scanf_s("%d", &size);
                            getchar();
                            mat1 = createMatrix_float(size);
                            printf("Enter elements of Matrix1:\n");
                            inputMatrix_float(mat1);
                            printf("Input scalar:\n");
                            scanf_s("%f", &scalar);
                            getchar();
                            printf("Matrix1:\n");
                            outputMatrix_float(mat1);

                            struct Matrix *res = multiply_matrix_on_scalar(mat1, scalar);
                            printf("Result of the multiplication on scalar:\n");
                            outputMatrix_float(res);
                        }
                            break;
                        case 2:{
                            int size;
                            float scalar;
                            printf("Input size of matrix:\n");
                            scanf_s("%d", &size);
                            getchar();
                            mat1 = createMatrix_complex(size);
                            printf("Enter elements of Matrix1:\n");
                            inputMatrix_complex(mat1);
                            printf("Input scalar:\n");
                            scanf_s("%f", &scalar);
                            getchar();
                            printf("Matrix1:\n");
                            outputMatrix_complex(mat1);

                            struct Matrix *res = multiply_matrix_on_scalar(mat1, scalar);
                            printf("Result of the multiplication on scalar:\n");
                            outputMatrix_complex(res);
                        }
                            break;
                        default:
                            break;
                    }
                } while(menu_type);
            }
                break;
            case 4:{
                tests();
            }
                break;
            default:
                break;
        }
    } while(menu);

    return 0;
}
