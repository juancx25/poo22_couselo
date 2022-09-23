#include "polinomio.h"
#include "cmath"

//monomio

monomio::monomio(){
    _coef = 0;
    _exp = 0;
}

monomio::monomio(double coef,int exp){
    _coef = coef;
    _exp = exp;
}

double monomio::getCoef(){ return _coef; }
int monomio::getExp(){ return _exp; }

void monomio::setCoef(double coef){ _coef = coef; }
void monomio::setExp(int exp){ _exp = exp; }

ostream& operator << (ostream& os,monomio& m){
    os << showpos << m._coef << 'x' << '^' << noshowpos << m._exp;
    return os;
}

//polinomio

polinomio::polinomio(){
    _elem = NULL;
    _used = 0;
    _size = 0;
}

polinomio::polinomio(int size){
    _elem = (monomio*)malloc(sizeof(monomio)*size);
    _used = 0;
    _size = size;
}

monomio* polinomio::getElem(int pos){
    monomio* m = NULL;
    if (pos < _size){
        m = &_elem[pos];
    }
    return m;
}

int polinomio::getSize(){ return _size; }


void polinomio::setElem(monomio elem,int pos){
    if (pos < _size){
        _elem[pos] = elem;
    }
    return;
}

void polinomio::addElem(monomio elem){
    while (!(_used < _size)){
        if (_size == 0) _size = 1;
        else _size <<= 1;    //Duplica el tamaño
    }
    _elem = (monomio*)realloc(_elem,sizeof(monomio)*_size);
    _elem[_used++] = elem;
    return;
}


void polinomio::setSize(int size){_size = size;}

double polinomio::operator () (double value){
    double result = 0;
    monomio aux;
    for (int i=0;i<_used;i++){
        aux = _elem[i];
        result += aux.getCoef()*pow(value,aux.getExp());
    }
    return result;
}

ostream& operator << (ostream& os,polinomio& p){
    for (int i=0;i<p._used;i++){
        monomio m = p._elem[i];
        os << m;
    }
    return os;
}
