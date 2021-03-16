#include<stdio.h>
#include<malloc.h>

struct Matrix
{
    void* matrix;
    int size;
    int type;
};

struct Complex
{
    float x;
    float y;
};

struct Matrix* create(int size, int type);

void input(struct Matrix* m1);
void output(struct Matrix* m1);
void multiply(struct Matrix* m1, struct Matrix* m2, struct Matrix* res);
void add(struct Matrix* m1, struct Matrix* m2, struct Matrix* res);
void scalar_multiply(struct Matrix* m1, float scalar, struct Matrix* res);


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
        printf("Choose the number of operation:\n1 - add matrix\n2 - multiply matrix\n3 - multiply matrix on scalar\n");
        scanf_s("%d", &operation);
        if (operation != 1 && operation != 2 && operation != 3)
        {
            printf("Wrong number of operation. Try one more time.\n");
            flag = 1;
        }
    }

    printf("Enter size of matrix nxn: ");
    scanf_s("%d", &size);

    flag = 1;
    while (flag)
    {
        flag = 0;
        printf("Enter type of data (1-float, 2-complex): ");
        scanf_s("%d", &type_1);
        if (type_1 != 1 && type_1 != 2)
        {
            printf("Wrong type of data. Try one more time.\n");
            flag = 1;
        }
        if (operation != 3)
        {
            printf("Enter type of data (1-float, 2-complex): ");
            scanf_s("%d", &type_2);
            if (type_2 != 1 && type_2 != 2)
            {
                printf("Wrong type of data. Try one more time.\n");
                flag = 1;
            }
        }
        
    }

    mat1 = create(size, type_1);

    switch (operation)
    {
        case 1:
            if (type_1 <= type_2)
                type_3 = type_2;
            else type_3 = type_1;
            mat2 = create(size, type_2);
            res = create(size, type_3);
            input(mat1);
            input(mat2);
            add(mat1, mat2, res);
            free(mat2);
            free(res);
            free(mat1);
            break;
        case 2:
            if (type_1 <= type_2)
                type_3 = type_2;
            else type_3 = type_1;
            mat2 = create(size, type_2);
            res = create(size, type_3);
            input(mat1);
            input(mat2);
            multiply(mat1, mat2, res);
            free(mat2);
            free(res);
            free(mat1);
            break;
        case 3:
            printf("Enter scalar: ");
            scanf_s("%f", &scalar);
            res = create(size, type_1);
            input(mat1);
            scalar_multiply(mat1, scalar, res);
            free(res);
            free(mat1);
            break;
    }

    return 0;
}

struct Matrix* create(int size, int type)
{
    struct Matrix* mtrx = (struct Matrix*)malloc(sizeof(struct Matrix));
    mtrx->size = size;
    mtrx->type = type;
    mtrx->matrix = malloc(size * size * type);
    for (int i = 0; i < size * size * type; i++)
        *(char*)((char*)mtrx->matrix + i) = 0;
    return mtrx;
}

struct Complex* inputcomplex()
{
    struct Complex* complex = (struct Complex*)malloc(sizeof(struct Complex));
    printf("Enter real part: ");
    scanf_s("%f", &complex->x);
    printf("Enter imaginary part: ");
    scanf_s("%f", &complex->y);
    return complex;
}

void input(struct Matrix* m1)
{
    printf("Enter elements of matrix:\n");
    for (int i = 0; i < m1->size * m1->size; i++)
    {
        if (m1->type == 1)
            scanf_s("%f", ((float*)m1->matrix + i));
        else
            *((struct Complex*)m1->matrix + i) = *inputcomplex();
    }
}

void output(struct Matrix* m1)
{
    printf("Result of the operation:\n");
    for (int i = 0; i < m1->size * m1->size; i++)
    {
        if (m1->type == 1)
            printf("%0.2f ", *((float*)m1->matrix + i));
        else
        {
            if ((((struct Complex*)m1->matrix + i)->x) == 0)
                printf("%0.2fi ", ((struct Complex*)m1->matrix + i)->y);
            else if ((((struct Complex*)m1->matrix + i)->y) == 0)
                printf("%0.2f ", ((struct Complex*)m1->matrix + i)->x);
            else if ((((struct Complex*)m1->matrix + i)->y) > 0)
                printf("%0.2f+%0.2fi ", ((struct Complex*)m1->matrix + i)->x, ((struct Complex*)m1->matrix + i)->y);
            else
                printf("%0.2f%0.2fi ", ((struct Complex*)m1->matrix + i)->x, ((struct Complex*)m1->matrix + i)->y);                        
        }
        if ((i + 1) % m1->size == 0)
            printf("\n");
    }
    printf("\n");
}

