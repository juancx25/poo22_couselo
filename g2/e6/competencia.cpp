#include "competencia.h"

#include <iostream>
#include <vector>
#include <iomanip>

using namespace POO22;
using namespace std;

void print_list(vector<ciclista*> v){
    cout << "Nombre" << setw(30) << "Apellido" << setw(30) << "Tiempo p1" << setw(30) << "Vueltas p2" << endl << endl;
    for (unsigned int i=0;i<v.size();i++){
        cout <<  v[i]->getFirstName()  << setw(30) << v[i]->getLastName()  << setw(30) << v[i]->getTest1()  << setw(30) << v[i]->getTest2() << endl;
    }
}
