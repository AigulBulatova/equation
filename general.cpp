#include <general.h>

int isequal(double num1, double num2)
{
    return (fabs(num1 - num2) <= EPS);
} 