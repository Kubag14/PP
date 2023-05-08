#include <stdio.h>
#include <stdlib.h>

void wypiszTekstP(FILE *wo, char *tekst) { // wypisywanie tekstu z tablicy do pliku
    int c, i = 0;
    while ((c = *(tekst+i)) != '\0') {
        if (fputc(c, wo) == EOF) { // pisanie do pliku out
            printf("Blad pisania w pliku wyjsciowym\n");
            exit(3);
        } else
            i++;
    }
    fprintf(wo, "\n"); // pisanie do pliku
}

void czytajTekst(FILE *wi, char *tekst, int max) { // czytanie tekstu z pliku do tablicy
    char c;
    int i = 0;
    if (i <= (max - 1)) {
        while ((c = fgetc(wi)) != EOF) { // czytanie z pliku in
            *(tekst+i++) = c;
        }
    } else {
        printf("Wprowadzono zbyt dlugi tekst, maksymalna dlugosc tekstu: %i znakow", max - 1);
        exit(4);
    }
    *(tekst + i + 1) = '\0';
}

void wszystkieZnakiP(FILE *wo, char *tekst) {
    int i = 0;
    while (*(tekst+i++) != '\0'); // zliczanie wszystkich znakow - de facto dlugosci tablicy
    fprintf(wo,"\n\nLiczba wszystkich znakow: %i\n", i);
}

void czarneZnakiP(FILE *wo, char *tekst) {
    int i = 0, o, czarne = 0;
    while ((o = *(tekst+i)) != '\0')
        switch (o) {
            case ' ':
            case '\n':
            case '\t':
                i++; // pozycja tablicy
            default:
                czarne++;
                i++; // pozycja tablicy
        }
    fprintf(wo,"Liczba czarnych znakow: %i\n", czarne); // wypisanie liczby czarnych znakow
}

void linieP(FILE *wo, char *tekst) {

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
    fprintf(wo,"Liczba linii: %i\n", linie); // wypisanie liczby linii
}

void slowaP(FILE *wo, char *tekst) {

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

    fprintf(wo,"Liczba slow: %i\n", slowa); // wypisanie liczby linii
}