#include <stdio.h>
int fbn_i(int n)
{ unsigned i;
    int a = 0, b = 1, c = 1;
    for (i = 0; i < (n - 1); ++i) {
        c = a + b;
        a = b;
        b = c;
        }
        return c;
}
int main()
{
    unsigned n;
    printf("Obliczanie ciagu Fibonacciego metoda iteracyjna\n");
    printf("Podaj liczbe naturalna n: ");
    scanf("%u",&n);
    printf("%u\n",fbn_i(n));
}