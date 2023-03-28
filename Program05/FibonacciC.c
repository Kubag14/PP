#include <stdio.h>

/* Obliczanie ciagu Fibonacciego - metoda iteracyjna z tablica */

void fbn_i(int fibonacci[], unsigned n)
{ unsigned i;
    fibonacci[0] = 0, fibonacci[1] = 1, fibonacci[2] = 1;// wartosci poczatkowe (rownoczesnie trzy pierwsze wyrazy ciagu)
    for (i = 3; i < n; ++i) // petla powtarza sie, poki i jest mniejsze od n - 1, gdzie n jest numerem liczby w ciagu
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2]; // Fn = F(n-1) + F(n-2)
    }
}
int main()
{
    unsigned tmin,tmax;
    unsigned t;
    printf("Obliczanie ciagu Fibonacciego - metoda iteracyjna z tablica.\n");
    do {
        printf("Podaj rozmiar tablicy - liczbe naturalna t = ");
        scanf("%u", &t); // wczytanie rozmiaru tablicy t
    } while (t < 1);

    int fibonacci[t]; // definiujemy tablice o rozmiarze t
    fbn_i(fibonacci,t); // wywolanie funkcji, ktora wypelni tablice fibonacci o rozmiarze t
    printf("Rozmiar tablicy t = %u\n",t);

    do {
        printf("Podaj dwie liczby naturalne w formacie n, k (od, do; k>=n, 0<=k<=t): "); // wczytanie tmin i tmax
        scanf("%u,%u", &tmin, &tmax); //
    } while (tmax < tmin || tmax > t || tmin < 0); // jesli tmax < tmin, tmax > t lub tmin < 0 to powtarzamy petle
   unsigned k = tmin;
   for (tmin >= 0 || tmax >= 0; k <= tmax; ++k)
        printf("%u\n", fibonacci[k]); // wypisanie wartosci z tablicy z podanego zakresu
}
