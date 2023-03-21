#include <stdio.h>
#include <math.h>

/*
	Obliczanie pierwiastkow rownania kwadratowego:
		a*x^2 + b*x + c = 0.
*/

int main() {
        double a, b, c;    // wspolczynniki rown. kwadr.
        double Delta, x0, x1, x2; // wyroznik i pierwiastki rown. kwadr.
        char tn[2];
        char sb = 0;
        char sc = 0;

    void rKwad(double a,double b,double c) // definicja funkcji rKwad
    {
        double Delta,x0,x1,x2;
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
    }

        printf("Pierwiastki rownania kwadratowego: ");
        printf("a*x^2 + b*x + c = 0.\n");
        do {
            do { // petla do, bedzie sie powtarzac poki a nie bedzie rozne od zera
            printf("Podaj wspolczynnik a rozny od 0: "); // wczytanie wspolczynnikow
            scanf("%lf", &a);
            } while (a == 0);
        printf("Podaj wspolczynnik b: ");
        scanf("%lf", &b);
        printf("Podaj wspolczynnik c: ");
        scanf("%lf", &c);

            if (b > 0.0)  // jesli b > 0.0 to znak b (sb) = +
                sb = '+';
            else
                sb = '-';
            if (c > 0.0)  // jesli c > 0.0 to znak c (sc) = +
                sc = '+' ;
            else
                sc = '-';
            printf("%gx^2 %c%gx %c%g = 0\n",a,sb,fabs(b),sc,fabs(c)); // wyswietlenie postaci rownania

        rKwad(a, b, c); // wywolanie funkcji rKwad argumentami a,b,c
        printf("Czy chcesz kontynuowac? [t/n]\n: ");
        scanf("%1s", tn);
        }
        while (tn[0] == 't'); // jesli uzytkownik odpowie "t", to petla sie powtorzy
}

