#ifndef PPC_TYPZESPOLONE_H
#define PPC_TYPZESPOLONE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <assert.h>

struct Zespolone {
    double Re;
    double Im;
};
typedef struct Zespolone zesp;

zesp czytajZ(FILE *in); // czyta liczbe zespolona z pliku i zwraca ja

int piszZ(FILE *out, zesp z, char const *nazwa); // pisze do pliku liczbe zespolona, zwraca 1/0 sukces/porazka

int piszL(FILE *out, double m, char const *nazwa);

zesp sprzezenieZ(zesp z);

double modulZ(zesp z); // zwraca modul liczby zespolonej z

double fazaZ(zesp z); // zwraca faze (argument) liczby zespolonej

zesp sumaZ(zesp z1, zesp z2); // zwraca sume liczb zespolonych z1 + z2

zesp roznicaZ(zesp z1, zesp z2); // zwraca roznice liczb zespolonych z1 - z2

zesp iloczynZ(zesp z1, zesp z2); // zwraca iloczyn liczb zespolonych z1*z2

zesp ilorazZ(zesp z1, zesp z2); // zwraca iloraz liczb zespolonych z1/z2


#endif