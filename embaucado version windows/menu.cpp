#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include "menuheader.h"
#include "rlutil.h"

using namespace std;
///--------------MENU-----------------------
void menu ()
{
    string nombre1, nombre2;
    int puntJ1[3], puntJ2[3];

    int opcion=7;

   while (opcion!=0){

    cout<<"EMBAUCADO"<<endl;
    cout<<"======================="<<endl;
    cout<<"1 - JUGAR            ||"<<endl;
    cout<<"2 - ESTADISTICAS     ||"<<endl;
    cout<<"3 - CREDITOS         ||"<<endl;
    cout<<"======================="<<endl;
    cout<<"0 - Salir"<<endl << endl;
    cout << "Ingrese una opción: ";
    cin>>opcion;
    ///rlutil::cls();
    system("cls");
    switch (opcion)
    {
    case 1:
        juego(nombre1, nombre2, puntJ1, puntJ2);
        break;
    case 2:
        estadisticas(nombre1, nombre2, puntJ1, puntJ2);
        break;
    case 3:
        creditos();
        break;

    case 0:
        ///rlutil::cls();
        system("cls");
        cout << "Gracias por jugar nuestro juego! Presione una tecla para continuar." << endl;

        return;

    default:

        ///rlutil::cls();
        system("cls");
        ///rlutil::anykey("Opcion incorrecta. Intente de nuevo.");
        system("pause");

        cout << endl << endl;

        break;
        }
    }
}
///----------------------------------------------------------------------------------------

//--------------------------CREDITOS-----------------------------------------------------------
void creditos()
{
      cout << "CREDITOS" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "APELLIDO       NOMBRES     LEGAJOS" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << " Laborde        Tomas       28895" << endl;
    cout << " Alderete       Kevin       30199" << endl;
    cout << "  Cayo          Nicole      30283" << endl << endl;

    ///rlutil::anykey();

    system("pause");
}
//-------------------------------------------------------------------------------------------------

//funcion para sacar un numero random
int numerorandom(int taman)
{
    return rand() %taman + 0;
}




