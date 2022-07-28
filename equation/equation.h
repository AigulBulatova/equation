#pragma once

#include <stdio.h>

///Enumeration type for possible cases of the number of roots
///
///0 stands for NO_ROOTS, 1 for ONE_ROOT, 2 for TWO_ROOTS and 3 for_INF_ROOTS
///@see num_of_roots
enum roots_cases {
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3
};

///Structure for working with a quadratic equation
///
///Structure includes coefficients of equation, roots and amount of roots.
 struct Equation {
        double a;
        double b;
        double c;
        double x1;
        double x2;
        enum roots_cases num_of_roots;
}; 

///Function solves equation
///
///Function calls solve_quadratic_case or solve_linear_case.
///@param equation - pointer to a structure with coefficients, roots and amount of roots.
///@see struct Equation, solve_quadratic_case(), solve_linear_case().
void solve_quadratic(struct Equation *equation);

///Function solves quadratic equation
///
///Function changes variables x1, x2 and num_of_roots .
///@param equation - pointer to a structure with coefficients, roots and amount of roots.
///@see struct Equation, solve_quadratic().
void solve_quadratic_case(struct Equation *equation);


///Function solves linear equation
///
///Function changes variables x1 and num_of_roots.
///@param equation - pointer to a structure with coefficients, roots and amount of roots.
///@see struct Equation, solve_case().
void solve_linear_case(struct Equation* equation);


///Function read coefficients of equation
///
///Function receives on input 3 double values. 
///In case of input error function calls input_cleaner() and user can try again.
///@param equation - pointer to a structure with coefficients, roots and amount of roots.
///@see struct Equation, input_cleaner()
void input_of_args(struct Equation* equation);

///Function shows the results of solving the equation
///
///Function prints the number of roots of the equation and their values if they exist.
///@param equation - pointer to a structure with coefficients, roots and amount of roots.
///@see struct Equation.
void show_args(struct Equation* equation);


///Function initializes structure
///
///Function initializes coefficients and roots of the equation at the start.
///@param equation - pointer to a structure with coefficients, roots and amount of roots.
///@see struct Equation.
void struct_initial (struct Equation *equation);

