#include <stdio.h>

/* Obliczanie ciagu Fibonacciego - metoda rekurencyjna */

long int fbn_r(int n)
{
    if (n >= 3)
        return fbn_r(n-2)+fbn_r(n-1);
    else
        return 1;
}

int main()
{
    int n;
    printf("Obliczanie ciagu Fibonacciego metoda rekurencyjna\n");
    printf("Podaj liczbe naturalna n: ");
    scanf("%u",&n);
    printf("%li\n",fbn_r(n)); // wypisanie wyniku funkcji - odpowiedniej liczby Fn
}