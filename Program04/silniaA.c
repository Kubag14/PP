#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Program do obliczania n! metoda iteracyjna */

unsigned silnia_i1(unsigned n) // unsigned - 16 bitow
{
    unsigned i,iloczyn;

    for (i = iloczyn = 1; i <= n; ++i) // petla bedzie sie powtarzac do i=n, za kazdym razem ustalajac i = i + 1
        iloczyn *= i;
    return iloczyn;
}
unsigned long silnia_i2(unsigned n) // unsigned long ma 32 bity
{
    unsigned long i, iloczyn;

    for (i = iloczyn = 1; i <= n; ++i)
        iloczyn *= i;
    return iloczyn;
}
double silnia_i3(unsigned n) // double - zazwyczaj 64 bity
{
    double i,iloczyn;

    for (i = iloczyn = 1; i <= n; ++i)
        iloczyn *= i;
    return iloczyn;
}
int main()
{
    unsigned n;
    printf("Obliczanie n! metoda iteracyjna\n");
    printf("Podaj liczbe naturalna n: ");
    scanf("%u",&n);
    printf("%u! = %u\n",n,silnia_i1(n)); // wywolanie wszystkich trzech funkcji i wyswietlenie ich wynikow
    printf("%u! = %lu\n",n,silnia_i2(n));
    printf("%u! = %f\n",n,silnia_i3(n));

    printf("Max unsigned = %u\n",UINT_MAX); // wypisanie wartosci UINT.MAX - maksymalna wartosc dla typu unsigned
    printf("Max unsigned long = %lu\n",ULONG_MAX); // wypisanie wartosci ULONG.MAX - maksymalna wartosc dla typu unsigned long
    printf("Max double = %g\n",DBL_MAX); // wypisanie wartosci DBL.MAX - maksymalna wartosc dla typu double
}