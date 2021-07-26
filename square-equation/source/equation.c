#include "equation.h"
#include <math.h>
#include <float.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>

#define DEBUG
#undef DEBUG

//======================================================================
void equation_init(struct Equation* equation) {

    assert(equation != NULL);

    equation->a = NAN;
    equation->b = NAN;
    equation->c = NAN;
    equation->x1 = NAN;
    equation->x2 = NAN;
}

//======================================================================
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

//======================================================================
int is_equal(float a, int b) {
    return (fabs(a - b) < PRECISION) ? 1:0;
}

//======================================================================
int equation_solve_linear(struct Equation* equation) {
    assert(equation != NULL);

    float b = equation->b;
    float c = equation->c;

    assert(is_equal(b, 0) == 0);

    float result = -c / b;
    equation->x1 = result;

    return SINGLE_ROOT;
}

//======================================================================
int equation_solve(struct Equation* equation) {
    assert(equation != NULL);

    float a = equation->a;
    float b = equation->b;
    float c = equation->c;
    float discr = NAN;
    float discr_sqr = NAN;

    int result = 0;

    if (is_equal(a, 0) && (is_equal(b, 0) == 0)) {
        result = equation_solve_linear(equation);
    } else if (is_equal(a, 0) && is_equal(b, 0)) {

        if (is_equal(c, 0)) {

            equation->x1 = INFTY;
            equation->x2 = INFTY;
            result = INF_ROOTS;

        } else {

            equation->x1 = NOT_A_ROOT;
            equation->x2 = NOT_A_ROOT;
            result = NO_ROOTS;

        }

    } else {

        #ifdef DEBUG
        fprintf(stderr, "Solving quadratic.\n");
        #endif

        discr = b * b - 4 * a * c;
        if (discr > 0) {
            discr_sqr = sqrt(discr);
        }

        #ifdef DEBUG
        fprintf(stderr, "Discr: %.2f\n", discr);
        #endif

        if (discr < 0) {

            equation->x1 = NOT_A_ROOT;
            equation->x2 = NOT_A_ROOT;
            result = NO_ROOTS;

        } else if (is_equal(discr, 0)) {
            result = SINGLE_ROOT;

            equation->x1 = -b / (2 * a);
            equation->x2 = NOT_A_ROOT;

        } else {
            result = TWO_ROOTS;

            equation->x1 = (-b - discr_sqr) / (2 * a);
            equation->x2 = (-b + discr_sqr) / (2 * a);

            #ifdef DEBUG
            fprintf(stderr, "x1: %.2f\n", equation->x1);
            fprintf(stderr, "x2: %.2f\n", equation->x2);
            #endif
            
        }

    }

    return result;

}

//======================================================================
void equation_print(struct Equation* equation) {
    printf("%.2f * x^2 + %.2f * x + %.2f = 0\n", equation->a, equation->b, equation->c);
}


//======================================================================
int equation_print_result(struct Equation* equation, int result_type) {
    assert(equation);

    switch(result_type) {
        case NO_ROOTS:
        printf("No roots for the equation: ");
        break;
        case INF_ROOTS:
        printf("Infinite amount of roots for the equation: ");
        break;
        case SINGLE_ROOT:
        printf("Only single root %.2f for the equation: ", equation->x1);
        break;
        case TWO_ROOTS:
        printf("x1 = %.2f, x2 = %.2f for the equation: ", equation->x1, equation->x2);
        break;
        default:
        fprintf(stderr, "ERROR: UNEXPECTED RESULT TYPE\n");
        return -1;
        break;
    }

    equation_print(equation);

    return 0;
}



