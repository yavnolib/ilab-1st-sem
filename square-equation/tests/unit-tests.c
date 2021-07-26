#include "equation.h"
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <stdio.h>

/*! \file unit-tests.c 
 Unit-tests for equation solver */

//! A static variable which represents the number of completed tests.
static int passed_counter = 0;

/* TODO
1) Update test generation with defines or call calculate function on the
    array of input
2) Add option do dump output do /dev/null
 */

//! Compares to equations.
/*! \param lhs - the first equation
 * \param rhs - the second equaiton
 * \returns - 1 if equal, 0 if not. */
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
    struct Equation tests_input = {0, 2, 1, NOT_A_ROOT, NOT_A_ROOT};
    struct Equation tests_output = {0, 2, 1, -0.5, NOT_A_ROOT};

    printf("Expected for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n",
            tests_input.a, tests_input.b, tests_input.c, tests_input.x1, tests_input.x2);
    equation_solve(&tests_input);

    printf("Result for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n\n\n",
            tests_input.a, tests_input.b, tests_input.c, tests_input.x1, tests_input.x2);

    assert(is_equal(&tests_input, &tests_output));
    passed_counter++;   
}

void test_2() {
    struct Equation tests_input = {0, 15, -9999, NOT_A_ROOT, NOT_A_ROOT};
    struct Equation tests_output = {0, 15, -9999, 666.6, NOT_A_ROOT};

    printf("Expected for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n",
            tests_input.a, tests_input.b, tests_input.c, tests_input.x1, tests_input.x2);
    equation_solve(&tests_input);

    printf("Result for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n\n\n",
            tests_input.a, tests_input.b, tests_input.c, tests_input.x1, tests_input.x2);

    assert(is_equal(&tests_input, &tests_output));
    passed_counter++;
}

void test_3() {
    struct Equation tests_input = {1, 2, 1, NOT_A_ROOT, NOT_A_ROOT};
    struct Equation tests_output = {1, 2, 1, -1, NOT_A_ROOT};

    printf("Expected for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n",
            tests_input.a, tests_input.b, tests_input.c, tests_input.x1, tests_input.x2);
    equation_solve(&tests_input);

    printf("Result for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n\n\n",
            tests_input.a, tests_input.b, tests_input.c, tests_input.x1, tests_input.x2);

    assert(is_equal(&tests_input, &tests_output));
    passed_counter++;
}

void test_4() {
    struct Equation tests_input = {1, 1, -6, NOT_A_ROOT, NOT_A_ROOT};
    struct Equation tests_output = {1, 1, -6, -3, 2};

    printf("Expected for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n",
            tests_input.a, tests_input.b, tests_input.c, tests_input.x1, tests_input.x2);
    equation_solve(&tests_input);

    printf("Result for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n\n\n",
            tests_input.a, tests_input.b, tests_input.c, tests_input.x1, tests_input.x2);

    assert(is_equal(&tests_input, &tests_output));
    passed_counter++;
}

void test_5() {
    struct Equation tests_input = {0, 0, 4, NOT_A_ROOT, NOT_A_ROOT};
    struct Equation tests_output = {0, 0, 4, NOT_A_ROOT, NOT_A_ROOT};

    printf("Expected for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n",
            tests_input.a, tests_input.b, tests_input.c, tests_input.x1, tests_input.x2);
    equation_solve(&tests_input);

    printf("Result for %.2f*x^2 + %.2f*x + %.2f = 0:\n x1 = %.2f, x2 = %.2f\n\n\n",
            tests_input.a, tests_input.b, tests_input.c, tests_input.x1, tests_input.x2);

    assert(is_equal(&tests_input, &tests_output));
    passed_counter++;
}

void test_6() {
    struct Equation tests_input = {0, 0, 0, NOT_A_ROOT, NOT_A_ROOT};
    struct Equation tests_output = {0, 0, 0, INFTY, INFTY};

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
    test_3();
    test_4();
    test_5();
    test_6();

    tests_cleanup(equation);

}

