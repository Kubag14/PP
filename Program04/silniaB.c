#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Program do obliczania n! metoda rekurencyjna */

double silnia_r1(unsigned n) // funkcja z rekurencja
{
    if (n > 1) // warunek - n > 1
        return n*silnia_r1(n-1);  // jesli warunek spelniony - zwracamy n razy wynik funkcji dla n-1
    else
        return 1;
}
double silnia_r2(unsigned n)
{
    return (n > 1) ? n*silnia_r2(n-1) : 1; // jesli n>1 to zwracamy n razy wynik funkcji dla n-1
}
int main()
{
    unsigned n;
    printf("Obliczanie n! metoda iteracyjna\n");
    printf("Podaj liczbe naturalna n: ");
    scanf("%u",&n);
    printf("%u! = %f\n",n,silnia_r1(n)); // wywolanie obu funkcji i wyswietlenie ich wynikow
    printf("%u! = %f\n",n,silnia_r2(n));

    printf("Max unsigned = %u\n",UINT_MAX); // wypisanie wartosci UINT.MAX - maksymalna wartosc dla typu unsigned
    printf("Max unsigned long = %lu\n",ULONG_MAX); // wypisanie wartosci ULONG.MAX - maksymalna wartosc dla typu unsigned long
    printf("Max double = %g\n",DBL_MAX); // wypisanie wartosci DBL.MAX - maksymalna wartosc dla typu double
}