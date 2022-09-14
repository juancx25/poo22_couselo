#include "tiempo.h"

using namespace POO22;

/*  Date format:
    0: HH:MM:SS (standard)
    1: HH:MM
*/
int tiempo::_format = 0;


tiempo::tiempo(int h=0,int m=0,int s=0){
    _hora = h;
    _min = m;
    _seg = s;
}

void tiempo::setHora(int h){
    _hora = h;
    return;
}
void tiempo::setMinutos(int m){
    _min = m;
    if (!validar()){
        acarrear();
    }
    return;
}
void tiempo::setSegundos(int s){
    _seg = s;
    if (!validar()){
        acarrear();
    }
    return;
}

void tiempo::setTiempo(int h,int m,int s){
    _hora = h;
    _min = m;
    _seg = s;
    if (!validar()){
        acarrear();
    }
}

int tiempo::getHora(){
    return _hora;
}

int tiempo::getMinutos(){
    return _min;
}

int tiempo::getSegundos(){
    return _seg;
}

int tiempo::getFormat(){
    return _format;
}

ostream& POO22::operator << (ostream& os,tiempo& t){
    switch (t.getFormat()){
        case 0:
            os << t.getHora()  << ':' << t.getMinutos() << ':' << t.getSegundos();
            break;
        case 1:
            os << t.getHora() << ':' << t.getMinutos();
            break;
    }
    return os;
}

bool tiempo::validar(){
    bool r = false;
    r = ((_min < 60) && (_seg < 60));
    return r;
}

void tiempo::acarrear(){
    while (_seg >= 60){
        _seg -= 60;
        _min++;
    }
    while (_min >= 60){
        _min -= 60;
        _hora++;
    }
}

void tiempo::ingresarDatos(){
    cout << "Horas: ";
    cin >> _hora;
    cout << "Minutos: ";
    cin >> _min;
    cout << "Segundos: ";
    cin >> _seg;
    if (!validar()) acarrear();
}