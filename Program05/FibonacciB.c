#include <stdio.h>

/* Obliczanie ciagu Fibonacciego - metoda rekurencyjna */

int fbn_r(int n)
{
    int k;
    if (k < n)
        return k+fbn_r(n+1);
    else
        return 1;
}

int main()
{
    int n;
    printf("Obliczanie ciagu Fibonacciego metoda rekurencyjna\n");
    printf("Podaj liczbe naturalna n: ");
    scanf("%u",&n);
    printf("%u\n",fbn_r(n)); // wypisanie wyniku funkcji - odpowiedniej liczby Fn
}