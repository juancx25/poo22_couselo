#include "polinomio.h"

//monomio

monomio::monomio(){
    _coef = 0;
    _exp = 0;
}

monomio::monomio(float coef,int exp){
    _coef = coef;
    _exp = exp;
}

float monomio::getCoef(){ return _coef; }
int monomio::getExp(){ return _exp; }

void monomio::setCoef(float coef){ _coef = coef; }
void monomio::setExp(int exp){ _exp = exp; }

ostream& operator << (ostream& os,monomio& m){
    os << m._coef << 'x' << '^' << m._exp;
    return os;
}

//polinomio

polinomio::polinomio(){
    _elem = NULL;
    _size = 0;
}
polinomio::polinomio(monomio& m){


}

monomio polinomio::getElem(){}
int polinomio::getSize(){}

void polinomio::setElem(monomio elem){}
void polinomio::setSize(int size){}

ostream& operator << (ostream& os,polinomio& p){

}
