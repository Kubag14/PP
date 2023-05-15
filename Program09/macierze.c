#include <assert.h>
#include "FunkcjeMacierzowe.h"

int main(int argc, char *argv[]) {
    char nazwa[15] = {0}; // tablica pod nazwe
    if (argc != 4) {
        printf("Niewlasciwa liczba argumentow programu!\n");
        printf("Poprawne wywolanie programu:\n");
        printf("%s plik-wejsciowy plik-wyjsciowy rozmiar-macierzy\n", argv[0]);
        exit(1);
    }
    int n = atoi(argv[3]);
    double M[n][n];
    FILE *in, *out;
    assert(in = fopen(argv[1], "r"));
    assert(out = fopen(argv[2], "w"));

    assert(czytajMacierz(in, nazwa, n, M));
    assert(wypiszMacierz(out, nazwa, n, M));
}