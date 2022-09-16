#include "becario.h"

using namespace std;
using namespace POO22;

becario::becario(string& first_name,string& last_name,fecha& birth_date,string& address,unsigned int dni,
        string& career,int subjects,fecha& entry_date,float average,
        string& category,fecha& start_date,float salary,
        string& type,int duration,string& lab, string& director) :

        empleado(first_name,last_name,birth_date,address,dni,category,start_date,salary),
        estudiante(first_name,last_name,birth_date,address,dni,career,subjects,entry_date,average)
{
    _type = type;
    _duration = duration;
    _lab = lab;
    _director = director;
}

/* ----- Getters ----- */
string becario::getType() { return _type; }
int becario::getDuration() { return _duration; }
string becario::getLab() { return _lab; }
string becario::getDirector() { return _director; }

/* ----- Setters ----- */
void becario::setType(string& type) { _type = type; }
void becario::setDuration(int duration) { _duration = duration; }
void becario::setLab(string& lab) { _lab = lab; }
void becario::setDirector(string& director) { _director = director; }

/* ----- I/O methods ----- */
ostream& POO22::operator << (ostream& os,becario& b){
    os << b.estudiante::getLastName() << ", " << b.estudiante::getFirstName() << endl;
    os << "DNI: " << b.estudiante::getDNI() << " | Fecha Nac.: " << b.estudiante::getBirthDate()
    << " | Direccion: " << b.estudiante::getAddress() << endl;

    os << "Carrera: " << b.estudiante::getCareer() << " | Materias: " << b.estudiante::getSubjects()
    << " | Fecha ingreso: " << b.estudiante::getEntryDate() << " | Promedio: " << b.estudiante::getAverage() << endl;

    os << "Categoria: " << b.empleado::getCategory() << " | Fecha inicio: "
    << b.empleado::getStartDate() << " | Sueldo: " << b.empleado::getSalary() << endl;

    os << "Tipo beca: " << b.getType() << " | Duracion: " << b.getDuration() <<
    " | Laboratorio: " << b.getLab() << " | Director: " << b.getDirector() << endl;

    return os;
}
