#include "menu.h"
#include "funciones.h"
#include<iostream>
#include<cstdlib>
#include "rlutil.h"

using namespace std;

/// #1 - JUGAR

int jugar(){

    string primerJugador, segundoJugador;
    char rta;

    cout << "EMBAUCADO" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Antes de comenzar deben registrar sus nombres:";
    cout << endl << endl;
    cout <<"¿Nombre del Jugador 1? ";
    cin >> primerJugador;
    cout << "¿Nombre del Jugador 2? ";
    cin >> segundoJugador;
    cout << endl;
    cout << "¿Confirmar nombres? (S/N) ";
    cin >> rta;
    cout << endl;

    if (rta == 'S' || rta == 's'){

        /// Llamaria a la funcion primeraRonda

    }
        else if (rta == 'N' || rta == 'n'){

            cout << "Nombres no confimados. Intente de nuevo" << endl << endl;
            jugar();
        }

    else{
        cout << "Selección no reconocida. Intente de nuevo." << endl << endl;
        jugar();
}

    cout << "------------------------------------------------------------------------" << endl;

}

/// #2 - ESTADISTICAS


/// #3 - CREDITOS

void creditos(){

    cout << "CRÉDITOS" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "APELLIDO       NOMBRES     LEGAJOS" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << " Laborde        Tomas       28895" << endl;
    cout << " Alderete       Kevin       30199" << endl;
    cout << "  Cayo          Nicole      30283" << endl << endl;

}
