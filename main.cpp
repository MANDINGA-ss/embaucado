#include <iostream>
#include "menu.h"
#include "rlutil.h" /// Libreria para el SO Linux Ubuntu
#include "funciones.h"

using namespace std;

int main(){

    system("color 03");

    srand(time(0));

    const int tam = 5;
    int mano[tam];

    string primerJugador, segundoJugador;
    menu();

    return 0;

}
