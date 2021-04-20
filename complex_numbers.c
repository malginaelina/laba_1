#include "complex_numbers.h"
#include <stdio.h>
#include<malloc.h>

struct Complex *input_complex()
{
    struct Complex* a = (struct Complex*)malloc(sizeof(struct Complex));
    printf("Enter real part:\n");
    scanf_s("%f", &a->x);
    printf("Enter imaginary part:\n");
    scanf_s("%f", &a->y);
    return a;
}

struct Complex *add_complex(struct Complex *a, struct Complex *b){
    struct Complex *c = (struct Complex*)malloc(sizeof(struct Complex));
    c->x = a->x + b->x;
    c->y = a->y + b->y;
    return c;
}

struct Complex *multiply_complex(struct Complex *a, struct Complex *b){
    struct Complex *c = (struct Complex*)malloc(sizeof(struct Complex));
    c->x = a->x * b->x - a->y * b->y;
    c->y = a->x * b->y + a->y * b->x;
    return c;
}

struct Complex *multiply_on_scalar_complex(struct Complex *a, float scalar){
    struct Complex *c = (struct Complex*)malloc(sizeof(struct Complex));
    c->x = a->x * scalar;
    c->y = a->y * scalar;
    return c;
}

void output_complex(struct Complex *a){
    printf(" %.2f + %.2fi", a->x, a->y);
}