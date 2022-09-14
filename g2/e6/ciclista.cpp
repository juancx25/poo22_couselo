#include "ciclista.h"
#include <iostream>
#include <vector>


using namespace POO22;
using namespace std;

ciclista::ciclista(){
    _first_name = "";
    _last_name = "";
    _birth_date = fecha();
    _address = "";
    _dni = "";
    _test1 = 0;
    _test2 = 0;
}

ciclista::ciclista(string& first_name,string& last_name,fecha& birth_date,
                   int test1,int test2){

    _first_name = first_name;
    _last_name = last_name;
    _birth_date = birth_date;
    _address = "";
    _dni = "";
    test1 = test1;
    test2 = test2;
}


int ciclista::getTest1() { return _test1; }
int ciclista::getTest2() { return _test2; }

void ciclista::setTest1(int test1) { _test1 = test1; }
void ciclista::setTest2(int test2) { _test2 = test2; }

int getAge(){
    return 0;
}

void ciclista::insert(){
    cout << "Nombre: "; cin >> _first_name;
    cout << endl << "Apellido: "; cin >> _last_name;
    cout << endl << "Fecha de nacimiento: " << endl;
    _birth_date.ingresarFecha();
    cout << endl << "Tiempo en 1ra prueba: "; cin >> _test1;
    cout << endl << "Cant. vueltas 2da prueba: "; cin >> _test2;
}

ostream& POO22::operator << (ostream& os,ciclista& c){
    os << c.getFirstName() << " " << c.getLastName() << endl;
    return os;
}
