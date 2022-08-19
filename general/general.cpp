#include "general.h"
 
void  input_cleaner(void)
{
    while (getchar() != '\n') {;}
}

//------------------------------------------------------------------

double zero_abs(double value)
{
    return (isequal(value, 0)) ? fabs(value) : value;
}

//------------------------------------------------------------------
