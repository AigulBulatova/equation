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

    struct Equation equation;
    struct_initial(&equation);

    int ans = YES;
    while (ans == YES) {
        input_of_args(&equation);

        solve_quadratic(&equation);
        show_args(&equation);

        ans = user_interface();
    }

}
 