FunkcjeMacierzowe.o: FunkcjeMacierzowe.c
	gcc -Wall -std=c99 -pedantic -c FunkcjeMacierzowe.c

macierze.o: macierze.c
	gcc -Wall -std=c99 -pedantic -c macierze.c

macierze.x: macierze.o FunkcjeMacierzowe.o
	gcc -Wall -std=c99 -pedantic -o macierze.x macierze.o FunkcjeMacierzowe.o

