#ifndef GENERAL_H
#define GENERAL_H

#include <stdio.h>
#include <math.h>

///@file general.h contains function declarations for isequal, input_cleaner and zero_abs

///A constant used to compare two double values 
///
///@see isequal()
#define EPS 1e-6 

///Function compares two double values
/// 
///@param num1 - first double value to compare
///@param num2 - second double value to compare 
///@returns 1 if num1 and num2 are equal and 0 if they aren't
static inline int isequal(double num1, double num2)
{
    return (fabs(num1 - num2) <= EPS);
} 

///Function cleans input
///
///This function used to clear the input buffer to a '\n' symbol
void  input_cleaner(void);

///Function turns "-0" to "0"
///
///@param value - floating point number
///@returns 0 if value -s equal to 0 or value if it does not
double zero_abs(double value);
#endif
 