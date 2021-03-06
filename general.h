#pragma once

#include <stdio.h>

///A constant used to compare two double values
///
///@see isequal()
#define EPS 1e-6 

///Function compares two double values
/// 
///@param num1 - first double value to compare
///@param num2 - second double value to compare 
///@returns 1 if num1 and num2 are equal and 0 if they aren't
inline int isequal(double num1, double num2);

 