#include "funWskTekst.h"

#define MAX 1001 // maksymalna ilosc znakow
int main(int argc, char *argv[])
{
    char tekst[MAX] = {0};
    if (argc != 3) {
        printf("Niewlasciwa liczba argumentow programu!\n");
        printf("Poprawne wywolanie porgramu:\n");
        printf("%s plik-wejsciowy plik-wyjsciowy\n", argv[0]);
        exit(1);
    }
    FILE *wi, *wo;
    wi = fopen(argv[1], "r");
    wo = fopen(argv[2], "w");

    czytajTekstP(wi, tekst, MAX);
    wypiszTekstP(wo, tekst);
    wszystkieZnakiP(wo, tekst);
    czarneZnakiP(wo, tekst);
    linieP(wo, tekst);
    slowaP(wo, tekst);
    printf("\033[1;34mPomyslnie przekopiowano i wykonano analize tekstu.\033[0m\n");
}