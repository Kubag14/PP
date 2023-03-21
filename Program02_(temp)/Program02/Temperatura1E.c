#include <stdio.h>

/*
	Program wypisuje zestawienie temperatur w skali Fahrenheita i Celsjusza wg wzoru: C= (5/9)*(F-32).
*/
int main()
{
int 	dolna = 0, // dolna granica temp. Fahr.
	gorna = 300, // gorna granica temp. Fahr.
	krok = 20, // co ile stopni w skali Fahr.
	fahr, celsius; // temperatury Fahr. i Cels.
	fahr = dolna;
while (fahr <= gorna) {
		celsius = 5*(fahr-32)/9;
		printf("%d\t%d\n",fahr,celsius);
		fahr += krok; // da taki sam efekt, jak fahr = fahr + krok
} // koniec while
} 
