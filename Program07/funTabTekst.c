#include <stdio.h>

void wypiszTekst(char tekst[])
{
    int i = 0;
    while (tekst[i] != '\0') {
        putchar(tekst[i]);
        i++;
    }
}
int czytajTekst(FILE *wp, char tekst[],int max);

int kopiujTekst(char skad[], char dokad[], int max);

void wszystkieZnaki(char tekst[])
{
    int i = 0;
    while (tekst[i] != '\0') // zliczanie wszystkich znakow - de facto dlugosci tablicy
        i++;
    printf("\n\nLiczba wszystkich znakow: %i\n", i);
}
void czarneZnaki(char tekst[])
{
    int i = 0, o, czarne = 0;
    while ((o = tekst[i]) != '\0')
        switch (o) {
            case ' ':
            case '\n':
            case '\t':
            i++; // pozycja tablicy
        default:
            czarne++;
            i++; // pozycja tablicy
        }
    printf("Liczba czarnych znakow: %i\n", czarne); // wypisanie liczby czarnych znakow
}
void linie(char tekst[]) {

    int i = 0, o = 0, linie = 0;
    while ((o = tekst[i]) != '\0') // zliczanie wszystkich znakow - de facto dlugosci tablicy
        switch (o) {
            case '\n':
                i++; // pozycja w tablicy
                linie++; // liczba linii
            default:
                i++;
        }
    if (tekst[i - 1] != '\n') // jesli przedostatni znak to nie \n to +1 do liczby linii
        linie++;
    printf("Liczba linii: %i\n", linie); // wypisanie liczby linii
}

void slowa(char tekst[]) {

    int i = 1, o = 0, slowa = 0;
    while (tekst[i] != '\0')
        if (tekst[i] = (' ' || '\n' || '\t') && tekst[i - 1] != (' ' && '\n' && '\t')) {
            slowa++;
            i++;
        }
        else
            i++;

    if (tekst[i - 1] != (' ' && '\n' && '\t')) // jesli przedostatni znak jest czarny to +1 do liczby slow
    slowa++;

    printf("Liczba slow: %i\n", slowa); // wypisanie liczby linii
}