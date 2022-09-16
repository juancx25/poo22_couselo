#include "empleado.h"

using namespace std;
using namespace POO22;

empleado::empleado(string& first_name,string& last_name,fecha& birth_date,string& address,unsigned int dni,
                   string& category,fecha& start_date, float salary) :
                   persona(first_name,last_name,birth_date,address,dni){
    _category = category;
    _start_date = start_date;
    _salary = salary;
}

empleado::empleado(string& first_name,string& last_name,int b_day,int b_month,int b_year,string& address,unsigned int dni,string& category,int s_day,int s_month,int s_year,float salary):
          persona(first_name,last_name,b_day,b_month,b_year,address,dni){

    _category = category;
    _start_date = fecha(s_day,s_month,s_year);
    _salary = salary;
}

/* ----- Getters ----- */
string empleado::getCategory(){ return _category; }
fecha& empleado::getStartDate(){ return _start_date; }
float empleado:: getSalary(){ return _salary; }

/* ----- Setters ----- */
void empleado::setCategory(string& category){ _category = category; }
void empleado::setStartDate(fecha& s_date){ _start_date = s_date; }
void empleado::setStartDate(int s_day,int s_month,int s_year){ _start_date = fecha(s_day,s_month,s_year); }
void empleado::setSalary(float salary) { _salary = salary; }



ostream& POO22::operator <<(ostream& os,empleado& e){

    os << e.getLastName() << ", " << e.getFirstName() << endl
    << "Contratado el: " << e.getStartDate() << endl
    << "Fecha de Nacimiento: " << e.getBirthDate() << endl;
    return os;
}
