#include <stdio.h>

unsigned silnia_i1(unsigned n)
{
    unsigned i,iloczyn;

    for (i = iloczyn = 1; i <= n; ++i) // petla bedzie sie powtarzac do i=n, za kazdym razem ustalajac i = i + 1
        iloczyn *= i;
    return iloczyn;
}

/* Program do obliczania n! metoda iteracyjna */

int main()
{
    unsigned n;

    printf("Obliczanie n! metoda iteracyjna\n");
    printf("Podaj liczbe naturalna n: ");
    scanf("%u",&n);
    printf("%u! = %u\n",n,silnia_i1(n));
}