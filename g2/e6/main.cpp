#include "competencia.h"

#include <iostream>
#include <vector>
#include <conio.h>

using namespace POO22;
using namespace std;

int main()
{
    ciclista* c;
    vector<ciclista*> competidores;
    int item = 0;
    do
    {
        system("cls");
        cout << "*--- COMPETENCIA DE CICLISMO ---*" << endl;
        cout << "Agregar ciclista................1" << endl;
        cout << "Remover ciclista................2" << endl;
        cout << "Ver listado.....................3" << endl;
        cout << "Salir...........................4" << endl;
        cin >> item;
        system("cls");
        switch (item) {
            case 1:
                c = new ciclista();
                c->insert();
                competidores.push_back(c);
                break;
            case 2:

                break;
            case 3:
                print_list(competidores);
                cout << "Presione una tecla para volver";
                getch();
                break;
        }
    } while (item!=4);

    return 0;
}


