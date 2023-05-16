#include "FunkcjeMacierzowe.h"

int czytajMacierz(FILE *in, char *nazwa, int n, double M[n][n]) { // czyta macierz oraz nazwe z pliku, zwraca 1 lub 0
    int k, w;
    fscanf(in, "%s", nazwa);
    for (k = 0; k < n; k++)
        for (w = 0; w < n; w++)
        fscanf(in, "%lf", &M[k][w]);
    return 1;
}
int wypiszMacierz(FILE *out, char *nazwa, int n, double M[n][n]) { // pisze macierz oraz nazwe do pliku, zwraca 1 lub 0
    int k, w;
    fprintf(out, "%s\n", nazwa);
    for (k = 0; k < n; k++) {
        for (w = 0; w < n; w++) {
            fprintf(out, "%g", M[k][w]);
            fputs(" ", out);
        }
        fprintf(out, "\n");
    }
    return 1;
}
int czytajWektor(FILE *in, char *nazwa, int n, double V[n]) { // czyta wektor oraz nazwe z pliku, zwraca 1 lub 0
    int k;
    fscanf(in, "%s", nazwa);
    for (k = 0; k < n; k++)
        fscanf(in, "%lf", &V[k]);
    return 1;
}

int wypiszWektor(FILE *out, char *nazwa, int n, double V[n]) { // pisze wektor oraz nazwe do pliku, zwraca 1 lub 0
    int k;
    fprintf(out, "%s\n", nazwa);
    for (k = 0; k < n; k++) {
        fprintf(out, "%g\n", V[k]);
    }
    fprintf(out, "\n");
    return 1;
}
int czytajLiczbe(FILE *in, char *nazwa, double c) {  // czyta nazwe i liczbe z pliku, zwraca 1 lub 0
    fscanf(in, "%s", nazwa);
    fscanf(in, "%lf", &c);
    return 1;
}

int wypiszLiczbe(FILE *out, char *nazwa, double c) { // pisze nazwe i liczbe do pliku, zwraca 1 lub 0
    fprintf(out, "%s\n", nazwa);
    fprintf(out, "%g\n", c);
    return 1;
}
void transponujMacierz(int n, double M[n][n], double MT[n][n]); // oblicza macierz transponowana

void dodajMacierze(int n, double A[n][n], double B[n][n], double C[n][n]); // oblicza sume macierzy C = A + B

void odejmijMacierze(int n, double A[n][n], double B[n][n], double C[n][n]); // oblicza roznice macierzy C = A - B

void mnozLiczbaMacierz(int n, double c, double A[n][n], double B[n][n]); // oblicza B = c*A

void mnozMacierzWektor(int n, double A[n][n], double V[n], double W[n]); // oblicza W = A * V

void mnozMacierze(int n, double A[n][n], double B[n][n], double C[n][n]) // oblicza C = A*B
{
    int i, j, k;
    double suma;
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j) {
            suma = 0.0;
            for (k = 0; k < n; ++k)
                suma += A[i][k] * B[k][j];
            C[i][j] = suma;
        }
}