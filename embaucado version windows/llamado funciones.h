#ifndef MENUHEADER_H_INCLUDED
#define MENUHEADER_H_INCLUDED

#include<stdio.h>
using namespace std;

void menu();
int numerorandom(int taman);
int juego(string &nombre1, string &nombre2, int puntJ1[], int puntJ2[]);
int estadisticas(string &nombre1, string &nombre2, int puntJ1[], int puntJ2[]);
void creditos();

#endif // MENUHEADER_H_INCLUDED
