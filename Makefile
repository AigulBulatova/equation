all: global

global: main.o equation.o general.o test.o
	gcc main.o equation.o general.o test.o -o equation

main.o: main.cpp equation.h test.h
	gcc -c main.cpp

equation.o: equation.cpp equation.h general.h
	gcc -c equation.cpp 

general.o: general.cpp general.h
	gcc -c general.cpp

test.o: test.cpp test.h equation.h 
	gcc -c test.cpp

cleanup:
	rm -rm *.0 equation