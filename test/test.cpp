#include <math.h>
#include "test.h"
#include "../equation/equation.h"
#include "../general/general.h"
#include "../equation_conf.h" 

//-----------------------------------------------------------------

int test_run(void)
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

    Answers  answers[] = {
    {.x1 = NAN, .x2 = NAN, .num_of_roots = INF_ROOTS},
    {.x1 = -1,  .x2 = NAN, .num_of_roots = ONE_ROOT},
    {.x1 = 1,   .x2 = -4,  .num_of_roots = TWO_ROOTS},
    {.x1 = NAN, .x2 = NAN, .num_of_roots = NO_ROOTS},
    {.x1 = 0.2, .x2 = NAN, .num_of_roots = ONE_ROOT},
    {.x1 = NAN, .x2 = NAN, .num_of_roots = NO_ROOTS},
    {.x1 = 0,   .x2 = NAN, .num_of_roots = ONE_ROOT}
    };

    int failed_tests = test_solve(test, answers, sizeof (test) / sizeof (test[0]));

    int show_return = test_show(failed_tests);
    if (show_return) {
        return show_return;
    }
    
    return 0;

} 

//------------------------------------------------------------------

int test_solve(Equation test[], const Answers answers[], int size)
{
    int failed_tests = 0;
    
    for (int num_of_test = 0; num_of_test < size; num_of_test++) {

        #ifdef DEBUG
            if (!isequal(test[num_of_test].a, 0)) {
                printf("Test number %d: ", num_of_test);
            }
        #endif
        solve_quadratic(&test[num_of_test]);


        int x1_comp = !root_compare(test[num_of_test].x1, answers[num_of_test].x1);
        int x2_comp = !root_compare(test[num_of_test].x2, answers[num_of_test].x2);
        int nroots_comp = answers[num_of_test].num_of_roots != test[num_of_test].num_of_roots;

        if (x1_comp || x2_comp || nroots_comp) {
            failed_tests++;
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
            int root_print = root_cases_print(test[num_of_test].num_of_roots);
            if (root_print) {
                return root_print;
            };

            printf(". Expected number of roots: ");
            root_print = root_cases_print(answers[num_of_test].num_of_roots);
            if (root_print) {
                return root_print;
            };
            printf(".\n");
        }
    }

    return failed_tests;
}

//------------------------------------------------------------------

int test_show(int failed_tests) 
{
    if (failed_tests == 0) {
        printf("All tests complete succesfully.\n");
    }
    else {
        printf("Tests failed: %d\n", failed_tests);
        exit(0);
    }

    return 0;
}

//------------------------------------------------------------------

int root_cases_print(int root_case)
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
            printf("infinite number of roots");
            break;
        }
        default: {
            printf("Unexpected number of roots.");
        }
    }

    return 0;
}

//------------------------------------------------------------------

int root_compare(double root_test, double root_answers) 
{
    int comp = 0;
    if (isnan(root_answers) && isnan(root_test)) {
        comp = 1;
    } 
    else if ((isnan(root_answers) && !isnan(root_test)) 
            || (!isnan(root_answers) && isnan(root_test))) {
        comp = 0;
    }
    else {
        comp = isequal(root_answers, root_test);
    }

    return comp;
}