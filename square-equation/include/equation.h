#pragma once

#define PRECISION 1e-6

enum results {
    NO_ROOTS = 0,
    SINGLE_ROOT,
    TWO_ROOTS,
    INF_ROOTS,
};


struct Equation {
    float a;
    float b;
    float c;
    float x1;
    float x2;
};


void equation_input(struct Equation* equation);

void equation_init(struct Equation* equation);

int equation_solve(struct Equation* equation);