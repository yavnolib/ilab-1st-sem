#include <stdio.h>
#include <stdlib.h>
#include "equation.h"

int main() {

    struct Equation equation;
    int result = 0;
    int ret = 0;

    equation_init(&equation);
    equation_input(&equation);
    result = equation_solve(&equation);
    ret = equation_print_result(&equation, result);

    if (ret < 0) {
        fprintf(stderr, "Error printing equation result.\n");
        return -1;
    }

    return 0;
}