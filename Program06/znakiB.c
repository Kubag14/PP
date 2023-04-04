#include <stdio.h>
#include <stdlib.h>

/* Program zlicza w tekscie: cyfry (kazda oddzielnie), biale znaki oraz pozostale znaki. */

#define NC 10
int main()
{
    int c, zz, zw,
    i,
    biale = 0,
    inne = 0,
    cyfry[NC] = {0};
    printf("Zliczanie cyfr, bialych znakow i pozostalych znakow w tekscie: \n");

    const char zrodlo[] = "txt.txt";
    const char cel[] = "out.txt";
    FILE *wz, *wc; // wskazniki do plikow zrodla i celu

    if ( (wz = fopen(zrodlo,"r")) == NULL) {
        printf("Blad otwarcia pliku %s\n", zrodlo);
        exit(1);
    }
    if ( ( wc = fopen(cel,"w")) == NULL) {
        printf("Blad otwarcia pliku %s\n", cel);
        exit(2);
    }
    while ((c = fgetc(wz)) != EOF) // czytanie do pliku wz
        if (fputc(c,wc) == EOF) {
            printf("Blad pisania w pliku %s\n", cel);
            exit(3);
        }
    // Jawne zamkniecie plikow - z obsluga bledow
    if (fclose(wz) == EOF) { // zamkniecie pliku wz
        printf("Blad zamykania pliku %s\n", zrodlo);
        exit(4);
    }
    if (fclose(wc) == EOF) { // zamkniecie pliku wc
        printf("Blad zamykania pliku %s\n", cel);
        exit(5);
    }



    while ( (c = getchar()) != EOF ) // wczytanie znaku
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
        printf("Cyfry:\n");
        for (i = 0; i < NC; ++i)
            printf("\t%c: %d\n", '0'+i, cyfry[i]);
        printf("Biale znaki: %d\nInne znaki: %d\n",biale,inne);
}