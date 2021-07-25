#include "equation.h"
#include <math.h>
#include <float.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>


void equation_init(struct Equation* equation) {

    assert(equation != NULL);

    equation->a = NAN;
    equation->b = NAN;
    equation->c = NAN;
    equation->x1 = NAN;
    equation->x2 = NAN;
}


void equation_input(struct Equation* equation) {

    assert(equation != NULL);

    int res = 0;

    while (res != 3) {

        printf("Please enter the coefficients for the equation a*x^2 + b*x + c = 0 in the following form: \
                a - float, b - float, c - float\n");
        res = scanf("%f %f %f", &(equation->a), &(equation->b), &(equation->c));
        if (res != 3) {
            fprintf(stderr, "ERROR on input: invalid coefficient form.\n");
            fflush(stdin);
        }
    }

    assert(isfinite(equation->a));
    assert(isfinite(equation->b));
    assert(isfinite(equation->c));

    printf("Entered coefficients: a = %.2f, b = %.2f, c = %.2f\n", equation->a, 
                                                                equation->b,
                                                                equation->c);
}

int is_equal(float a, int b) {
    return (fabs(a - b) < PRECISION) ? 1:0;
}

int equation_solve_linear(struct Equation* equation) {
    assert(equation != NULL);

    float b = equation->b;
    float c = equation->c;

    assert(is_equal(b, 0) == 0);

    float result = -c / b;
    equation->x1 = result;.

    return SINGLE_ROOT;
}

int equation_solve(struct Equation* equation) {
    assert(equation != NULL);

    float a = equation->a;
    float b = equation->b;
    float c = equation->c;
    float discr = NAN;
    float discr_sqr = NAN:

    int result = 0;

    if (is_equal(a, 0) && (is_equal(b, 0) == 0)) {
        result = equation_solve_linear(equation);
    } else if (is_equal(a, 0) && is_equal(b, 0)) {

        if (is_equal(c, 0)) {
            result = INF_ROOTS;
        } else {
            result = NO_ROOTS;
        }

    } else {

        discr = b * b - 4 * a * c;
        if (discr < 0) {
            result = NO_ROOTS;
        } else if (is_equal(discr, 0)) {
            discr_sqr = sqrt(discr);
            result = SINGLE_ROOT;

            equation->x1 = (-b - discr_sqr) / (2 * a);

        } else {
            result = TWO_ROOTS;

            equation->x1 = (-b - discr_sqr) / (2 * a);
            equation->x2 = (-b + discr_sqr) / (2 * a);
            
        }

    }

}



