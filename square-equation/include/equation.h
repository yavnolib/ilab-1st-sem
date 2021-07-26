#pragma once

/*! \file equation.h
 * Equation's properties. */

//! constant for number comparisons
#define PRECISION 1e-6


//! constant for specifying root types
#define INFTY 666666
//! constant for specifying root types
#define NOT_A_ROOT -666666

//! \enum results
/*! An enum with values for each possible roots scenario. */
enum results {
    NO_ROOTS = 0,
    SINGLE_ROOT,
    TWO_ROOTS,
    INF_ROOTS,
};


//! \struct Equation "equation.h"
/*! Structure of the equation, which include equation'c coefficients and roots. */
struct Equation {
    float a; /*!< Coefficient with x^2. */
    float b; /*!< Coefficient with x^1. */
    float c; /*!< Coefficient with x^0. */
    float x1; /*!< First possible root. */
    float x2; /*!< Second possible root. */
};



//! Function that receives input from user.
/*! \param equation - the equation where input should be placed. */
void equation_input(struct Equation* equation);

//! Initializes equation, leaving all its members in valid state
//! before input is placed.
/*! \param equation - the equation to be initialized */
void equation_init(struct Equation* equation);

//! Solves the equation, roots are places into the equation's structure.
/*! \param equation - the equation to be solved.
 * \returns result - type of the result (see enum results) */
int equation_solve(struct Equation* equation);

//! Function that prints the equation.
/*! \param equation - the equation to be printed. */
void equation_print(struct Equation* equation);

//! Function that receives input from user.
/*! \param equation - the equation for which the results should be printed.
 * \param results - the type of result. This should be obtained through
 *  equation_solve() function */
int equation_print_result(struct Equation* equation, int result_type);