///------------------------ funcion de la partida   ------------------
int juego(string &nombre1, string &nombre2, int puntJ1[], int puntJ2[])
{
    const int tam=5;
    const int tam2=4;
    int puntost[5]={10,11,12,15,20};
    int puntosacu[2];
    puntosacu[0]=0;
    puntosacu[1]=0;
    string respuesta="n";
    string respuestaembauc;
    string carta[tam];
    string palo[tam2];

    /// aca en en cada espacio del  vector guarda los numeros y palo

    carta[0]="10";
    carta[1]="J";
    carta[2]="Q";
    carta[3]="K";
    carta[4]="A";

    palo[0]="corazon          |";
    palo[1]="diamante         |";
    palo[2]="pica             |";
    palo[3]="trebol           |";

    while (respuesta!="s")
    {
    cout<< "EMBAUCADO"<< endl;
    cout<<"======================="<<endl;
    cout<<"Antes de comenzar deben registrar sus nombres:";
    cout<<endl<<endl;
    cout<<"Ingrese el nombre del jugador 1: ";
    cin>>nombre1;
    cout<<"Ingrese el nombre del jugador 2: ";
    cin>>nombre2;
    ///rlutil::cls();
    system("cls");
    cout<<"Estos son los nombres que elegiste:"<<endl;
    cout<<"Jugador 1: "<<nombre1<<endl;
    cout<<"Jugador 2: "<<nombre2<<endl << endl;
    cout<<"Confirmar nombres? (S/N): ";
    cin>>respuesta;
    ///rlutil::cls();
    system("cls");
    }
    ///rlutil::cls();
    system("cls");

/// esta variable es para guardar la carta embaucadora en una auxiliar

  string auxembauc;

/// aca comienza el juego con las 3 rondas

    for(int i=1; i<=3; i++){

        if(i==1){
            auxembauc=palo[numerorandom(tam2)];
        }

    ///pregunta por la ronda para saber si pide cambiar la carta
        else if(i==2){

                cout<<nombre1<<", quiere cambiar la carta embaucadora?";
                cout<<"(S/N): ";
                cin>>respuestaembauc;

                if(respuestaembauc=="s"||respuestaembauc=="S"&&puntosacu[0]>20){

                    puntosacu[0]-=20;
                    auxembauc=palo[numerorandom(tam2)];
                }
                else if(respuestaembauc=="n"||respuestaembauc=="N"){

                    cout<<nombre2<<", quiere cambiar la carta embaucadora?";
                    cout<<"(S/N): ";
                    cin>>respuestaembauc;

                    if(respuestaembauc=="s"||respuestaembauc=="S"&&puntosacu[1]>20)
                    {
                        puntosacu[1]-=20;
                        auxembauc=palo[numerorandom(tam2)];
                    }
                }
        }

        else
            {
                cout<<nombre2<<", quiere cambiar la carta embaucadora? ";
                cout<<"(S/N): ";
                cin>>respuestaembauc;
                if(respuestaembauc=="s"||respuestaembauc=="S"&&puntosacu[1]>20)
                {
                    puntosacu[1]-=20;
                    auxembauc=palo[numerorandom(tam2)];
                }
                else if(respuestaembauc=="n"||respuestaembauc=="N")
                {
                    cout<<nombre1<<", quiere cambiar la carta embaucadora?"<<endl;
                    cout<<"(S/N): ";
                    cin>>respuestaembauc;
                    if(respuestaembauc=="s"||respuestaembauc=="S"&&puntosacu[0]>20)
                    {
                        puntosacu[0]-=20;
                        auxembauc=palo[numerorandom(tam2)];
                    }
                }
                ///rlutil::cls();
                ///system("cls");
            }

    /// empieza la ronda y el i es para que marque el numero de ronda con el reloj del for
        cout<<"RONDA "<<i<<endl;
        cout<<"===================="<<endl;
        cout<<nombre1<<" ("<<puntosacu[0]<<" puntos)"<<endl;
        string auxpalo;
        int auxcarta;
        for (int j1=1;j1<=5;j1++)
            {

            ///aca calcula el palo y el  numero de la carta para poder acumularlo
                auxpalo=palo[numerorandom(tam2)];
                auxcarta=numerorandom(tam);
                cout<<carta[auxcarta]<<" "<<auxpalo<<endl;
                if(auxpalo!=auxembauc)
                {
                    puntosacu[0]+=puntost[auxcarta];
                }
            }
        puntJ1[i-1]=puntosacu[0];
        cout<<"PUNTOS DEL JUGADOR 1: "<<puntosacu[0]<<endl;
        cout<<"===================="<<endl;
        cout<<nombre2<<" ("<<puntosacu[1]<<" puntos)"<<endl;
        for (int j2=1;j2<=5 ;j2++ )
            {
                auxpalo=palo[numerorandom(tam2)];
                auxcarta=numerorandom(tam);
                cout<<carta[auxcarta]<<" "<<auxpalo<<endl;
                if (auxpalo!=auxembauc)
                {
                    puntosacu[1]+=puntost[auxcarta];
                }
            }
        puntJ2[i-1]=puntosacu[1];
        cout<<"puntos del jugador 2: "<<puntosacu[1]<<endl;
        cout<<"===================="<<endl<<endl;
        cout<<"CARTA EMBAUCADORA: " << auxembauc<<endl<<endl;
        system("pause");
        system("cls");

}
///luego de que termina el for de 3 muestra el ganador
    cout<<"==================================="<<endl;
    cout<<"GANADOR                            "<<endl;
    cout<<"el ganador es: ";
    if (puntosacu[0]>puntosacu[1])
    {
        cout<<nombre1<<endl;
    cout<<"==================================="<<endl;
        cout<<"con "<<puntosacu[0]<<" puntos"<<endl;
    cout<<"==================================="<<endl;
    }
    else
    {
        cout<<nombre2<<endl;
    cout<<"==================================="<<endl;
        cout<<"con "<<puntosacu[1]<<" puntos"<<endl;
    cout<<"==================================="<<endl;
    }
    ///rlutil::anykey();
    system("pause");
    return 0;

}

///----------funcion para las estadisticas--------------------
int estadisticas(string &nombre1, string &nombre2, int puntJ1[], int puntJ2[])
{
    int cero;
    int acumulador1=0;
    int acumulador2=0;

    cout<<"EMBAUCADO"<<endl;
    cout<<"========================================================================"<<endl<<endl;
    cout <<"RONDA       "<<nombre1<<"       "<<nombre2<<endl;
    cout<<"------------------------------------------------------------------------"<<endl<<endl;
    for(int x=1;x<=3;x++){
        cout<<x+1<<"           "<<puntJ1[x]<<"       "<<puntJ2[x]<<endl;
        acumulador1+=puntJ1[x];
        acumulador2+=puntJ2[x];
    }
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"TOTAL       "<<acumulador1<<"       "<<acumulador2<<endl<<endl;
    if(acumulador1>acumulador2){
        cout<<"GANADOR: "<<nombre1<<" con "<<acumulador1<<" puntos de victoria."<<endl<<endl;
    }
    else{
        cout<<"GANADOR: "<<nombre2<<" con "<<acumulador2<<" puntos de victoria."<<endl<<endl;
    }
    cout<<"Presione 0 para continuar...";
    cin>>cero;
    if(cero==0){
        system("cls");
    }
}

///--------------------------------------------------------------
