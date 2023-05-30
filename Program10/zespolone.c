#include "TypZespolone.h"

#define MAX 200
int main(int argc, char *argv[]) {
    zesp z1, z2, zs1, zs2;
    double m1, m2;
    char nazwaZ1[MAX] = {0};
    char nazwaZ2[MAX] = {0};
    if (argc != 3) {
        printf("\033[0;31mNiewlasciwa liczba argumentow programu!\n");
        printf("Poprawne wywolanie programu:\n");
        printf("%s plik-wejsciowy plik-wyjsciowy\033[0m\n", argv[0]);
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
    sprintf(nazwaZ1, "Iloczyn liczb zespolonych z1 * z2");
    assert(piszZ(out,zs1,nazwaZ1));
    zs1 = ilorazZ(z1,z2);
    sprintf(nazwaZ1, "Iloraz liczb zespolonych z1 / z2");
    assert(piszZ(out,zs1,nazwaZ1));


    /* ponizej operacje z wykorzystaniem biblioteki complex */
    printf("\n\033[0;31mOPERACJE Z WYKORZYSTANIEM COMPLEX.H\033[0m\n\n"); // ekran (stdout)
    fprintf(out,"\nOPERACJE Z WYKORZYSTANIEM COMPLEX.H\n\n"); // plik

    double complex zf1 = 5.8 + 10.5*I, zf2 = 6.2 + 2.3*I; // zdefiniowane liczby zespolone
    double complex zfc1, zfc2; // na tych zmiennych program "pracuje"
    printf("\033[0;35mLiczba zespolona zf1\033[0m = (%lg, %lg)\n", creal(zf1),cimag(zf1));
    printf("\033[0;35mLiczba zespolona zf2\033[0m = (%lg, %lg)\n", creal(zf2),cimag(zf2));
    fprintf(out,"Liczba zespolona zf1 = (%lg, %lg)\n", creal(zf1),cimag(zf1));
    fprintf(out,"Liczba zespolona zf2 = (%lg, %lg)\n", creal(zf2),cimag(zf2));
    /* sprzezenie */
    zfc1 = conj(zf1);
    zfc2 = conj(zf2);
    printf("\033[0;35mLiczba zespolona sprzezona zf1*\033[0m = (%lg, %lg)\n", creal(zfc1),cimag(zfc1));
    printf("\033[0;35mLiczba zespolona sprzezona zf2*\033[0m = (%lg, %lg)\n", creal(zfc2),cimag(zfc2));
    fprintf(out,"Liczba zespolona sprzezona zf1*= (%lg, %lg)\n", creal(zfc1),cimag(zfc1));
    fprintf(out,"Liczba zespolona sprzezona zf2* = (%lg, %lg)\n", creal(zfc2),cimag(zfc2));
    /* modul */
    printf("\033[0;35mModul liczby zespolonej |zf1|\033[0m = %lg\n", cabs(zf1)); // modul bezposrednio w printf, bo cabs zwraca double
    printf("\033[0;35mModul liczby zespolonej |zf2|\033[0m = %lg\n", cabs(zf2));
    fprintf(out,"Modul liczby zespolonej |zf2| = %lg\n", cabs(zf1));
    fprintf(out,"Modul liczby zespolonej |zf2| = %lg\n", cabs(zf2));
    /* faza */
    printf("\033[0;35mFaza liczby zespolonej fi(zf1)\033[0m = %lg\n", carg(zf1)); // faza bezposrednio w printf, bo carg zwraca double
    printf("\033[0;35mFaza liczby zespolonej fi(zf2)\033[0m = %lg\n", carg(zf2));
    fprintf(out,"Faza liczby zespolonej fi(zf1) = %lg\n", carg(zf1));
    fprintf(out,"Faza liczby zespolonej fi(zf2) = %lg\n", carg(zf2));

    zfc1 = zf1 + zf2; // suma
    printf("\033[0;35mSuma liczb zespolonych zf1 + zf2\033[0m = (%lg, %lg)\n", creal(zfc1),cimag(zfc1));
    fprintf(out,"Suma liczb zespolonych zf1 + zf2 = (%lg, %lg)\n", creal(zfc1),cimag(zfc1));

    zfc1 = zf1 - zf2; // roznica
    printf("\033[0;35mRoznica liczb zespolonych zf1 - zf2\033[0m = (%lg, %lg)\n", creal(zfc1),cimag(zfc1));
    fprintf(out,"Roznica liczb zespolonych zf1 - zf2 = (%lg, %lg)\n", creal(zfc1),cimag(zfc1));
    zfc1 = zf1 * zf2; // iloczyn
    printf("\033[0;35mIloczyn liczb zespolonych zf1 * zf2\033[0m = (%lg, %lg)\n", creal(zfc1),cimag(zfc1));
    fprintf(out,"Iloczyn liczb zespolonych zf1 * zf2 = (%lg, %lg)\n", creal(zfc1),cimag(zfc1));

    zfc1 = zf1/zf2; // iloraz
    printf("\033[0;35mIloraz liczb zespolonych zf1 / zf2\033[0m = (%lg, %lg)\n", creal(zfc1),cimag(zfc1));
    fprintf(out,"Iloraz liczb zespolonych zf1 / zf2 = (%lg, %lg)\n", creal(zfc1),cimag(zfc1));
}
