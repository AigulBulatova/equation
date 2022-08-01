#include <math.h>
#include "test.h"
#include "../equation/equation.h"
#include "../general/general.h"

//-----------------------------------------------------------------

void test_run(void)
{

    Equation  test[] = {
    {.a = 0, .b = 0, .c = 0,  .x1 = NAN, .x2 = NAN, .num_of_roots = NO_ROOTS},
    {.a = 1, .b = 2, .c = 1,  .x1 = NAN, .x2 = NAN, .num_of_roots = NO_ROOTS},
    {.a = 1, .b = 3, .c = -4, .x1 = NAN, .x2 = NAN, .num_of_roots = NO_ROOTS},
    {.a = 0, .b = 0, .c = 1,  .x1 = NAN, .x2 = NAN, .num_of_roots = NO_ROOTS},
    {.a = 0, .b = 5, .c = -1, .x1 = NAN, .x2 = NAN, .num_of_roots = NO_ROOTS},
    {.a = 3, .b = 1, .c = 2,  .x1 = NAN, .x2 = NAN, .num_of_roots = NO_ROOTS},
    {.a = 0, .b = 5, .c = 0,  .x1 = NAN, .x2 = NAN, .num_of_roots = NO_ROOTS}
    };

    Equation  answers[] = {
    {.x1 = NAN, .x2 = NAN, .num_of_roots = INF_ROOTS},
    {.x1 = -1,  .x2 = NAN, .num_of_roots = ONE_ROOT},
    {.x1 = 1,  .x2 = -4,   .num_of_roots = TWO_ROOTS},
    {.x1 = NAN, .x2 = NAN, .num_of_roots = NO_ROOTS},
    {.x1 = 0.2, .x2 = NAN, .num_of_roots = ONE_ROOT},
    {.x1 = NAN, .x2 = NAN, .num_of_roots = NO_ROOTS},
    {.x1 = 0,   .x2 = NAN, .num_of_roots = ONE_ROOT}
    };


    int failed_tests = test_solve(test, answers, sizeof (test) / sizeof (test[0]));
    test_show(failed_tests);

} 

//------------------------------------------------------------------

int test_solve (Equation test[], const Equation answers[], int size)
{
    int failed_test = 0;
    int num_of_test;
    
    for(num_of_test = 0; num_of_test < size; num_of_test++) {
        solve_quadratic(&test[num_of_test]);

        int x1_comp = !root_compare(test[num_of_test].x1, answers[num_of_test].x1);
        int x2_comp = !root_compare(test[num_of_test].x2, answers[num_of_test].x2);
        int nroots_comp = answers[num_of_test].num_of_roots != test[num_of_test].num_of_roots;


        if (x1_comp || x2_comp || nroots_comp) {
            failed_test++;
            printf("Test number %d failed.\n", num_of_test + 1);
            }
        
        if (x1_comp) {
            printf("Received value for x1 %.2lf instead of %.2lf.\n",
                   test[num_of_test].x1, answers[num_of_test].x1);
        }

        if (x2_comp) {
            printf("Received value for x2 %.2lf instead of %.2lf.\n",
                   test[num_of_test].x2, answers[num_of_test].x2);
        }

        if (nroots_comp) {
            printf("Received number of roots: ");
            root_cases_print(test[num_of_test].num_of_roots);
            printf(". Expected number of roots: ");
            root_cases_print(answers[num_of_test].num_of_roots);
            printf(".\n");
        }
    }
    return failed_test;
}

//------------------------------------------------------------------

void test_show (int failed_test) 
{
    if (failed_test == 0) {
        printf("All tests complete succesfully.\n");
    }
    else {
        printf("Tests failed: %d\n", failed_test);
        exit(0);
    }
}

//------------------------------------------------------------------

void root_cases_print(int root_case)
{
    switch (root_case) {
        case NO_ROOTS: {
            printf("no roots");
            break;
        }
        case ONE_ROOT: {
            printf("one root");
            break;
        }
        case TWO_ROOTS: {
            printf("two roots");
            break;
        }
        case INF_ROOTS: {
            printf ("infinite number of roots");
            break;
        }
        default: {
            printf("Unexpected number of roots.");
        }
    }
}

//------------------------------------------------------------------

int root_compare(double x_test, double x_answers) 
{
    int comp = 0;
    if (isnan(x_answers) && isnan(x_test)) {
        comp = 1;
    } 
    else if ((isnan(x_answers) && !isnan(x_test)) 
            || (!isnan(x_answers) && isnan(x_test))) {
        comp = 0;
    }
    else {
        comp = isequal(x_answers, x_test);
    }

    return comp;
}