#include <stdio.h>

/*
	Program wypisuje zestawienie temperatur w skali Fahrenheita i Celsjusza wg wzoru: C= (5/9)*(F-32).
*/
int main()
{
float 	dolna = 0, // dolna granica temp. Fahr.
	gorna = 300, // gorna granica temp. Fahr.
	krok = 20, // co ile stopni w skali Fahr.
	fahr, celsius; // temperatury Fahr. i Cels.
	fahr = dolna;
while (fahr <= gorna) {
		celsius = 5.0/9.0*(fahr-32.0);
		printf("%3.0f%6.1f\n",fahr,celsius);
		fahr = fahr + krok;
} // koniec while
} 
