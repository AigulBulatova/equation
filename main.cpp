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
    test_run();
#endif 

    Equation equation = {};
    equation_init(&equation);

    int answer = YES;
    while (answer == YES) {
        input_of_args(&equation);

        solve_quadratic(&equation);
        show_args(&equation);

        answer = user_menu();
    }

    return 0;
}
 