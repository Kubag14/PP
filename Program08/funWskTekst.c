#include "funWskTekst.h"

void wypiszTekstP(FILE *wo, const char *restrict tekst) { // wypisywanie tekstu z tablicy do pliku
    if (fprintf(wo,"\033[0;33m%s\033[0m",tekst) < 0) { //wypisanie calosci tablicy do pliku
        printf("\033[0;31mBlad pisania w pliku wyjsciowym!\033[0m\n"); // jesli mniejsze <0 to blad, bo fprintf przy bledzie wyrzuca wartosc ujemna
        exit(3);
    }
    fprintf(wo, "\n"); // pisanie do pliku
}

void czytajTekstP(FILE *wi, char *restrict tekst,int max) { // czytanie tekstu z pliku do tablicy
    char c;
    int i = 0;
    while ((c = fgetc(wi)) != EOF) { // czytanie z pliku in
        *(tekst + i) = c;
        i++;
        if (i >= max - 1) { // jesli i >= max -1 to blad z powodu zbyt dlugiego tekstu
            printf("\033[0;31mWprowadzono zbyt dlugi tekst, maksymalna dlugosc tekstu: %i znakow.\033[0m\n", max - 1);
            exit(4);
        }
    }
    *(tekst + i + 1) = '\0';
}

void wszystkieZnakiP(FILE *wo, const char *restrict tekst) {
    int i = 0;
    while (*(tekst+i++) != '\0'); // zliczanie wszystkich znakow - de facto dlugosci tablicy
    fprintf(wo,"\n\n\033[0;35mLiczba wszystkich znakow: %i\033[0m\n", i);
}

void czarneZnakiP(FILE *wo, const char *restrict tekst) {
    int i = 0, o, czarne = 0;
    while ((o = *(tekst+i)) != '\0') // \0 konczy string
        switch (o) {
            case ' ':
            case '\n':
            case '\t':
                i++; // pozycja tablicy
            default: // czarny znak to kazdy inny oprocz powyzszych
                czarne++;
                i++; // pozycja tablicy
        }
    fprintf(wo,"\033[0;35mLiczba czarnych znakow: %i\033[0m\n", czarne); // wypisanie liczby czarnych znakow
}

void linieP(FILE *wo, const char *restrict tekst) {

    int i = 0, o, linie = 0;
    while ((o = *(tekst+i)) != '\0') // zliczanie wszystkich znakow - de facto dlugosci tablicy
        switch (o) {
            case '\n':
                i++; // pozycja w tablicy
                linie++; // liczba linii
            default:
                i++;
        }
    if (*(tekst+i-1) != '\n') // jesli przedostatni znak to nie \n to +1 do liczby linii
        linie++;
    fprintf(wo,"\033[0;35mLiczba linii: %i\033[0m\n", linie); // wypisanie liczby linii
}

void slowaP(FILE *wo, const char *restrict tekst) {

    int i = 1, slowa = 0;
    while (*(tekst+i) != '\0') {
        if ((*(tekst+i) == ' ' || *(tekst+i) == '\n' || *(tekst+i) == '\t') && (*(tekst+i-1) != ' ' && *(tekst+i-1) != '\n' && *(tekst+i-1) != '\t')) { // jesli aktualny znak jest bialy i poprzedni jest czarny, to +1 do slow
            slowa++;
            i++; // wskaznik znaku
        } else
            i++; // wskaznik znaku
    }
    if (*(tekst+i-1) != ' ' && *(tekst+i-1) != '\n' &&
            *(tekst+i-1) != '\t') // jesli przedostatni znak jest czarny to +1 do liczby slow
        slowa++;

    fprintf(wo,"\033[0;35mLiczba slow: %i\033[0m\n", slowa); // wypisanie liczby linii
}