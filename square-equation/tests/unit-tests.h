#pragma once

#include "equation.h"

/*! \file unit-tests.h
 * Unit tests. */

//! Test initializer. Prepares equation for testing
/*! \returns Pointer to equation structure. */
struct Equation* tests_init();

void test_1();

void test_1();

void test_1();

void test_1();

void test_1();

//! Test destructor. Clears all memory after all tests have been completed.
/*! \param Test equation */
void tests_cleanup(struct Equation* equation);