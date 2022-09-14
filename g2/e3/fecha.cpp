#include "fecha.h"


using namespace POO22;
using namespace std;

int fecha::_format = 1;
static const char* months[] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio",
                               "Agosto","Septiembre","Octubre","Noviembre","Diciembre"};

fecha::fecha(int day,int month, int year){
    _day = day;
    _month = month;
    _year = year;
}

void fecha::setFecha(int day, int month, int year){
    fecha test = fecha(day,month,year);
    if (test.validarFecha()){
        _day = day;
        _month = month;
        _year = year;
    }
    return;
}

void fecha::setDay(int day){
    fecha test = fecha(day,getMonth(),getYear());
    if (test.validarFecha()){
        _day = day;
    }
    return;
}

void fecha::setMonth(int month){
    fecha test = fecha(getDay(),month,this->getYear());
    if (test.validarFecha()){
        _month = month;
    }
    return;
}

void fecha::setYear(int year){
    fecha test = fecha(getDay(),this->getMonth(),year);
    if (test.validarFecha()){
        _year = year;
    }
    return;
}

void fecha::setFormat(int value){
    _format = value;
    return;
}

int fecha::getDay(){
    return _day;
}

int fecha::getMonth(){
    return _month;
}

int fecha::getYear(){
    return _year;
}

int fecha::getFormat(){
    return _format;
}

void fecha::ingresarFecha(){
    int d,m,a;
    bool valid = false;
    while (!valid){
        cout << "Ingrese una fecha: " << endl;
        cout << "Dia: ";
        cin >> d;
        cout << "Mes: ";
        cin >> m;
        cout << "A" << char(164) << "o: ";
        cin >> a;
        setFecha(d,m,a);
        valid = validarFecha();
    }
    return;
}

void fecha::imprimir(){
    switch (getFormat()){
        case 0:
            cout << getDay() << '/' << getMonth() << '/' << getYear() << endl;
            break;
        case 1:
            cout << getYear() << '/' << getMonth() << '/' << getDay() << endl;
            break;
        case 2:
            cout << getMonth() << '/' << getDay() << '/' << getYear() << endl;
            break;
    }

    return;
}

char* fecha::mesLetras(){
    int m = getMonth()-1;
    int sz = strlen(months[m])+1;

    char *str = static_cast<char *>(calloc(sz, sizeof(char)));
    strncpy(str, months[m],sz);
    return str;
}

ostream& POO22::operator << (ostream& co, fecha& date){

    co << date.getDay() << " de " << date.mesLetras() << " de " << date.getYear();
    return co;
}

bool fecha::validarFecha(){
    bool r = (_day > 0 && _month > 0 && _month <= 12 && _year > 0);
    if (r){
        if (_month == 2){
            r = (_day<=28);
        }
        else if(_month == 4 || _month == 6 || _month == 9 || _month == 11){
            r = (_day<=30);
        }
        else{
            r = (_day<=31);
        }
    }
    return r;
}
