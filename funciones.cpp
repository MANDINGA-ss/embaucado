#include <iostream>
#include <cstdlib>
#include "funciones.h"
#include "menu.h"

using namespace std;

int generarNroAleatorio(){ /// Genera 20 numeros aleatorios

    return rand() % 20; /// Genera numeros entre el 0 y 19
}

void generarMano(int v[], int tam){ /// Genera la mano

    for(int i = 0; i < tam; i++){
        v[i]= generarNroAleatorio();
    }
}

void mostrarMano(int v[], int tam){ /// Muestra la mano

    int valor;
    string nombre;
    string palo;

    for(int i = 0; i < tam; i++) {

        obtenerCarta(v[i], valor, nombre, palo);
        cout << nombre << " de " << palo << endl;

    }
}

/// Las cartas con sus figuras y naipes con sus valores correspondientes

void obtenerCarta(int id, int &valor, string &nombre, string &palo) {

    const string palos[] = {"Corazones", "Diamantes", "Treboles", "Picas"};

    const string nombresDeLosNaipes[] = {"A", "10", "J", "Q", "K"};
    const int valoresDeLosNaipes[] = {20, 10, 11, 12, 15};

    int p = id / 5; /// Palo de la carta
    int n = id % 5; /// Valor del naipe/carta

    nombre = nombresDeLosNaipes[n]; /// Se le asigna como el nombre de la carta corresp, al valor 'n'
    palo = palos[p]; /// Se le asigna como palo corresp. al valor 'p'
    valor = valoresDeLosNaipes[n]; /// Se le asigna como el valor numero corresp. al valor 'n'
}

void cartaEmbaucadora (int v[], int tam){

    int nrosAleat = rand() % 4; /// Genera 4 numeros alteatorios desde el 0 al 3 para seleccionar el palo

    int id = nrosAleat * 5; /// Calcula el indice desde la primera carta del palo y segun el nro aleatorio que toque dentro del id va a ir mostrando el palo correspondiente

    int valor;
    string nombre, palo;

    obtenerCarta(id, valor, nombre, palo);

    cout << "Carta embaucadora: " << palo << endl;

}

/// Primera Ronda #1 -------------------------------------------------------------------------------------------------------------------------------------------

void primeraRonda(string primerJugador, string segundoJugador){

    /// Tamaño del vector
    const int tam = 5;
    int mano1[tam];
    int mano2[tam];

    /// Acumuladores de puntos de cada jugador
    int puntos1 = 0; /// Puntos del Jugador 1
    int puntos2 = 0; /// Puntos del jugador 2

    ///
    string figura1, figura2;
    int valor;
    string carta;

    cout << "EMBAUCADO" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "RONDA #1" << endl;
    cout << primerJugador  << " Vs " << segundoJugador << endl << endl;
    cout << "+-------------------------+" << endl;
    cout << "|                         |" << endl;
    cout << "| " << primerJugador << " (" << puntos1 << " puntos)       |" << endl;

    generarMano(mano1, tam);
    mostrarMano(mano1, tam);

    cout << "|                         |" << endl;
    cout << "|                         |" << endl;
    cout << "|                         |" << endl;

    cout << "| " << segundoJugador << " (" << puntos2 << " puntos)       |" << endl;

    generarMano(mano2, tam);
    mostrarMano(mano2, tam);

    cout << "|                         |" << endl;
    cout << "|  Embaucadora: ";
    embaucadora(mano1, tam, figura1); /// Muestra la carta embaucadora - figura 1
    cout << "  |" << endl;
    cout << "|                         |" << endl;
    cout << "+-------------------------+" << endl;

    cout << endl << endl;

    cout << "Puntajes obtenidos:" << endl;
    cout << "------------------------------------------------------------------------" << endl;

/// Puntos del Jugador 1

    cout << primerJugador << ":"; /// incio del texto
    
    for(int i = 0; i < tam; i++){
    obtenerCarta(mano1[i], valor, carta, figura2);
        if(figura2 == figura1){
        puntos1 -= 0;
        }
        else{
        puntos1+=valor;
        }
    }

    cout << " = " << puntos1 << " puntos" << endl; /// fin del texto

/// Puntos del Jugador 2

    cout << segundoJugador << ": "; /// incio del texto
    
    for(int i = 0; i < tam; i++){
    obtenerCarta(mano2[i], valor, carta, figura2);
        if(figura2 == figura1){
        puntos2 -= 0;
        }
        else{
        puntos2+=valor;
        }
    }

    cout << " = " << puntos2 << " puntos" << endl; /// fin del texto

}

/// Opciones del menu -----------------------------------------------------------------------------------------------


/// #1 - JUGAR

void jugar(string &primerJugador, string &segundoJugador){

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
    cout << "------------------------------------------------------------------------" << endl << endl;

    if (rta == 'S' || rta == 's'){

            primeraRonda(primerJugador, segundoJugador);

    }
        else if (rta == 'N' || rta == 'n'){
            cout << "Nombres no confimados. Intente de nuevo" << endl << endl;
            jugar(primerJugador, segundoJugador);
        }

    else{
        cout << "Selección no reconocida. Intente de nuevo." << endl << endl;
        jugar(primerJugador, segundoJugador);
}

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
