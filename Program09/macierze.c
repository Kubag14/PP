#include <assert.h>
#include "FunkcjeMacierzowe.h"

#define MAXNAZWA 15 // maksymalna długość nazwy
int main(int argc, char *argv[]) {
    char nazwaA[MAXNAZWA] = {0}; // tablice pod nazwe
    char nazwaB[MAXNAZWA] = {0};
    char nazwaC[MAXNAZWA] = {0};
    char nazwaV[MAXNAZWA] = {0};
    char nazwaL[MAXNAZWA] = {0};

    if (argc != 4) {
        printf("Niewlasciwa liczba argumentow programu!\n");
        printf("Poprawne wywolanie programu:\n");
        printf("%s plik-wejsciowy plik-wyjsciowy rozmiar-macierzy\n", argv[0]);
        exit(1);
    }
    else if (atoi(argv[3]) < 1 || atoi(argv[3]) > 10) {
        printf("Niewlasciwy rozmiar macierzy! Podaj rozmiar w granicy 1-10\n");
        printf("Poprawne wywolanie programu:\n");
        printf("%s plik-wejsciowy plik-wyjsciowy rozmiar-macierzy\n", argv[0]);
        exit(2);
        }
    int n = atoi(argv[3]);
    double A[n][n];
    double B[n][n];
    double C[n][n];
    double V[n];
    double c = 0;
    FILE *in, *out;
    assert((in = fopen(argv[1], "r")));
    assert((out = fopen(argv[2], "w")));

    assert(czytajMacierz(in, nazwaA, n, A));
    assert(czytajMacierz(in, nazwaB, n, B));
    assert(wypiszMacierz(out, nazwaA, n, A));
    assert(wypiszMacierz(out, nazwaB, n, B));
    assert(czytajLiczbe(in, nazwaL, c));
    assert(wypiszLiczbe(out, nazwaL, c));
    assert(czytajWektor(in, nazwaV, n, V));
    assert(wypiszWektor(out, nazwaV, n, V));
}