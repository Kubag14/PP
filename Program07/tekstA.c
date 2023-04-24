#include "funTabTekst.h"

#define MAX 5001 // maksymalna ilosc znakow
int main()
{
    char tekst[] = "Wielki Zderzacz Hadronów LHC (Large Hadron Collider)\n"
                   "Wielki ze względu na wymiary akceleratora (długość obwodu około 27 km).\n"
                   "Zderzacz, bo cząstki z dwóch przeciwbieżnych wiązek zderzają się w czterech miejscach, w których tory tych wiązek się przecinają.\n"
                   "Hadronów, bo przyspieszane są protony lub jony, które są hadronami (cząstkami, które zbudowane są z kwarków i oddziałują silnie).";
    char tekstKop[MAX] = {0};
    printf("Dane dla tekstu pierwotnego:\n");
    wypiszTekst(tekst);
    wszystkieZnaki(tekst);
    czarneZnaki(tekst);
    linie(tekst);
    slowa(tekst);

    kopiujTekst(tekst,tekstKop,MAX);

    printf("\nDane dla tekstu skopiowanego:\n");
    wypiszTekst(tekstKop);
    wszystkieZnaki(tekstKop);
    czarneZnaki(tekstKop);
    linie(tekstKop);
    slowa(tekstKop);
}