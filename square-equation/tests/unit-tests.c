#include "equation.h"
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <stdio.h>

static int passed_counter = 0;

/* TODO
1) Update test generation with defines or call calculate function on the
    array of input
 */

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


void test_1() {
    struct Equation tests_input = {0, 2, 1, 0, 0};
    struct Equation tests_output = {0, 2, 1, -0.5, 0};

    printf("Expected for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n",
            tests_input.a, tests_input.b, tests_input.c, tests_input.x1, tests_input.x2);
    equation_solve(&tests_input);

    printf("Result for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n\n\n",
            tests_input.a, tests_input.b, tests_input.c, tests_input.x1, tests_input.x2);

    assert(is_equal(&tests_input, &tests_output));
    passed_counter++;   
}

void test_2() {
    struct Equation tests_input = {0, 15, -9999, 0, 0};
    struct Equation tests_output = {0, 15, -9999, 666.6, 0};

    printf("Expected for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n",
            tests_input.a, tests_input.b, tests_input.c, tests_input.x1, tests_input.x2);
    equation_solve(&tests_input);

    printf("Result for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n\n\n",
            tests_input.a, tests_input.b, tests_input.c, tests_input.x1, tests_input.x2);

    assert(is_equal(&tests_input, &tests_output));
    passed_counter++;
}

struct Equation* tests_init() {

    struct Equation* equation;
    equation = (struct Equation*) calloc(1, sizeof(struct Equation));
    assert(equation != NULL);

    equation_init(equation);

    return equation;
}

void tests_cleanup(struct Equation* equation) {
    assert(equation != NULL);
    free(equation);
    printf("TESTS PASSED: %d\n", passed_counter);
}

int main() {

    struct Equation* equation = tests_init();
    test_1();
    test_2();
    tests_cleanup(equation);

}