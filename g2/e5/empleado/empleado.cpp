#include "empleado.h"

using namespace std;
using namespace POO22;

empleado::empleado(string& first_name,string& last_name,fecha& birth_date,string& address,string& dni,fecha& hiring_date){
    _first_name = first_name;
    _last_name = last_name;
    _birth_date = birth_date;
    _address = address;
    _dni = dni;
    _hiring_date = hiring_date;
}


empleado::empleado(string& first_name,string& last_name,int b_day,int b_month,int b_year,string& address,string& dni,int h_day,int h_month,int h_year){
    _first_name = first_name;
    _last_name = last_name;
    _birth_date = fecha(b_day,b_month,b_year);
    _address = address;
    _dni = dni;
    _hiring_date = fecha(h_day,h_month,h_year);
}



fecha& empleado::getHiringDate(){ return _hiring_date; }

void empleado::setHiringDate(fecha& h_date){
    _hiring_date = h_date;
}

void empleado::setHiringDate(int day,int month,int year){
    _hiring_date = fecha(day,month,year);
    return;
}

ostream& POO22::operator <<(ostream& os,empleado& e){

    os << e.getLastName() << ", " << e.getFirstName() << endl
    << "Contratado el: " << e.getHiringDate() << endl
    << "Fecha de Nacimiento: " << e.getBirthDate() << endl;
    return os;
}
