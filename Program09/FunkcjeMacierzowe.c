#include "FunkcjeMacierzowe.h"

int czytajMacierz(FILE *in, char *nazwa, int n, double M[n][n]) { // czyta macierz oraz nazwe z pliku, zwraca 1 lub 0
    int k, w;
    if (in == NULL)
        return 0;
    if (fscanf(in, "%s", nazwa) <= 0)
        return 0;
    for (k = 0; k < n; k++)
        for (w = 0; w < n; w++)
            if (fscanf(in, "%lf", &M[k][w]) <= 0)
                return 0;
    return 1;
}
int wypiszMacierz(FILE *out, char *nazwa, int n, double M[n][n]) { // pisze macierz oraz nazwe do pliku, zwraca 1 lub 0
    int k, w;
    if (out == NULL)
        return 0;
    if (fprintf(out, "\033[0;35m%s:\033[0m\n", nazwa) <= 0)
        return 0;
    printf("\033[0;35m%s:\033[0m\n", nazwa);
    for (k = 0; k < n; k++) {
        for (w = 0; w < n; w++) {
            if (fprintf(out, "%g ", M[k][w]) <= 0)
                return 0;
            printf("%g ", M[k][w]);
        }
        fprintf(out, "\n");
        printf("\n");
    }
    fprintf(out, "\n");
    printf("\n");
    return 1;
}
int czytajWektor(FILE *in, char *nazwa, int n, double V[n]) { // czyta wektor oraz nazwe z pliku, zwraca 1 lub 0
    int w;
    if (in == NULL)
        return 0;
    if (fscanf(in, "%s", nazwa) <= 0)
        return 0;
    for (w = 0; w < n; w++)
        if (fscanf(in, "%lf", &V[w]) <= 0)
            return 0;
    return 1;
}

int wypiszWektor(FILE *out, char *nazwa, int n, double V[n]) { // pisze wektor oraz nazwe do pliku, zwraca 1 lub 0
    int w;
    if (out == NULL)
        return 0;
    if (fprintf(out, "\033[0;35m%s:\033[0m\n", nazwa) <= 0)
        return 0;
    printf("\033[0;35m%s:\033[0m\n", nazwa);
    for (w = 0; w < n; w++) {
        if (fprintf(out, "%g\n", V[w]) <= 0)
            return 0;
        printf("%g\n", V[w]);
    }
    fprintf(out, "\n");
    printf("\n");
    return 1;
}

int czytajLiczbe(FILE *in, char *nazwa, double* c) {  // czyta nazwe i liczbe z pliku, zwraca 1 lub 0
    if (in == NULL)
        return 0;
    if (fscanf(in, "%s", nazwa) <= 0 || fscanf(in, "%lf", c) <= 0)
        return 0;
    return 1;
}

int wypiszLiczbe(FILE *out, char *nazwa, double c) { // pisze nazwe i liczbe do pliku, zwraca 1 lub 0
    if (out == NULL)
        return 0;
    if (fprintf(out, "\033[0;35m%s\033[0m\n", nazwa) <= 0 || fprintf(out, "%g\n\n", c) <= 0)
        return 0;
    printf("\033[0;35m%s:\n\033[0m%g\n\n", nazwa, c);
    return 1;
}
void transponujMacierz(char const *nazwaM, char *nazwaMT, int n, double M[n][n], double MT[n][n]) {  // oblicza macierz transponowana
    int k,w;
    for (k = 0; k < n; k++) {
        for (w = 0; w < n; w++) {
            MT[k][w] = M[w][k];
        }
    }
    sprintf(nazwaMT, "Macierz transponowana %s^T", nazwaM);
}

void dodajMacierze(char const *nazwaA, char const *nazwaB, char *nazwaC, int n, double A[n][n], double B[n][n], double C[n][n]) { // oblicza sume macierzy C = A + B
    int k, w;
    for (k = 0; k < n; k++) {
        for (w = 0; w < n; w++) {
            C[k][w] = A[k][w] + B[k][w];
        }
    }
    sprintf(nazwaC, "Macierz Cd = %s + %s", nazwaA, nazwaB);
}

void odejmijMacierze(char const *nazwaA, char const *nazwaB, char *nazwaC, int n, double A[n][n], double B[n][n], double C[n][n]) { // oblicza roznice macierzy C = A - B
    int k, w;
    for (k = 0; k < n; k++) {
        for (w = 0; w < n; w++) {
            C[k][w] = A[k][w] - B[k][w];
        }
    }
    sprintf(nazwaC, "Macierz Co = %s - %s", nazwaA, nazwaB);
}
void mnozLiczbaMacierz(char const *nazwaA, char const *nazwaL, char *nazwaC, int n, double c, double M[n][n], double Mc[n][n]) { // oblicza B = c*A
    int k, w;
    for (k = 0; k < n; k++) {
        for (w = 0; w < n; w++) {
            Mc[k][w] = M[k][w] * c;
        }
    }
    sprintf(nazwaC, "Macierz Cl = %s * %s", nazwaA, nazwaL);
}

void mnozMacierzWektor(char const *nazwaA, char const *nazwaV, char *nazwaC, int n, double A[n][n], double V[n], double W[n]) { // oblicza W = A * V
    int k, w, i;
    for (i = 0; i < n; i++)
        W[i] = 0;
    for (w = 0; w < n; w++)
        for (k = 0; k < n; k++)
            W[w] += A[w][k] * V[k];
    sprintf(nazwaC, "Wektor W = %s * %s", nazwaA, nazwaV);
}

void mnozMacierze(char const *nazwaA, char const *nazwaB, char *nazwaC, int n, double A[n][n], double B[n][n], double C[n][n]) { // oblicza C = A*B
    int k, w, p;
    double suma;
    for (w = 0; w < n; w++)
        for (k = 0; k < n; k++) {
            suma = 0.0;
            for (p = 0; p < n; p++)
                suma += A[w][p] * B[p][k];
            C[w][k] = suma;
        }
    sprintf(nazwaC, "Macierz Cm = %s * %s", nazwaA, nazwaB);
}