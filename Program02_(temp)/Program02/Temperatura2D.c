#include <stdio.h>
/*
	Program wypisuje zestawienie temperatur w skali Fahrenheita i Celsjusza wg wzoru: C= (5/9)*(F-32).
	wersja z petla for
*/

int main()
{
const int	dolna = 0,	// dolna granica Fahr.
		gorna = 300,	// gorna granica Fahr.
		krok = 20;	// krok stopni w skali Fahr.

float 		fahr; // temperatura Fahrenheita

	printf("\nProgram wypisuje zestawienie temperatur w skali Fahrenheita i Celsjusza, przeliczajac je wg wzoru ");
	printf("C = (5/9)*(F-32)\n");
	printf("J. Goc\t 07.03.2023\n\n");
	for (fahr = dolna; fahr <= gorna; fahr += krok) 
		printf("F = %3.0f \t C = %6.1f\n",fahr,5.0/9*(fahr - 32));
} 
