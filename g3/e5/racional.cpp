#include "racional.h"
using namespace std;
using namespace POO22;


racional::racional(){
    _num = 0;
    _den = 0;
}
racional::racional(int num, int den){
    _num = num;
    _den = den;
}

/* ----- Getters ----- */
int racional::getNum() { return _num; }
int racional::getDen() { return _den; }

/* ----- Setters ----- */
void racional::setNum(int num) { _num = num; }
void racional::setDen(int den) { _den = den; }

/* ----- I/O methods ----- */
ostream& POO22::operator << (ostream& os,racional& r){
    os << r.getNum() << '/' << r.getDen();
    return os;
}
istream& POO22::operator >> (istream& is,racional& r){
    //int aux;
    is >> r._num >> r._den;
    //is >> aux; r.setDen(aux);
    return is;
}

/* ----- Arithmetic ----- */
void simplify(racional& r){

}

racional racional::operator +(racional& b){
    return racional();
}