void multiply(struct Matrix* m1, struct Matrix* m2, struct Matrix* res)
{
    float element, element_x, element_y;

    for (int i = 0; i < m1->size; i++)
    {
        for (int j = 0; j < m1->size; j++)
        {
            element = 0;
            element_x = 0;
            element_y = 0;
            for (int k = 0; k < m1->size; k++)
            {
                if (m1->type == 1 && m2->type == 1)
                {
                    element += *((float*)m1->matrix + i * m1->size + k) * (*((float*)m2->matrix + k * m2->size + j));
                    *((float*)res->matrix + i * res->size + j) = element;
                }
                else if (m1->type == 1 && m2->type == 2)
                {
                    element_x += *((float*)m1->matrix + i * m1->size + k) * ((struct Complex*)m2->matrix + k * m1->size + j)->x;
                    ((struct Complex*)res->matrix + i * res->size + j)->x = element_x;
                    element_y += *((float*)m1->matrix + i * m1->size + k) * ((struct Complex*)m2->matrix + k * m1->size + j)->y;
                    ((struct Complex*)res->matrix + i * res->size + j)->y = element_y;
                }
                else if (m1->type == 2 && m2->type == 1)
                {
                    element_x += ((struct Complex*)m1->matrix + i * m1->size + k)->x * (*((float*)m2->matrix + k * m2->size + j));
                    ((struct Complex*)res->matrix + i * res->size + j)->x = element_x;
                    element_y += ((struct Complex*)m1->matrix + i * m1->size + k)->y * (*((float*)m2->matrix + k * m2->size + j));
                    ((struct Complex*)res->matrix + i * res->size + j)->y = element_y;
                }
                else
                {
                    element_x += ((struct Complex*)m1->matrix + i*m1->size + k)->x*
                        ((struct Complex*)m2->matrix + k * m1->size + j)->x - ((struct Complex*)m1->matrix + i * m1->size + k)->y*
                        ((struct Complex*)m2->matrix + k * m1->size + j)->y;
                    ((struct Complex*)res->matrix + i * res->size + j)->x = element_x;
                    element_y += ((struct Complex*)m1->matrix + i * m1->size + k)->x *
                        ((struct Complex*)m2->matrix + k * m1->size + j)->y + ((struct Complex*)m1->matrix + i * m1->size + k)->y *
                        ((struct Complex*)m2->matrix + k * m1->size + j)->x;
                    ((struct Complex*)res->matrix + i * res->size + j)->y = element_y;
                }
            }
        }

    }

    output(res);
}

void add(struct Matrix* m1, struct Matrix* m2, struct Matrix* res)
{

    for (int i = 0; i < res->size * res->size; i++)
    {
        if (m1->type == 1 && m2->type == 1)
        {
            *((float*)res->matrix + i) = *((float*)m1->matrix + i) + *((float*)m2->matrix + i);
        }
        else if (m1->type == 1 && m2->type == 2)
        {
            ((struct Complex*)res->matrix + i)->x = *((float*)m1->matrix + i) + ((struct Complex*)m2->matrix + i)->x;
            ((struct Complex*)res->matrix + i)->y = ((struct Complex*)m2->matrix + i)->y;
        }
        else if (m1->type == 2 && m2->type == 1)
        {
            ((struct Complex*)res->matrix + i)->x = *((float*)m2->matrix + i) + ((struct Complex*)m1->matrix + i)->x;
            ((struct Complex*)res->matrix + i)->y = ((struct Complex*)m1->matrix + i)->y;
        }
        else
        {
            ((struct Complex*)res->matrix + i)->x = ((struct Complex*)m1->matrix + i)->x + ((struct Complex*)m2->matrix + i)->x;
            ((struct Complex*)res->matrix + i)->y = ((struct Complex*)m1->matrix + i)->y + ((struct Complex*)m2->matrix + i)->y;
        }
    }

    output(res);
}

void scalar_multiply(struct Matrix* m1, float scalar, struct Matrix* res)
{
    for (int i = 0; i < res->size * res->size; i++)
    {
        if (m1->type == 1)
            *((float*)res->matrix + i) = *((float*)m1->matrix + i) * scalar;
        else
        {
            ((struct Complex*)res->matrix + i)->x = ((struct Complex*)m1->matrix + i)->x * scalar;
            ((struct Complex*)res->matrix + i)->y = ((struct Complex*)m1->matrix + i)->y * scalar;
        }
    }

    output(res);
}