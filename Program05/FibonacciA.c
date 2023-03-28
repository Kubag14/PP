#include <stdio.h>

/* Obliczanie ciagu Fibonacciego - metoda iteracyjna */

int fbn_i(int n)
{ unsigned i;
    int a = 0, b = 1, c = 1; // wartosci poczatkowe (rownoczesnie trzy pierwsze wyrazy ciagu
    for (i = 0; i < (n - 1); ++i) { // petla powtarza sie, poki i jest mniejsze od n - 1, gdzie n jest numerem liczby w ciagu
        c = a + b; // F3 = F1 + F2
        a = b; // F1 = F2
        b = c; // F2 = F3
        }
        return c;
}
int main()
{
    int n;
    printf("Obliczanie ciagu Fibonacciego metoda iteracyjna\n");
    printf("Podaj liczbe naturalna n: ");
    scanf("%u",&n);
    printf("%u\n",fbn_i(n)); // wypisanie wyniku funkcji - odpowiedniej liczby Fn
}