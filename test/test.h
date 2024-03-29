#ifndef TEST_H
#define TEST_H

#include <stdio.h> 

///@file test.h contains structures and function declarations for testing the program

///Structure for testing program
///
///This structure includes roots of equation and their amount 
///@see test_run(), test_solve()
struct Answers {
    double x1;
    double x2;
    int num_of_roots;
};

///Function starts testing
///
///This function runs test_solve() and test_show().
///@see struct Equation, test_solve(), test_show().
int test_run(void);

///Testing function
///
///This function solves test equations, compares received roots and their
///amount with answers. It indicates an error with number of test and type of error
///if any value doesn't match the answer.
///@param test[] - array including structures of equation to test.
///@param answers[] - array with correct answers for each equation from test[].
///@param size - number of equations to check.
///@see struct Equation, test_run(), test_show(), root_cases_print(). 
int test_solve(struct Equation test[], const Answers answers[], int size);

///Function shows test results
///
///This function print the amount of failed tests or notifies 
///that all tests passed successfully.
///@param failed_test - amount of failed tests.
///@see test_run().
int test_show(int failed_test);

///Printing the number of roots
///
///This function prints the name of enum root_cases instead of its value.
///@param root_case defines a number of roots.
///@see test_solve().
int root_cases_print(int root_case);

///Function compares two double values
///
///This function used to compare roots of equation in tests and includes the NAN case
///@param x_test - first double value to compare
///@param x_answers - second double value to compare
///@returns 1 if x_test and x_answers are equal and 0 if they aren't
int root_compare(double root_test, double root_answers);
#endif