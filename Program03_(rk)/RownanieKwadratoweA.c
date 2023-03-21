#include <stdio.h>
#include <math.h>

/*
	Obliczanie pierwiastkow rownania kwadratowego:
		a*x^2 + b*x + c = 0.

*/
int main()
{
	double a,b,c;	// wspolczynniki rown. kwadr.
	double Delta,x0,x1,x2; // wyroznik i pierwiastki rown. kwadr.
	char tn[2];

	printf("Pierwiastki rownania kwadratowego: ");
	printf("a*x^2 + b*x + c = 0.\n");
do {
	printf("Podaj Wspolczynniki a, b, c: ");
	scanf("%lf%lf%lf",&a,&b,&c);
	Delta = (b*b - 4*a*c); // wyroznik rown. kwadr. (delta)
	if (Delta > 0.0) { // warunek na dwa pierwiastki rown. kwadr.
		x1 = -(b + sqrt(Delta))/2/a;
		x2 = -(b - sqrt(Delta))/2/a;
		printf("Dwa pierwiastki: x1 = %lf, x2 = %lf\n",x1,x2);
	} else if (Delta == 0.0) { // Delta = 0 - jeden pierwiastek
		x0 = -b/2/a;
		printf("Jeden pierwiastek podwojny: x0 = %lf\n",x0);
	} else // niespelniony warunek delta > 0 lub delta = 0 --> brak pierwiastkow
		printf("Brak pierwiastkow: Delta = %lf\n",Delta);
	printf("Czy chcesz kontynuowac? [t/n]\n: ");
	scanf("%1s",tn); // jesli uzytkownik odpowie "t", to petla sie powtorzy
}
while (tn[0] == 't');
}
