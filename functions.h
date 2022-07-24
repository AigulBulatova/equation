#include <stdio.h>

#define EPS 1e-6 


enum num_of_roots {
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
}; 

/*Function solves equation
It takes as a parameter a pointer to a structuree with coefficients and roots of equation
The function calls solve_quadratic and solve_linear and returns number of roots
*/
int solve(struct Equation *equation);

/*Function solves quadratic equation
It takes as a parameter a pointer to a structure with coefficients and roots of equation
Function returns number of roots
*/
int solve_quadratic(struct Equation *equation);


/*Function solves linear equation 
It takes as a parameter a pointer to a structure with coefficients and roots of equation
Function returns number of roots
*/
int solve_linear(struct Equation* equation);

/*Function compares two double values
It takes as parameters double values num1 and num2
Function returns 1 if num1 and num2 are equal and 0 if they aren't
*/
int isequal(double num1, double num2);



void input(struct Equation* equation);

/*Function shows the results of solving the equation
It takes as a parameter a pointer to a structure with coefficients and roots of equation and a number of roots
Function prints the number of roots of the equation and their values if they exist 
*/
void output(struct Equation* equation, int num_of_roots);
