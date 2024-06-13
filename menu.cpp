#include "menu.h"
#include "funciones.h"
#include<iostream>
#include<cstdlib>
#include "rlutil.h"

using namespace std;

void menu(){

    string primerJugador, segundoJugador;
    char opcion;

    cout << "EMBAUCADO" << endl;
    cout << "---------------------" << endl;
    cout << "1- JUGAR" << endl;
    cout << "2- ESTADÍSTICAS" << endl;
    cout << "3 - CRÉDITOS" << endl;
    cout << "---------------------" << endl;
    cout << "0- SALIR" << endl;

    cout << "Ingrese una opcion: ";
    cin >> opcion;

    rlutil::cls();

    switch(opcion){
        
        case '1':
        jugar(primerJuador, segundoJugador);
        break;

        case '2':
        /// Estadisticas
        break;

        case '3':
        creditos();
        break;

        case '0':

        rlutil::cls();
        cout << "Gracias por jugar nuestro juego." << endl;
        rltuil::anykey("Presione una tecla para continuar...");
        cout << endl;
            
        return;

        default:
        rlutil::cls();
        rltuil::anykey("Opcion incorrecta. Intente de nuevo.");
        cout << endl;  

        break;
    }
}
