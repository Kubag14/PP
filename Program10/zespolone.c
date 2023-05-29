#include <assert.h>
#include "TypZespolone.h"

int main(int argc, char *argv[]) {
    zesp z1, z2;
    if (argc != 3) {
        printf("Niewlasciwa liczba argumentow programu!\n");
        printf("Poprawne wywolanie programu:\n");
        printf("%s plik-wejsciowy plik-wyjsciowy\n", argv[0]);
        exit(1);
    }

    FILE *in, *out;
    assert((in = fopen(argv[1], "r")));
    assert((out = fopen(argv[2], "w")));
    z1 = czytajZ(in);
    z2 = czytajZ(in);
    printf("Odczytane liczby zespolone: z1 = (%lg,%lg), z2 = (%lg,%lg)\n", z1.Re, z1.Im, z2.Re, z2.Im);
    assert(piszZ(out, z1));
    assert(piszZ(out, z2));
}