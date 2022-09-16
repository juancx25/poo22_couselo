#include "estudiante.h"
#include <iostream>
using namespace std;
using namespace POO22;

/* ----- Constructors ----- */
estudiante::estudiante(){

}

estudiante::estudiante(string& first_name,string& last_name,fecha& birth_date,string& address,unsigned int dni,string& career,int subjects,fecha entry_date,float average):
            persona(first_name,last_name,birth_date,address,dni)
{
    _career = career;
    _subjects = subjects;
    _entry_date = entry_date;
    _average = average;

}

estudiante::estudiante(string& first_name,string& last_name,int b_day,int b_month,int b_year,string& address,unsigned int dni,string& career,int subjects,int e_day,int e_month,int e_year,float average) :
            persona(first_name,last_name,b_day,b_month,b_year,address,dni) {

    _career = career;
    _subjects = subjects;
    _entry_date = fecha(e_day,e_month,e_year);
    _average = average;

}

/* ----- Getters ----- */
string estudiante::getCareer() { return _career; }
int estudiante::getSubjects() { return _subjects; }
fecha& estudiante::getEntryDate() { return _entry_date; }
float estudiante::getAverage() { return _average; }

/* ----- Setters ----- */
void estudiante::setCareer(string& career) { _career = career; }
void estudiante::setSubjects(int subjects) { _subjects = subjects; }
void estudiante::setEntryDate(fecha& entry_date) { _entry_date = entry_date; }
void estudiante::setEntryDate(int e_day,int e_month,int e_year) { _entry_date.setFecha(e_day,e_month,e_year); }
void estudiante::setAverage(float average) { _average = average; }

/* ----- I/O ----- */
ostream& POO22::operator << (ostream& os,estudiante& est){
    os << est.getLastName() << ", " << est.getFirstName();
    return os;
}
