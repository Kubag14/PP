#include "TypZespolone.h"

zesp czytajZ(FILE *in) { // czyta liczbe zespolona z pliku i zwraca ja
    char c;
    zesp z;
    fscanf(in, "%c%lg%c%lg%c%c ", &c, &z.Re, &c, &z.Im, &c, &c);
    printf("Odczytano liczbe zespolona (%lg,%lg)\n", z.Re, z.Im);
    return z;
}

int piszZ(FILE *out, zesp z) { // pisze do pliku liczbe zespolona, zwraca 1/0 sukces/porazka
    if (out == NULL)
        return 0;
    if (fprintf(out, "(%lg,%lg\n)", z.Re, z.Im) <= 0)  // pisanie liczby zespolonej; fprintf zwraca liczbe wpisanych znakow i 0 lub liczbe ujemna przy bledzie, jesli tak bedzie to zwracamy 0 (blad)
        return 0;
    return 1;
}

zesp sprzezenieZ(zesp z);

double modulZ(zesp z); // zwraca modul liczby zespolonej z

double fazaZ(zesp z); // zwraca faze (argument) liczby zespolonej

zesp sumaZ(zesp z1, zesp z2); // zwraca sume liczb zespolonych z1 + z2

zesp roznicaZ(zesp z1, zesp z2); // zwraca roznice liczb zespolonych z1 - z2

zesp iloczynZ(zesp z1, zesp z2); // zwraca iloczyn liczb zespolonych z1*z2

zesp ilorazZ(zesp z1, zesp z2); // zwraca iloraz liczb zespolonych z1/z2

