#include <assert.h>
#include "FunkcjeMacierzowe.h"

int main(int argc, char *argv[]) {
    char nazwa[15] = {0}; // tablica pod nazwe

    if (argc != 3) {
        printf("Niewlasciwa liczba argumentow programu!\n");
        printf("Poprawne wywolanie porgramu:\n");
        printf("%s plik-wejsciowy plik-wyjsciowy\n", argv[0]);
        exit(1);
    }
    FILE *in, *out;
    assert(in = fopen(argv[1], "r"));
    assert(out = fopen(argv[2], "w"));
}