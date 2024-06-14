#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
using namespace std;

/// Menu
void menu();
void jugar(string &primerJugador, string &segundoJugador); /// #1
                    /// #2
void creditos();    /// #3

/// Maso
int generarNroAleatorio();
void generarMano(int v[], int tam);
void mostrarMano(int v[], int tam);

void obtenerCarta(int id, int &valor, string &carta, string &figura);

/// Embaucadora
void embaucadora (int v[], int tam, string &figura);

/// Organizacion de masos
int contarNumeros(int v[], int tam, int numero);
bool verificarMano(int v[], int tam);
void ordenarMano(int v[], int tam);

/// Rondas
void primeraRonda(string primerJugador, string segundoJugador);

#endif // FUNCIONES_H_INCLUDED
