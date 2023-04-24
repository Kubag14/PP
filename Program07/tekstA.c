#include <stdio.h>
#include "funTabTekst.h"

int main()
{
    char tekst[] = "Wielki Zderzacz Hadronów LHC (Large Hadron Collider)\n"
                   "Wielki ze względu na wymiary akceleratora (długość obwodu około 27 km).\n"
                   "Zderzacz, bo cząstki z dwóch przeciwbieżnych wiązek zderzają się w czterech miejscach, w których tory tych wiązek się przecinają.\n"
                   "Hadronów, bo przyspieszane są protony lub jony, które są hadronami (cząstkami, które zbudowane są z kwarków i oddziałują silnie).";
    wypiszTekst(tekst);
    wszystkieZnaki(tekst);
    czarneZnaki(tekst);
    linie(tekst);
    slowa(tekst);
}