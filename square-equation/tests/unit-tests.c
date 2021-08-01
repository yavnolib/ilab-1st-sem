#include "equation.h"
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <stdio.h>

static struct Equation* input; 
static struct Equation* output;

static int is_equal(struct Equation* lhs, struct Equation* rhs) {

    if (fabs(lhs->a - rhs->a) < PRECISION &&
       fabs(lhs->b - rhs->b) < PRECISION &&
       fabs(lhs->c - rhs->c) < PRECISION &&
       fabs(lhs->x1 - rhs->x1) < PRECISION &&
       fabs(lhs->x2 - rhs->x2) < PRECISION) {
        return 1;
    } else {
        return 0;
    }
}



#define TEST(coeff1, coeff2, coeff3, ans1, ans2)                                            \
    input->a = coeff1;                                                                      \
    input->b = coeff2;                                                                      \
    input->c = coeff3;                                                                      \
    input->x1 = NOT_A_ROOT;                                                                 \
    input->x2 = NOT_A_ROOT;                                                                 \
    output->a = coeff1;                                                                     \
    output->b = coeff2;                                                                     \
    output->c = coeff3;                                                                     \
    output->x1 = ans1;                                                                      \
    output->x2 = ans2;                                                                      \
                                                                                            \
    printf("Expected for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n",           \
            (*output).a, (*output).b, (*output).c, (*output).x1, (*output).x2);             \
                                                                                            \
    equation_solve(input);                                                                  \
                                                                                            \
    printf("Result for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n\n\n",         \
            (*input).a, (*input).b, (*input).c, (*input).x1, (*input).x2);                  \
                                                                                            \
    assert(is_equal(input, output));                                                        \

void tests_init() {
    printf("INITIALIZING TESTS\n");
    input = (struct Equation*) calloc(1, sizeof(struct Equation));
    output = (struct Equation*) calloc(1, sizeof(struct Equation));
}

void tests_cleanup() {
    printf("TESTS PASSED\n");
    free(input);
    free(output);
}

int main() {

    tests_init();

    TEST(0, 2, 1, -0.5, NOT_A_ROOT)
    TEST(0, 15, -9999, 666.6, NOT_A_ROOT)
    TEST(1, 2, 1, -1, NOT_A_ROOT)
    TEST(1, 1, -6, -3, 2)
    TEST(0, 0, 4, NOT_A_ROOT, NOT_A_ROOT)
    TEST(0, 0, 0, INFTY, INFTY)


    tests_cleanup();

}

