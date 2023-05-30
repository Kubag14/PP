#include <assert.h>
#include "TypZespolone.h"
#define MAX 200
int main(int argc, char *argv[]) {
    zesp z1, z2, zs1, zs2;
    double m1, m2;
    char nazwaZ1[MAX] = {0};
    char nazwaZ2[MAX] = {0};
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
    sprintf(nazwaZ1, "Liczba zespolona z1");
    sprintf(nazwaZ2, "Liczba zespolona z2");
    assert(piszZ(out, z1, nazwaZ1));
    assert(piszZ(out, z2, nazwaZ2));
    zs1 = sprzezenieZ(z1);
    zs2 = sprzezenieZ(z2);
    sprintf(nazwaZ1, "Liczba zespolona sprzezona z1*");
    sprintf(nazwaZ2, "Liczba zespolona sprzezona z2*");
    assert(piszZ(out, zs1, nazwaZ1));
    assert(piszZ(out, zs2, nazwaZ2));
    m1 = modulZ(z1);
    m2 = modulZ(z2);
    sprintf(nazwaZ1, "Modul liczby zespolonej |z1|");
    sprintf(nazwaZ2, "Modul liczby zespolonej |z2|");
    assert(piszL(out, m1, nazwaZ1));
    assert(piszL(out, m2, nazwaZ2));
    m1 = fazaZ(z1);
    m2 = fazaZ(z2);
    sprintf(nazwaZ1, "Faza liczby zespolonej fi(z1)");
    sprintf(nazwaZ2, "Faza liczby zespolonej fi(z2)");
    assert(piszL(out, m1, nazwaZ1));
    assert(piszL(out, m2, nazwaZ2));
    zs1 = sumaZ(z1,z2);
    sprintf(nazwaZ1, "Suma liczb zespolonych z1 + z2");
    assert(piszZ(out,zs1,nazwaZ1));
    zs1 = roznicaZ(z1,z2);
    sprintf(nazwaZ1, "Roznica liczb zespolonych z1 - z2");
    assert(piszZ(out,zs1,nazwaZ1));
    zs1 = iloczynZ(z1,z2);
    sprintf(nazwaZ1, "Iloczyn zespolonych z1 * z2");
    assert(piszZ(out,zs1,nazwaZ1));
    zs1 = ilorazZ(z1,z2);
    sprintf(nazwaZ1, "Iloraz liczb zespolonych z1 / z2");
    assert(piszZ(out,zs1,nazwaZ1));
}