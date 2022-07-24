#include <stdio.h>
#include <math.h>



struct Equation  test[] = 
{.a = 0, .b = 0, .c = 0, .x1 = NAN, .x2 = NAN},
{.a = 1, .b = 2, .c = 1, .x1 = -1, .x2 = NAN},
{.a = 1, .b = 3, .c = -4, .x1 = -4, .x2 = 1},
{.a = 0, .b = 0, .c = 1, .x1 = NAN, .x2 = NAN},
{.a = 0, .b = 5, .c = -1, .x1 = 0.2, .x2 = NAN},
{.a = 3, .b = 1, .c = 2, .x1 = NAN, .x2 = NAN},
{.a = 0, .b = 5, .c = 0, .x1 = 0, .x2 = NAN};


int roots_true [] = {INF_ROOTS, ONE_ROOT, TWO_ROOTS, NO_ROOTS, ONE_ROOT, NO_ROOTS, ONE_ROOT};

int test_solve (struct Equation test[], int roots_true[])
{
    int i, mistakes; 
    struct Equation testing;
    int roots_num;
    for (i = 0; i <= 6, i++) {

        testing.a = test[i].a;
        testing.b = test[i].b;
        testing.c = test[i].c;

        roots_num = solve(&testing)
        if(solve(&testing) != roots_true[i] || !(isequal(testing.x1, test[i].x1)) || !(isequal(testing.x2, test[i].x2))) {
            printf("Test number %d failed. x1 = %lf (expected value %lf), x2 = %lf (expected value %lf).\n", i, testing.x1, test[i].x1, testing.x2, test[i].x2);
            mistakes++;
        }
    }
    return mistakes;
}