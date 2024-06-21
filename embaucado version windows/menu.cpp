#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include "menuheader.h"
#include "rlutil.h"

using namespace std;

void menu ()
{
    int opcion=7;
   while (opcion!=0){

    cout<<"EMBAUCADO"<<endl;
    cout<<"======================="<<endl;
    cout<<"1 - JUGAR            ||"<<endl;
    cout<<"2 - ESTADISTICAS     ||"<<endl;
    cout<<"3 - CREDITOS         ||"<<endl;
    cout<<"======================="<<endl;
    cout<<"0 - Salir"<<endl;
    cin>>opcion;
    switch (opcion)
    {
    case 1:
        system("cls");
        juego();
        break;
    case 2:
        break;
    case 3:
        creditos();
        break;

    default:
        break;
    }
   system("cls");



   }
}
void creditos()
{
      cout << "CREDITOS" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "APELLIDO       NOMBRES     LEGAJOS" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << " Laborde        Tomas       28895" << endl;
    cout << " Alderete       Kevin       30199" << endl;
    cout << "  Cayo          Nicole      30283" << endl << endl;
    system("pause");
    system("cls");
}



int numerorandom(int taman)
{
    return rand() %taman + 0;
}





void juego()
{
    const int tam=5;
    const int tam2=4;
    int puntost[5]={10,11,12,15,20};
    int puntosacu[2];
    puntosacu[0]=0;
    puntosacu[1]=0;
    string respuesta="n";
    string respuestaembauc;
    string nombre1,nombre2;
    string carta[tam];
    string palo[tam2];

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

    cout<<"ingrese el nombre del jugador 1: "<<endl;
    cin>>nombre1;
    cout<<"ingrese el nombre del jugador 2: "<<endl;
    cin>>nombre2;
    system("cls");
    cout<<"estos son los nombres que elegiste "<<endl;
    cout<<nombre1<<endl;
    cout<<nombre2<<endl;
    cout<<"confirmar nombres? (S/N)"<<endl;
    cin>>respuesta;
    system("cls");
    }
    system("cls");
  string auxembauc;
    for (int i=1;i<=3 ;i++ )
    {
        auxembauc=palo[numerorandom(tam2)];
        if (i==2)
            {
                cout<<"jugador 1 quiere cambiar la carta embaucadora?"<<endl;
                cout<<"(S/N)"<<endl;
                cin>>respuestaembauc;
                if(respuestaembauc=="s")
                {
                    auxembauc=palo[numerorandom(tam2)];
                }
                else
                {
                    cout<<"jugador 2 quiere cambiar la carta embaucadora?"<<endl;
                    cout<<"(S/N)"<<endl;
                    cin>>respuestaembauc;
                    if(respuestaembauc=="s")
                    {
                        auxembauc=palo[numerorandom(tam2)];
                    }
                }
            }
       if (i==3)
            {
                cout<<"jugador 2 quiere cambiar la carta embaucadora?"<<endl;
                cout<<"(S/N)"<<endl;
                cin>>respuestaembauc;
                if(respuestaembauc=="s")
                {
                    auxembauc=palo[numerorandom(tam2)];
                }
                else
                {
                    cout<<"jugador 1 quiere cambiar la carta embaucadora?"<<endl;
                    cout<<"(S/N)"<<endl;
                    cin>>respuestaembauc;
                    if(respuestaembauc=="s")
                    {
                        auxembauc=palo[numerorandom(tam2)];
                    }
                }
                system("cls");
            }
        cout<<"RONDA "<<i<<endl;
        cout<<"===================="<<endl;
        cout<<"    JUGADOR 1      |"<<endl;
        string auxpalo;
        int auxcarta;
        for (int j1=1;j1<=5 ;j1++ )
            {
                auxpalo=palo[numerorandom(tam2)];
                auxcarta=numerorandom(tam);
                cout<<carta[auxcarta]<<" "<<auxpalo<<endl;
                if(auxpalo!=auxembauc)
                {
                    puntosacu[0]+=puntost[auxcarta];
                }
            }
        cout<<"PUNTOS DEL JUGADOR 1: "<<puntosacu[0]<<endl;
        cout<<"===================="<<endl;
        cout<<"    JUGADOR 2      |"<<endl;
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
        cout<<"puntos del jugador 2: "<<puntosacu[1]<<endl;
        cout<<"===================="<<endl;
        cout<<"  CARTA EMBAUCADORA "<<endl;
        cout<<auxembauc<<endl;

        system("pause");
        system("cls");
    }

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
    system("pause");


}


