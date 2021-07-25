#include <stdio.h>
#include <stdlib.h>
#include "equation.h"

int main() {

    struct Equation equation;

    equation_init(&equation);
    equation_input(&equation);
    equation_solve(&equation);

    return 0;
}