FLAGS = -lubsan -D NDEBUG -g -std=c++14 -fmax-errors=1 			  	\
		-Wc++0x-compat -Wc++11-compat -Wc++14-compat  				\
		-Wcast-qual -Wchar-subscripts -Wconditionally-supported 	\
		-Wconversion  -Wctor-dtor-privacy -Wempty-body 				\
		-Wfloat-equal -Wformat-nonliteral -Wformat-security 		\
		-Wformat-signedness -Wformat=2 -Winline  -Wlogical-op 		\
		-Wmissing-declarations  -Wnon-virtual-dtor -Wopenmp-simd	\
		-Woverloaded-virtual -Wpacked -Wpointer-arith 				\
		-Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo	\
		-Wstack-usage=8192  -Wstrict-null-sentinel 					\
		-Wstrict-overflow=2 -Wsuggest-attribute=noreturn 			\
		-Wsuggest-final-methods -Wsuggest-final-types  				\
		-Wsuggest-override -Wswitch-default -Wswitch-enum 			\
		-Wsync-nand -Wundef  -Wunreachable-code -Wunused 			\
		-Wuseless-cast -Wvariadic-macros -Wno-literal-suffix 		\
		-Wno-missing-field-initializers -Wno-narrowing				\
		-Wno-old-style-cast -Wno-varargs -fcheck-new 				\
		-fsized-deallocation  -fstack-protector 					\
		-fstrict-overflow   -flto-odr-type-merging 					\
		-fno-omit-frame-pointer -fPIE -fsanitize=address  			\
		-fsanitize=bool -fsanitize=bounds -fsanitize=enum  			\
		-fsanitize=float-cast-overflow 								\
		-fsanitize=float-divide-by-zero 							\
		-fsanitize=integer-divide-by-zero -fsanitize=leak 			\
		-fsanitize=nonnull-attribute -fsanitize=null 				\
		-fsanitize=object-size -fsanitize=return 					\
		-fsanitize=returns-nonnull-attribute -fsanitize=shift 		\
		-fsanitize=signed-integer-overflow -fsanitize=undefined 	\
		-fsanitize=unreachable -fsanitize=vla-bound 				\


all: global

global: main.o equation.o general.o test.o
	gcc main.o equation.o general.o test.o -o equation -lm $(FLAGS)

main.o: main.cpp equation.h test.h
	gcc -c main.cpp	$(FLAGS)

equation.o: equation.cpp equation.h general.h
	gcc -c equation.cpp $(FLAGS)

general.o: general.cpp general.h
	gcc -c general.cpp $(FLAGS)

test.o: test.cpp test.h equation.h 
	gcc -c test.cpp $(FLAGS)

cleanup:
	rm -rm *.0 equation