#ifndef COLORED_OUTPUT_H
#define COLORED_OUTPUT_H

///@file colored_output.h contains ANSI codes for color definitions and declaration of colored printing function

#define RESET   "\033[0m"
#define RED     "\033[31m"     
#define GREEN   "\033[32m"     

///Colored output
///
///This function colors text in console
///@param color - color in which the text is colored
///@param str - format line to be printed
void colored_print(const char *color, const char *format, ...);
#endif