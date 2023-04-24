#include "funTabTekst.h"

#define MAX 5001 // maksymalna ilosc znakow
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

    czytajTekst(wi, tekst, MAX);
    wypiszTekstP(wo, tekst);
    wszystkieZnakiP(wo, tekst);
    czarneZnakiP(wo, tekst);
    linieP(wo, tekst);
    slowaP(wo, tekst);
    printf("Pomyslnie przekopiowano i wykonano analize tekstu.\n");
}