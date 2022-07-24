#include <stdio.h>
#include <math.h>



static struct Equation  test[] = 
{.a = 0, .b = 0, .c = 0,  .x1 = NAN, .x2 = NAN, num_of_roots = NAN},
{.a = 1, .b = 2, .c = 1,  .x1 = NAN, .x2 = NAN, num_of_roots = NAN},
{.a = 1, .b = 3, .c = -4, .x1 = NAN, .x2 = NAN, num_of_roots = NAN},
{.a = 0, .b = 0, .c = 1,  .x1 = NAN, .x2 = NAN, num_of_roots = NAN},
{.a = 0, .b = 5, .c = -1, .x1 = NAN, .x2 = NAN, num_of_roots = NAN},
{.a = 3, .b = 1, .c = 2,  .x1 = NAN, .x2 = NAN, num_of_roots = NAN},
{.a = 0, .b = 5, .c = 0,  .x1 = NAN, .x2 = NAN, num_of_roots = NAN};

static struct Equation  answers[] = 
{.x1 = NAN, .x2 = NAN, num_of_roots = INF_ROOTS},
{.x1 = -1,  .x2 = NAN, num_of_roots = ONE_ROOT},
{.x1 = -4,  .x2 = 1,   num_of_roots = TWO_ROOTS},
{.x1 = NAN, .x2 = NAN, num_of_roots = NO_ROOTS},
{.x1 = 0.2, .x2 = NAN, num_of_roots = ONE_ROOT},
{.x1 = NAN, .x2 = NAN, num_of_roots = NO_ROOTS},
{.x1 = 0,   .x2 = NAN, num_of_roots = ONE_ROOT};


int test_solve (struct Equation test[], const struct Equation answers[], int size)
{
    int num_of_test;
    
    for(num_of_test = 0; num_of_test <= size; num_of_test++) {
        solve_quadratic(&test[num_of_test]);

        int x1_comp = answers[num_of_test].x1 != test[num_of_test].x1;
        int x2_comp = answers[num_of_test].x2 != test[num_of_test].x2;
        int roots_comp = answers[num_of_test].num_of_roots != test[num_of_test].num_of_roots;

        if (x1_comp || x2_comp || roots_comp) {
                mistakes++;
                printf("Test number %d failed.\n", num_of_test);
            }
        
        if (x1_comp) {
            printf("Received value for x1 %lf instead of %lf\n", test[num_of_test].x1, answers[num_of_test].x1);
        }

        if (x2_comp) {
            printf("Received value for x2 %lf instead of %lf\n", test[num_of_test].x2, answers[num_of_test].x2);
        }

        if (roots_comp) {
            printf("Received number of roots: ");
            root_cases_print(test[num_of_test].num_of_roots);
            printf(". Expected number of roots: ");
            root_cases_print(answers[num_of_test].num_of_roots);
            printf("\n");
        }
    }
    return mistakes;
}

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
            printf("Error:unexpected number of roots.");
        }
    }
}