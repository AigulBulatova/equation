#include <stdio.h>
#include <math.h>

#include "functions.h"
void input(struct Equation* equation)
{
    printf("Please enter the coefficients a, b and c of the equation a * x^2 + b * x + c = 0 in the form \"a b c\"\n");
    printf("Press Tab if you want to exit\n");

    while (scanf("%lf %lf %lf", &(equation->a), &(equation->b), &(equation->c)) != 3) {
         if (getchar() == '\t') {
        //????????????
        }
        printf("Incorrect coefficient entry. Try again\n");
    }
}

void output(struct Equation* equation, int num_of_roots)
{
    switch (num_of_roots) {
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
            printf("Something strange.\n")
    }
}

int solve_linear(struct Equation* equation)
{
    double b = equation->b;
    double c = equation->c;

    if (isequal(b, 0)) {
        if (isequal(c, 0)) {
            return INF_ROOTS;
        }
        else {
            return NO_ROOTS;
        }
    }
    else {
        equation->x1 = - c / b;
        return ONE_ROOT;
    }

}

int solve_quadratic(struct Equation *equation)
{
    double a = equation->a;
    double b = equation->b;
    double c = equation->c;

    double discr = b * b - 4 * a * c;

    if (isequal(discr, 0)) {
        equation->x1 = - b / (2 * a);
        return ONE_ROOT;
    }
    else if (discr < 0) {
        return NO_ROOTS;
    }
    else  {
        equation->x1 = ( - b + sqrt(discr)) / (2 * a);
        equation->x2 = ( - b - sqrt(discr)) / (2 * a);
        return TWO_ROOTS;
    }

}

int solve(struct Equation *equation)
{
    int roots_num;

    if (isequal(equation->a, 0)) 
        roots_num = linear(equation);
    else 
        roots_num = quadratic(equation);

    return roots_num;
}

int isequal(double num1, double num2)
{
    return (fabs(num1 - num2) <= EPS);
}

void struct_init(struct Equation *equation)
{
    equation->a = NAN;
    equation->b = NAN;
    equation->c = NAN;
    equation->x1 = NAN
    equation->x2 = NAN;
}

