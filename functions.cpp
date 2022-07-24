#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "functions.h"

//------------------------------------------------------------------
void input_of_args(struct Equation* equation)
{
    assert (equation != NULL);

    printf("Please enter the coefficients a, b and c of the equation"
            " a * x^2 + b * x + c = 0 in the form \"a b c\"\n");

    int input = scanf("%lf %lf %lf", &(equation->a), &(equation->b), &(equation->c));
    while (input != 3) {
        printf("Incorrect coefficient entry. Try again\n");
    }
}

//------------------------------------------------------------------

void show_args(struct Equation* equation)
{
    assert (equation != NULL);

    switch(equation->num_of_roots) {
        case NO_ROOTS:
            printf("The equation has no roots.\n");
            break;
        case ONE_ROOT:
            printf("The equation has one root. x = %lf.\n", equation->x1);
            break;
        case TWO_ROOTS:
            printf("The equation has two roots. x1 = %lf, x2 = %lf.\n", equation->x1, equation->x2);
            break;
        case INF_ROOTS:
            printf("The equation has an infinite number of roots.\n");
            break;
        case default:
            printf("Unexpected amount of roots.\n");
    }
}

//------------------------------------------------------------------

void solve_linear_case(struct Equation* equation)
{
    assert(equation != NULL);

    double b = equation->b;
    double c = equation->c;

    if (isequal(b, 0)) {
        if (isequal(c, 0)) {
            equation->num_of_roots = INF_ROOTS;
        }
        else {
            equation->num_of_roots = NO_ROOTS;
        }
    }
    else {
        equation->x1 = - c / b;
        equation->num_of_roots = ONE_ROOT;
    }

}

//------------------------------------------------------------------

void solve_quadratic_case(struct Equation *equation)
{
    assert (equation != NULL);

    double a = equation->a;
    double b = equation->b;
    double c = equation->c;

    double discr = b * b - 4 * a * c;

    if (isequal(discr, 0)) {
        equation->x1 = - b / (2 * a);
        equation->num_of_roots =  ONE_ROOT;
    }
    else if (discr < 0) {
        equation->num_of_roots =  NO_ROOTS;
    }
    else  {
        equation->x1 = ( - b + sqrt(discr)) / (2 * a);
        equation->x2 = ( - b - sqrt(discr)) / (2 * a);
        equation->num_of_roots =  TWO_ROOTS;
    }

}

//------------------------------------------------------------------

void solve_quadratic(struct Equation *equation)
{
    assert (equation != NULL);

    if (isequal(equation->a, 0)) 
        solve_linear_case(equation);
    else 
        solve_quadratic_case(equation);

}



