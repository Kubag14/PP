
#include <stdio.h>

/*
	Program wypisuje zestawienie temperatur w skali Fahrenheita i Celsjusza wg wzoru: C= (5/9)*(F-32).
	wersja z petla for
*/
int main()
{
	int 	dolna = 0, // dolna granica temp. Fahr.
		gorna = 300, // gorna granica temp. Fahr.
		krok = 20; // co ile stopni w skali Fahr.

	float	fahr; // temperatura Fahr.
		fahr = dolna;

for (fahr = dolna; fahr <= gorna; fahr += krok) 
		printf("%3.0f\t%6.1f\n",fahr,5.0/9*(fahr - 32));
} 
