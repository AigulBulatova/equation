#include <stdio.h>
#include <math.h>
#include "equation/equation.h"

#define TESTING
#ifdef TESTING
#include "test/test.h"
#endif 

int main ()
{
    
#ifdef TESTING
    int test_return = test_run();
    
    if(test_return) {
        return test_return;
    }
#endif 

    Equation equation = {};
    equation_init(&equation);

    int answer = YES;
    while (answer == YES) {
        input_of_args(&equation);

        int solve_ret = solve_quadratic(&equation);

        if (solve_ret) {
            return solve_ret;
        }  

        show_args(&equation);

        answer = user_menu();
    }

    return 0;
}
 