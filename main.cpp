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

    char menu;

    while(true){

    cout << "EMBAUCADO" << endl;
    cout << "---------------------" << endl;
    cout << "1 - JUGAR"<< endl;
    cout << "2 - ESTADÍSTICAS"<< endl;
    cout << "3 - CRÉDITOS"<< endl;
    cout << "---------------------" << endl;
    cout << "0 - SALIR" << endl << endl;

    cout << "Ingrese una opción: ";
    cin >> menu;

    cout << endl;
    rlutil::cls(); /// Limpia la pantalla

    switch(menu){

    case '1':
        jugar();
        break;

    case '2':
        /// Estadisticas
        break;

    case '3':
        creditos();
        break;

    case '0':

        rlutil::cls(); /// Limpia la pantalla - system("cls");
        cout << "Gracias por jugar nuestro juego." << endl;
        rlutil::anykey("Presione una tecla para continuar..."); /// Pausa la ejecucion antes de contestar - system("pause")

        cout << endl;

        return 0;

    default:

        rlutil::cls(); /// Limpia la pantalla

        rlutil::anykey("Opcion incorrecta. Intente de nuevo."); /// Pausa la ejecucion antes de contestar

        cout << endl << endl;

        break;

        }

        return 0;
    }

        return 0;

}
/**

srand(time(0));

    const int tam = 5;
    int mano[tam];

    do{
        generarMano(mano, tam);
    }
    while(verificarMano(mano, tam) != true);

    ordenarMano(mano, tam);
    mostrarMano(mano, tam);

    cout << "-------------" << endl;
    cartaEmbaucadora(mano, tam);

    cout << "-------------" << endl;
    primeraRonda(mano, tam);

*/
