#include "TypZespolone.h"
#include <math.h>

zesp czytajZ(FILE *in) { // czyta liczbe zespolona z pliku i zwraca ja
    char c;
    zesp z;
    fscanf(in, "%c%lg%c%lg%c%c ", &c, &z.Re, &c, &z.Im, &c, &c);
    // printf("Odczytano liczbe zespolona (%lg,%lg)\n", z.Re, z.Im);
    return z;
}

int piszZ(FILE *out, zesp z, char const *nazwa) { // pisze liczbe zespolona, zwraca 1/0 sukces/porazka
    if (out == NULL)
        return 0;
    if (fprintf(out, "%s = (%lg, %lg)\n", nazwa, z.Re, z.Im) <= 0)  // pisanie liczby zespolonej; fprintf zwraca liczbe wpisanych znakow i 0 lub liczbe ujemna przy bledzie, jesli tak bedzie to zwracamy 0 (blad)
        return 0;
    printf("\033[0;35m%s\033[0m = (%lg, %lg)\n", nazwa, z.Re, z.Im);
    return 1;
}

int piszL(FILE *out, double m, char const *nazwa) { // pisze liczbe, do modulu lub fazy
    if (out == NULL)
        return 0;
    if (fprintf(out, "%s = %lg\n", nazwa, m) <= 0)  // pisanie liczby zespolonej; fprintf zwraca liczbe wpisanych znakow i 0 lub liczbe ujemna przy bledzie, jesli tak bedzie to zwracamy 0 (blad)
        return 0;
    printf("\033[0;35m%s\033[0m = %lg\n", nazwa, m);
    return 1;
}

zesp sprzezenieZ(zesp z) {
    zesp zs;
    zs.Re = z.Re;
    zs.Im = -z.Im;
    return zs;
}

double modulZ(zesp z) { // zwraca modul liczby zespolonej z
    double a, b, c, m;
    a = z.Re;
    b = z.Im;
    c = (pow(a,2) + pow(b,2));
    m = sqrt(c);
    return m;
}


double fazaZ(zesp z) { // zwraca faze (argument) liczby zespolonej
    double a, b, c, m, f;
    a = z.Re;
    b = z.Im;
    c = (pow(a,2) + pow(b,2));
    m = sqrt(c); // modul
    if (b >= 0)
        f = acos(a / m);
    else
        f = 2 * (M_PI) - acos(a/m);
    return f;
}
zesp sumaZ(zesp z1, zesp z2) { // zwraca sume liczb zespolonych z1 + z2
    double a, b;
    zesp suma;
    a = z1.Re + z2.Re;
    b = z1.Im + z2.Im;
    suma.Re = a;
    suma.Im = b;
    return suma;
}
zesp roznicaZ(zesp z1, zesp z2) { // zwraca roznice liczb zespolonych z1 - z2
    double a, b;
    zesp roznica;
    a = z1.Re - z2.Re;
    b = z1.Im - z2.Im;
    roznica.Re = a;
    roznica.Im = b;
    return roznica;
}
zesp iloczynZ(zesp z1, zesp z2) { // zwraca iloczyn liczb zespolonych z1*z2
    double a, b;
    zesp iloczyn;
    a = (z1.Re * z2.Re) - (z1.Im * z2.Im);
    b = (z1.Re * z2.Im) + (z1.Im * z2.Re);
    iloczyn.Re = a;
    iloczyn.Im = b;
    return iloczyn;
}
zesp ilorazZ(zesp z1, zesp z2) { // zwraca iloraz liczb zespolonych z1/z2
    double a, b;
    zesp iloraz;
    a = ((z1.Re * z2.Re) + (z1.Im * z2.Im))/(pow(z2.Re,2) + pow(z2.Im,2));
    b = ((z1.Im * z2.Re) - (z1.Re * z2.Im))/(pow(z2.Re,2) + pow(z2.Im,2));
    iloraz.Re = a;
    iloraz.Im = b;
    return iloraz;

}

