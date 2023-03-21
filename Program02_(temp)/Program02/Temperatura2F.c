#include <stdio.h>
/*
	Program wypisuje zestawienie temperatur w skali Celsjusza i Fahrenheita wg wzoru: F = C*(9/5) + 32.
	wersja z petla for
*/

int main()
{
const int	dolna = 0,	// dolna granica Cels.
		gorna = 150,	// gorna granica Cels.
		krok = 10;	// krok stopni w skali Cels.

int 		cels; // temperatura Celsjusza

	printf("\nProgram wypisuje zestawienie temperatur w skali Celsjusza i Fahrenheita, przeliczajac je wg wzoru ");
	printf("F = (9/5)*C + 32\n");
	printf("J. Goc\t 07.03.2023\n\n");
	for (cels = dolna; cels <= gorna; cels += krok) 
		printf("C = %3d \t F = %6.1f\n",cels,(9/5.0*cels) + 32);
} 
