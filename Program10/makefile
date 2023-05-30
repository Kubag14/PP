TypZespolone.o: TypZespolone.c
	gcc -Wall -pedantic -c TypZespolone.c -lm

zespolone.o: zespolone.c
	gcc -Wall -std=c99 -pedantic -c zespolone.c -lm

zespolone.x: zespolone.o TypZespolone.o
	gcc -Wall -std=c99 -pedantic -o zespolone.x zespolone.o TypZespolone.o -lm

