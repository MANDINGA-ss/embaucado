#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
using namespace std;

void menu();
int jugar();
void creditos();

int generarNroAleatorio();
void generarMano(int v[], int tam);
void mostrarMano(int v[], int tam);

void obtenerCarta(int id, int &valor, string &nombre, string &palo);

void cartaEmbaucadora (int v[], int tam);

int contarNumeros(int v[], int tam, int numero);
bool verificarMano(int v[], int tam);
void ordenarMano(int v[], int tam);

void primeraRonda(int v[], int tam);

#endif // FUNCIONES_H_INCLUDED
