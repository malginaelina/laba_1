#ifndef MAIN_C_COMPLEX_NUMBERS_H
#define MAIN_C_COMPLEX_NUMBERS_H

// структура для комплексных чисел
struct Complex
{
    float x;
    float y;
};

struct Complex* input_complex();
struct Complex *add_complex(struct Complex *a, struct Complex *b);
struct Complex *multiply_complex(struct Complex *a, struct Complex *b);
struct Complex *multiply_on_scalar_complex(struct Complex *a, float scalar);
void output_complex(struct Complex *a);

#endif //MAIN_C_COMPLEX_NUMBERS_H
