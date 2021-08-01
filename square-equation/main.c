#include <stdio.h>
#include <stdlib.h>
#include "equation.h"

/* TODO
1) Update test generation with defines or call calculate function on the
    array of input
2) Add option do dump output do /dev/null
3) Write criteria for assessment
4) Add colorized error printing
5) Make a library with colorized output
 */

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