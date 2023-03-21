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

	float fahr; // temperatura Fahrenheita

	for (fahr = dolna; fahr <= gorna; fahr += krok) {
		printf("%3.0f%6.1f\n",fahr,5.0/9*(fahr - 32));
		gorna = 310;
	}
}
