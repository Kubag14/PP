#include "FunkcjeMacierzowe.h"

int czytajMacierz(FILE *in, char *nazwa, int n, double M[n][n]) { // czyta macierz oraz nazwe z pliku, zwraca 1 lub 0
    int k, w;
    fscanf(in, "%s", &nazwa);
    for (k = 0; k < n; k++)
        for (w = 0; w < n; w++)
        fscanf(in, "%f", &M[k][w]);

    return 1;
}
int wypiszMacierz(FILE *out, char *nazwa, int n, double M[n][n]) { // pisze macierz oraz nazwe do pliku, zwraca 1 lub 0
    int k, w;
    fprintf(out, "%s", nazwa);
    for (k = 0; k < n; k++) {
        for (w = 0; w < n; w++) {
            fprintf(out, "%f", &M[k][w]);
            fputs(" ", out);
        }
        fprintf(out, "\n");
    }
    return 1;
}
int czytajWektor(FILE *in, char *nazwa, int n, double V[n]); // czyta wektor oraz nazwe z pliku, zwraca 1 lub 0

int wypiszWektor(FILE *in, char *nazwa, int n, double V[n]); // pisze wektor oraz nazwe do pliku, zwraca 1 lub 0

int czytajLiczbe(FILE *in, char *nazwa, double *c); // czyta nazwe i liczbe z pliku, zwraca 1 lub 0

int wypiszLiczbe(FILE *in, char *nazwa, double *c); // pisze nazwe i liczbe do pliku, zwraca 1 lub 0

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