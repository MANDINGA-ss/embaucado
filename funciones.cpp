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

/// #1 - Jugar ------------------------------------------------------------------------------------------------------

/// PRIMERA RONDA

void primeraRonda(int v[], int tam){



}
