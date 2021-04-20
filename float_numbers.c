#include "float_numbers.h"

float *add_float(const float *a, const float *b){
    float *c = calloc(1, sizeof(float));
    *c = *a + *b;
    return c;
}

float *multiply_float(const float *a, const float *b){
    float *c = calloc(1, sizeof(float));
    *c = *a * *b;
    return c;
}

float *multiply_on_scalar_float(const float *a, float b){
    float *c = calloc(1, sizeof(float));
    *c = *a * b;
    return c;
}