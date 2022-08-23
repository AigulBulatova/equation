#ifndef EQUATION_H
#define EQUATION_H

#include <stdio.h>

///@file equation.h contains function declarations, enumeration types and structures for solving the equation

///Enumeration type for possible cases of the number of roots
///
///0 stands for NO_ROOTS, 1 for ONE_ROOT, 2 for TWO_ROOTS and 3 for_INF_ROOTS
///@see num_of_roots
enum roots_cases {
    NO_ROOTS  = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3
};

///Enumeration type for user's answers
///
///@see user_menu()
enum answers {
    CONTINUE_SOLVING = 1,
    STOP = 2,
    NOT_STATED = 0
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
int solve_quadratic(Equation *equation);

///Function solves quadratic equation
///
///Function changes variables x1, x2 and num_of_roots .
///@param equation - pointer to a structure with coefficients, roots and amount of roots.
///@see struct Equation, solve_quadratic().
int solve_quadratic_case(Equation *equation);

///Function solves linear equation
///
///Function changes variables x1 and num_of_roots.
///@param equation - pointer to a structure with coefficients, roots and amount of roots.
///@see struct Equation, solve_case().
int solve_linear_case(Equation* equation);

///Function read coefficients of equation
///
///Function receives on input 3 double values. 
///In case of input error function calls input_cleaner() and user can try again.
///@param equation - pointer to a structure with coefficients, roots and amount of roots.
///@see struct Equation, input_cleaner()
void input_of_args(Equation* equation);

///Function for user interface
///
///This function sets the value of variable ans to YES or NO depending of user's answer.
///@returns value of variable ans
int user_menu(void);

///Function shows the results of solving the equation
///
///Function prints the number of roots of the equation and their values if they exist.
///@param equation - pointer to a structure with coefficients, roots and amount of roots.
///@see struct Equation.
int show_results(Equation* equation);

///Function initializes structure
///
///Function initializes coefficients and roots of the equation at the start.
///@param equation - pointer to a structure with coefficients, roots and amount of roots.
///@see struct Equation.
void equation_init(Equation *equation);
#endif

