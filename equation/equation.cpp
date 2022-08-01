#include <assert.h>
#include "equation.h"
#include "../general/general.h"
 
//------------------------------------------------------------------

void input_of_args(Equation* equation)
{
    assert (equation != NULL);

    printf("Please enter the coefficients a, b and c of the equation"
            " a * x^2 + b * x + c = 0 in the form \"a b c\"\n");

    while (true) {
        if (scanf("%lf %lf %lf", &(equation->a), &(equation->b), &(equation->c)) != 3) {
            printf("Incorrect coefficient entry. Try again\n");
            input_cleaner();
        }
        else {
            break;
        }
    }

    return;
}

//------------------------------------------------------------------

int user_menu(void) {
    int answer = NOT_STATED;

    printf("\nDo you want to repeat?\n1.YES.\n2.NO.\n");

    while (true) {
        if(scanf("%d", &answer) != 1 || (answer != YES && answer != NO)) {
            printf("Please, try again. Press 1 to repeat or 2 to stop.\n");
            input_cleaner();
        }
        else {
            break;
        }
    }
    return answer;
}

//------------------------------------------------------------------

void show_args(Equation* equation)
{
    assert (equation != NULL);

    switch(equation->num_of_roots) {
        case NO_ROOTS: {
            printf("The equation has no roots.\n");
            break;
        }
        case ONE_ROOT: {
            printf("The equation has one root. x = %.2lf.\n", equation->x1);
            break;
        }
        case TWO_ROOTS: {
            printf("The equation has two roots. x1 = %.2lf, x2 = %.2lf.\n",
                    equation->x1, equation->x2);
            break;
        }
        case INF_ROOTS: {
            printf("The equation has an infinite number of roots.\n");
            break;
        }
        default: {
            printf("Unexpected amount of roots.\n");
        }
    }

    return;
}

//------------------------------------------------------------------

int solve_linear_case(Equation* equation)
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

    return 0;
}

//------------------------------------------------------------------

int solve_quadratic_case(Equation *equation)
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

    return 0;
}

//------------------------------------------------------------------

int solve_quadratic(Equation *equation)
{
    assert (equation != NULL);

    if (isequal(equation->a, 0)) {
        return solve_linear_case(equation);
    }
    else {
        return solve_quadratic_case(equation);
    }

    return 0;
}

//------------------------------------------------------------------

void equation_init (Equation *equation)
{
    assert (equation != NULL);

    equation->a = NAN;
    equation->b = NAN;
    equation->c = NAN;
    equation->x1 = NAN;
    equation->x2 = NAN;
    equation->num_of_roots = NO_ROOTS;

    return;
}



