#include <iostream>
#include <cstdlib>
#include "funciones.h"
#include "menu.h"
#include "rlutil.h"

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
    string carta, figura;

    for(int i = 0; i < tam; i++) {

        obtenerCarta(v[i], valor, carta, figura);
        cout << "|  " << carta << " de " << figura << "         |"<< endl;

    }
}

void obtenerCarta(int id, int &valor, string &carta, string &figura) { /// Tiene las figuras y los valores con sus cartas correspondientes

    const string figuras[4] = {"Corazones", "Diamantes", "Treboles", "Picas"};

    const string cartas[5] = {"A", "10", "J", "Q", "K"};
    const int valoresCartas[5] = {20, 10, 11, 12, 15};

    int c = 0;
    int p = 0;

    /// Calcula el palo de la carta 1x1

    for(int i = 0; i < 5; i++){
        if(id >= 5){
            id -= 5;
            p++;
        }
        else{
            break;
        }
    }

    /// Calcula el valor de la carta 1x1

    for(int i = 0; i < 4; i++){
        if(id > 0){
            id--;
            c++;
        }
        else{
            break;
        }
    }

    valor = valoresCartas[c];
    carta = cartas[c];
    figura = figuras[p];
}

void embaucadora (int v[], int tam, string &figura){ /// Genera la carta embaucadora

    int numerosAleatorios = rand() % 4; /// Genera 4 numeros aleatorios desde el 0 al 3 para seleccionar el palo
    int id = numerosAleatorios * 5;
    int valor;
    string carta;

    obtenerCarta(id, valor, carta, figura);

    cout << figura;

}

/// PRIMERA RONDA -----------------------------------------------------------------------------------------------------

void primeraRonda(string primerJugador, string segundoJugador){

    /// Tamaño del vector
    const int tam = 5;
    int mano1[tam];
    int mano2[tam];

    /// Acumuladores de puntos de cada jugador
    int puntos1 = 0; /// Puntos del Jugador 1
    int puntos2 = 0; /// Puntos del jugador 2

    /// Variables de la funcion
    string figura1, figura2;
    int valor;
    string carta;

    /// Opcion si el jugador quiere cambiar la carta embaucadora si elije que si l acambia
    string embauca;


   for (int y = 1; y <= 3; y++){

    cout << "EMBAUCADO" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "RONDA #"<<y << endl;
    cout << primerJugador  << " Vs " << segundoJugador << endl << endl;
    cout << "+-------------------------+" << endl;
    cout << "|                         |" << endl;
    cout << "| " << primerJugador << " (" << puntos1 << " puntos)       |" << endl;

    /// Mano del Jugador #1
    generarMano(mano1, tam);

    /// Verifica si la mano no tiene cartas repetidas
    while(verificarMano(mano1, tam) != true){
        generarMano(mano1, tam);
    }

    /// Ordena la mano
    ordenarMano(mano1, tam);

    /// Muestra ya la mano ordenada por la funcion anterior
    mostrarMano(mano1, tam);


    cout << "|                         |" << endl;
    cout << "|                         |" << endl;
    cout << "|                         |" << endl;

    cout << "| " << segundoJugador << " (" << puntos2 << " puntos)       |" << endl;

    /// Mano del Jugador #2
    generarMano(mano2, tam);

    /// Verifica si la mano no tiene cartas repetidas
    while(verificarMano(mano2, tam) != true){
        generarMano(mano2, tam);
    }

    /// Ordena la mano
    ordenarMano(mano2, tam);

    /// Muestra ya la mano ordenada por la funcion anterior
    mostrarMano(mano2, tam);

    cout << "|                         |" << endl;
    cout << "|  Embaucadora: ";
    embaucadora(mano1, tam, figura1); /// Muestra la carta embaucadora - figura 1
    cout << "  |" << endl;
    cout << "|                         |" << endl;
    cout << "+-------------------------+" << endl;


/// Cambio de carta embaucadora -----------------------------------------------------------------------------------------

    if(y > 1){

    cout << primerJugador << ", quiere cambiar la carta embaucadora? (pica) ";

    cout << "(S/N): ";
    cin >> embauca;

    cout << endl;

    if(embauca == "S" || embauca == "s"){

    cout << "+-------------------------+" << endl;
    cout << "|                         |" << endl;
    cout << "| Nueva Embaucadora: ";

    embaucadora(mano1, tam, figura2); /// Muestra la carta embaucadora - figura 1

    cout << "|" << endl;

    cout << "|                         |" << endl;
    cout << "+-------------------------+" << endl;
    rlutil :: anykey();

    }

    }
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
        cout << " + " << valor;
        puntos1+=valor;
        }
    }

    cout << " = " << puntos1 << " puntos" << endl; /// fin del texto

/// Puntos del Jugador 2

    cout << segundoJugador << ": "; /// incio del texto

    for(int j = 0; j < tam; j++){
    obtenerCarta(mano2[j], valor, carta, figura2);

        if(figura2 == figura1){
        puntos2 -= 0;
        }
        else{
        cout << " + " << valor;
        puntos2+=valor;
        }
    }

    cout << " = " << puntos2 << " puntos" << endl; /// fin del texto
    cout << endl;
    rlutil::anykey("Presione una tecla para continuar...");
    cout << endl << endl;
    }

}

/// SEGUNDA RONDA -----------------------------------------------------------------------------------------------------


/// La organizacion general de las manos -----------------------------------------------------------------------------

int contarNumeros(int v[], int tam, int numero){ /// Cuenta si algun numero entre las cartas se repite

    int cont = 0;
    for(int i = 0; i < tam; i++){
        if(v[i] == numero){
        cont++;
        }
    }

    return cont; /// devuelve cuantos numeros dentro del vector estan repetidos
}

bool verificarMano(int v[], int tam){ /// Si llevan a haber dos cartas iguales returna true sino false

    for(int i = 0; i < tam; i++){

        if(contarNumeros(v,tam,v[i]) > 1){

            return false; /// Si devuelve 'false' es porque el contador es mayor a 1 osea que si hay numeros que se repiten
        }
    }
    return true; /// Si devuelve 'true' es porque el cont esta en 0, lo que signific que los numeros no se repiten
}

void ordenarMano(int v[], int tam){ /// Ordena los naipes de menor a mayor

    int aux;

    for (int i= 0; i < tam; i++){
        for (int j= i +1; j < tam; j++){
            if(v[j] < v[i]){
                aux = v[j];
                v[j]=v[i];
                v[i]=aux;
            }
        }
    }
}

/// Opciones del menu ------------------------------------------------------------------------------------------------------


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
