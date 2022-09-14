#include "persona.h"

using namespace std;
using namespace POO22;

/* ----- Constructors/Destructors ----- */

persona::persona(){
    _first_name = "";
    _last_name = "";
    _birth_date = fecha();
    _address = "";
    _dni = "";
}

persona::persona(string& first_name,string& last_name,fecha& birth_date, string& address,string& dni){
    _first_name = first_name;
    _last_name = last_name;
    _birth_date = birth_date;
    _address = address;
    _dni = dni;
}

persona::persona(string& first_name,string& last_name,int day,int month,int year, string& address,string& dni){
    _first_name = first_name;
    _last_name = last_name;
    _birth_date = fecha(day,month,year);
    _address = address;
    _dni = dni;
}

/* ----- Getters ----- */

string persona::getFirstName(){ return _first_name; }
string persona::getLastName(){ return _last_name; }
fecha& persona::getBirthDate(){ return _birth_date; }
string persona::getAddress(){ return _address; }
string persona::getDNI(){ return _dni; }

/* ----- Setters ----- */

void persona::setFirstName(string& first_name){ _first_name = first_name; }
void persona::setLastName(string& last_name){ _last_name = last_name; }
void persona::setBirthDate(fecha& birth_date){ _birth_date = birth_date; }
void persona::setAddress(string& address){ _address = address; }
void persona::setDNI(string& dni){ _dni = dni; }

bool persona::setBirthDate(int day,int month,int year){
    bool result = false;
    fecha bdate = fecha();
    bdate.setFecha(day,month,year);
    if (bdate.validarFecha()){
        _birth_date = bdate;
        result = true;
    }
    return result;
}

/* ----- I/O methods ----- */

ostream& POO22::operator << (ostream& os, persona& p){
    os << p.getLastName() << ", " << p.getFirstName() << endl;
    return os;
}
