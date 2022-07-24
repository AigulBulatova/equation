#pragma once


enum roots_cases {
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3
};

 struct Equation {
        double a;
        double b;
        double c;
        double x1;
        double x2;
        enum roots_cases num_of_roots
}; 

///Function solves equation
///
///Function calls solve_quadratic_case or solve_linear_case
///@param equation - pointer to a structure with coefficients, roots and amount of roots
///@see struct Equation, solve_quadratic_case(), solve_linear_case()
void solve_quadratic(struct Equation *equation);

///Function solves quadratic equation
///
///Function changes variables x1, x2 and num_of_roots 
///@param equation - pointer to a structure with coefficients, roots and amount of roots
///@see struct Equation, solve_quadratic()
void solve_quadratic_case(struct Equation *equation);


///Function solves linear equation
///
///Function changes variables x1 and num_of_roots 
///@param equation - pointer to a structure with coefficients, roots and amount of roots
///@see struct Equation, solve_case()
void solve_linear_case(struct Equation* equation);





void input_of_args(struct Equation* equation);

///Function shows the results of solving the equation
///
///Function prints the number of roots of the equation and their values if they exist 
///@param equation - pointer to a structure with coefficients, roots and amount of roots
///@see struct Equation
void show_args(struct Equation* equation);
