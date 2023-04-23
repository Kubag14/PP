#include <stdio.h>
#include <stdlib.h>

/* Program zlicza w tekscie: cyfry (kazda oddzielnie), biale znaki oraz pozostale znaki. */

#define NC 10 // definiujemy rozmiar tablicy - jest 9 cyfr
int main()
{
    int c, i,
    biale = 0,
    inne = 0,
    cyfry[NC] = {0}; // tablica na cyfry
    const char in[] = "wejscie.txt";
    const char out[] = "wyjscieB.txt";
    printf("Zliczanie cyfr, bialych znakow i pozostalych znakow w tekscie. \n");
    printf("Plik wejsciowy: wejscie.txt; plik wyjsciowy: wyjscieB.txt \n");

    FILE *wi, *wo; // wskazniki do plikow zrodla i celu, wi = in, wo = out
    wi = fopen(in,"r"); // otwarcie pliku in do czytania
    wo = fopen(out,"w"); // otwarcie pliku out do pisania

    if ((wi) == NULL) {
        printf("Blad otwarcia pliku %s\n", in);
        exit(1);
    }
    if ((wo) == NULL) {
        printf("Blad otwarcia pliku %s\n", out);
        exit(2);
    }
    while ((c = fgetc(wi)) != EOF) // czytanie z pliku in
        if (fputc(c,wo) == EOF) { // pisanie do pliku out
            printf("Blad pisania w pliku %s\n", out);
            exit(3);
        }

    // Jawne zamkniecie plikow - z obsluga bledow
    if (fclose(wi) == EOF) { // zamkniecie pliku in
        printf("Blad zamykania pliku %s\n", in);
        exit(4);
    }
    if (fclose(wo) == EOF) { // zamkniecie pliku out
        printf("Blad zamykania pliku %s\n", out);
        exit(5);
    }

/* na tym etapie dane z pliku wejsciowego sa przekopiowane do pliku wyjsciowego */

    FILE *wor;
    wor = fopen(out,"a+"); // ponowne otwarcie pliku wyjsciowego, czytanie i pisanie na koncu

    if ((wor) == NULL) {
        printf("Blad otwarcia pliku %s\n", out);
        exit(6);
    }

    while ((c = fgetc(wor)) != EOF ) // wczytanie znaku
        switch (c) { // rozpoznanie znaku
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                cyfry[c - '0']++; // zliczanie cyfr
                break;

            case ' ':
            case '\n':
            case '\t':
                biale++; // zliczanie bialych znakow
                break;

            default:
                inne++; // zliczanie innych znakow
                break;
        } // switch
    fprintf(wo,"\nCyfry:\n");
    for (i = 0; i < NC; ++i)
        fprintf(wo,"\t%c: %d\n", '0'+i, cyfry[i]);
    fprintf(wo,"Biale znaki: %d\nInne znaki: %d\n",biale,inne); // wypisanie wynikow na koncu pliku

    if (fclose(wor) == EOF) { // ponowne zamkniecie pliku out
        printf("Blad zamykania pliku %s\n", in);
        exit(7);
    }
    printf("Zakonczono pomyslnie \n");
}