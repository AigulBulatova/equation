#include <stdio.h>
#include <math.h>
#include "equation/equation.h"
#include "equation_conf.h"

#ifdef TESTING
#include "test/test.h"
#endif 

int main () 
{
#ifdef TESTING
    int test_return = test_run();
    
    if (test_return) {
        return test_return;
    }
#endif 

    Equation equation = {};
    equation_init(&equation);

    int answer = CONTINUE_SOLVING;
    while (answer == CONTINUE_SOLVING) {
        input_of_args(&equation);

        int solve_ret = solve_quadratic(&equation);
        if (solve_ret) {
            return solve_ret;
        }  

        int show_ret = show_results(&equation);
        if (show_ret) {
            return show_ret;
        }

        answer = user_menu();
    }

    return 0;
}
 