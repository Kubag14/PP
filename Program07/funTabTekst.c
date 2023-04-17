#include <stdio.h>
#include <stdlib.h>

int wypiszTekst(char tekst[])
{
    unsigned i = 0;
    while (i <= sizeof(tekst)) {
        putchar(tekst[i]);
        i++;
    }
}
int czytajTekst(FILE *wp, char tekst[],int max);

int kopiujTekst(char skad[], char dokad[], int max);

int wszystkieZnaki(char tekst[])
{
    printf("Liczba wszystkich znakow: %u\n", sizeof(tekst));
}
int czarneZnaki(char tekst[]);
{
while (i = tekst[i] <= sizeof(tekst)) // wczytanie znaku
    switch (i) { // rozpoznanie znaku
        case ' ':
        case '\n':
        case '\t':
        biale++; // zliczanie bialych znakow
        break;
    }
}

int linie(char tekst[]);

int slowa(char tekst[]);