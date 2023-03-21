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
		celsius = 5.0/9*(fahr-32);
		printf("%f\t%f\n",fahr,celsius); // output bedzie typu float, wiec f
		fahr = fahr + krok;
} // koniec while
} 
