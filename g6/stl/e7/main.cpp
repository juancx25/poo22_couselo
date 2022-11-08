#include <iostream>
#include "empleado.h"
#include "files.h"
#include <vector>
#include <conio.h>

using namespace std;

void agregar_empleado(vector<empleado>& v){
    empleado* aux = new empleado();
    v.push_back(*aux);
}

void imprimir_empleados(const vector<empleado>& v){
    if (v.size()==0){
        cout << "No hay empleados" << endl;
    }
    else{
        cout << "Lista de empleados:" << endl;
        for (vector<empleado>::const_iterator it = v.begin() ; it != v.end() ; ++it){
            cout << *it << endl;
        }
    }

}

vector<empleado> buscar_empleados(const vector<empleado>& v){
    vector<empleado> found;
    string ap;
    cout << "Introduzca el apellido del/los empleado/s a buscar: "; cin >> ap;

    for (vector<empleado>::const_iterator it = v.begin() ; it != v.end() ; ++it){
        empleado aux = *it;
        if (aux.getApellido() == ap){
            found.push_back(*it);
        }
    }

    return found;
}

void eliminar_empleado(vector<empleado>& v){
    string ap;
    cout << "Introduzca el apellido del empleado a eliminar: "; cin >> ap;

    vector<empleado>::iterator it = v.begin();
    bool found = false;
    while ((!found) && (it!=v.end())){
        empleado aux = *it;
        if (aux.getApellido() == ap){
            v.erase(it);
            cout << aux << " eliminado correctamente." << endl;
            found = true;
        }
        else ++it;
    }
}

void esperar_tecla(){ cout << "Presione una tecla para continuar"; getch(); }

int main()
{
    vector<empleado> proletariado;
    leer_empleados("emp.txt",proletariado);
    int menu;
    do{
        system("cls");
        cout << "-Sistema Empleados-" << endl;
        cout << "Agregar...........1" << endl;
        cout << "Imprimir todos....2" << endl;
        cout << "Buscar............3" << endl;
        cout << "Eliminar..........4" << endl;
        cout << "Salir.............5" << endl;
        cin >> menu;

        switch (menu){

        case 1:{
            agregar_empleado(proletariado);
            break;
        }

        case 2:{
            imprimir_empleados(proletariado);
            esperar_tecla();
            break;
        }

        case 3:{
                vector<empleado> found = buscar_empleados(proletariado);
                imprimir_empleados(found);
                esperar_tecla();
                found.clear();
                break;
            }

        case 4:{
                eliminar_empleado(proletariado);
                esperar_tecla();
                break;
            }

        }

    } while (menu != 5);
    guardar_empleados("emp.txt",proletariado);
    return 0;
}
