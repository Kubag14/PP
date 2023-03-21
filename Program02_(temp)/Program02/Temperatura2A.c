#include <stdio.h>
/*
	Program wypisuje zestawienie temperatur w skali Fahrenheita i Celsjusza wg wzoru: C= (5/9)*(F-32).
	wersja z petla for
*/

//stale jawne

#define DOLNA 0		// dolna granica Fahr.
#define GORNA 300	// gorna granica Fahr.
#define KROK 20		// krok stopni w skali Fahr.

//program
int main()
{
	float fahr; // temperatura Fahrenheita

	for (fahr = DOLNA; fahr <= GORNA; fahr += KROK) 
		printf("%3.0f\t%6.1f\n",fahr,5.0/9*(fahr - 32));
} 
