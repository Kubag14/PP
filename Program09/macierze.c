#include <assert.h>
#include "FunkcjeMacierzowe.h"

#define MAXNAZWA 200 // maksymalna długość nazwy
int main(int argc, char *argv[]) {
    char nazwaA[MAXNAZWA] = {0}; // tablice pod nazwe
    char nazwaB[MAXNAZWA] = {0};
    char nazwaC[MAXNAZWA] = {0};
    char nazwaV[MAXNAZWA] = {0};
    char nazwaL[MAXNAZWA] = {0};
    int n;

    if (argc != 4) {
        printf("Niewlasciwa liczba argumentow programu!\n");
        printf("Poprawne wywolanie programu:\n");
        printf("%s plik-wejsciowy plik-wyjsciowy rozmiar-macierzy\n", argv[0]);
        exit(1);
    }
    else if ((n = atoi(argv[3])) < 1 || n > 10) { // atoi konwertuje char na int (pobieranie wartosci n z argumentu wywolania programu)
        printf("Niewlasciwy rozmiar macierzy! Podaj rozmiar w granicy 1-10\n");
        printf("Poprawne wywolanie programu:\n");
        printf("%s plik-wejsciowy plik-wyjsciowy rozmiar-macierzy\n", argv[0]);
        exit(2);
    }
    double A[n][n]; // tablice pod macierze
    double B[n][n];
    double C[n][n];
    double V[n]; // tablice pod wektory
    double W[n];
    double c = 0; // liczba
    FILE *in, *out;
    assert((in = fopen(argv[1], "r"))); // otwieranie plikow
    assert((out = fopen(argv[2], "w")));

    assert(czytajMacierz(in, nazwaA, n, A));
    assert(czytajMacierz(in, nazwaB, n, B));
    assert(czytajLiczbe(in, nazwaL, &c));
    assert(czytajWektor(in, nazwaV, n, V)); // odczytane dane wejsciowe
    assert(wypiszMacierz(out, nazwaA, n, A));
    assert(wypiszMacierz(out, nazwaB, n, B));
    assert(wypiszLiczbe(out, nazwaL, c));
    assert(wypiszWektor(out, nazwaV, n, V)); // dane wejsciowe przepisane do pliku wyjsciowego
    /* dalsze operacje wykonywane sa na zapisanych tablicach
    po wykonaniu operacji wynik jest od razu wypisywany na ekran i do pliku
    kazda funkcja wykonuje operacje i zapisuje nazwe wyniku (np. macierz transponowana) do tablicy nazwaC
    przez to mozna uzyc jednej tablicy do wszystkich nazw - nazwaC w kazdym przypadku wskazuje, co jest pod tablica C[n][n] */
    transponujMacierz(nazwaA, nazwaC, n, A, C);
    assert(wypiszMacierz(out, nazwaC, n, C));
    transponujMacierz(nazwaB, nazwaC, n, B, C);
    assert(wypiszMacierz(out, nazwaC, n, C));
    dodajMacierze(nazwaA, nazwaB, nazwaC, n, A, B, C);
    assert(wypiszMacierz(out, nazwaC, n, C));
    odejmijMacierze(nazwaA, nazwaB, nazwaC, n, A, B, C);
    assert(wypiszMacierz(out, nazwaC, n, C));
    mnozLiczbaMacierz(nazwaA, nazwaL, nazwaC, n, c, A, C);
    assert(wypiszMacierz(out, nazwaC, n, C));
    mnozLiczbaMacierz(nazwaB, nazwaL, nazwaC, n, c, B, C);
    assert(wypiszMacierz(out, nazwaC, n, C));
    mnozMacierzWektor(nazwaA, nazwaV, nazwaC, n, A, V, W);
    assert(wypiszWektor(out, nazwaC, n, W));
    mnozMacierze(nazwaA, nazwaB, nazwaC, n, A, B, C);
    assert(wypiszMacierz(out, nazwaC, n, C));
}