# Equation solver
This program can solve quadratic equations of the form ```a * x^2 + b * x + c = 0```

# Installation
If you want to install this program:
* Download files or clone this repository:
    * ``` git clone https://github.com/AigulBulatova/equation.git ```
* Build the program
   * ```cd equation/```
   * ```make```
  
# Usage
* Run the program:
    * ```./solve```
* Enter coefficients `a`, `b`, `c` of the equation separated by spaces
* If input is incorrect, program will allow you to repeat
* Program will show you roots of equation
* Press 1 to continue with new equation or 2 to stop
  
## Testing and debugging
This project includes testing that checks if the program works correctly and shows the test results to the user.

If you want to turn on the testing, go to [equation_conf.h](https://github.com/AigulBulatova/equation/blob/master/configs/equation_conf.h) and  define TESTING by uncomment  ```//#define TESTING```
___

The project also includes debugging that displays basic calculations and entered data to the user

If you want to turn on debugging of the program, uncomment ```//#define DEBUG``` in  [equation_conf.h](https://github.com/AigulBulatova/equation/blob/master/configs/equation_conf.h)

```
//#define TESTING

//#define DEBUG 
```
## Documentation
If you want to create documentation for this project:
* make sure that the ```doxygen``` installed
* generate documentation:
    * ```doxygen Doxyfile```
* documentation will be at html files

