#ifndef OPERACJE_MACIERZOWE
#define OPERACJE_MACIERZOWE

#include <stdio.h>
#include <stdlib.h>

int czytajMacierz(FILE *in, char *nazwa, int n, double M[n][n]); // czyta macierz oraz nazwe z pliku, zwraca 1 lub 0

int wypiszMacierz(FILE *out, char *nazwa, int n, double M[n][n]); // pisze macierz oraz nazwe do pliku, zwraca 1 lub 0

int czytajWektor(FILE *in, char *nazwa, int n, double V[n]); // czyta wektor oraz nazwe z pliku, zwraca 1 lub 0

int wypiszWektor(FILE *out, char *nazwa, int n, double V[n]); // pisze wektor oraz nazwe do pliku, zwraca 1 lub 0

int czytajLiczbe(FILE *in, char *nazwa, double* c); // czyta nazwe i liczbe z pliku, zwraca 1 lub 0

int wypiszLiczbe(FILE *out, char *nazwa, double c); // pisze nazwe i liczbe do pliku, zwraca 1 lub 0

void transponujMacierz(int n, double M[n][n], double MT[n][n]); // oblicza macierz transponowana

void dodajMacierze(int n, double A[n][n], double B[n][n], double C[n][n]); // oblicza sume macierzy C = A + B

void odejmijMacierze(int n, double A[n][n], double B[n][n], double C[n][n]); // oblicza roznice macierzy C = A - B

void mnozLiczbaMacierz(int n, double c, double A[n][n], double B[n][n]); // oblicza B = c*A

void mnozMacierzWektor(int n, double A[n][n], double V[n], double W[n]); // oblicza W = A * V

void mnozMacierze(int n, double A[n][n], double B[n][n], double C[n][n]); // oblicza C = A*B

#endif