#include "racional.h"
using namespace std;
using namespace POO22;


racional::racional(){
    _num = 0;
    _den = 1;
}
racional::racional(const int& num,const int& den){
    _num = num;
    if (den!=0) _den = den;
    else _den = 1;
}

racional::racional(const int& num){
    _num = num;
    _den = 1;
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
    is >> r._num;
    int aux = 0;
    while (aux == 0){
        is >> aux;
    }
    r._den = aux;
    return is;
}

/* ----- Arithmetic ----- */

int POO22::mcd(int a,int b){
    int aux;
    while (b != 0) {
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

racional::operator double() const{
    return (double(_num)/double(_den));
}

void racional::simplify(){
    int a = mcd(_num,_den);
    _num /= a;
    _den /= a;
    return;
}

racional racional::operator + (racional b){
    racional r( _num*b._den + _den*b._num , _den*b._den );
    r.simplify();
    return r;
}

racional POO22::operator + (double& d,racional& b){
    return racional(d+b._num,b._den);
}

racional& racional::operator += (racional& b){
    _num = _num*b._den + _den*b._num;
    _den = _den*b._den;
    simplify();
    return *this;
}

racional& racional::operator ++ (){
    _num += _den;
    return *this;
}
racional racional::operator ++ (int dummy){
    racional copy(*this);
    _num += _den;
    return copy;
}

racional POO22::operator - (racional& r){
    racional result(r._num*-1 , r._den);
    result.simplify();
    return result;
}
racional racional::operator - (racional& b){
    racional result( _num*b._den - _den*b._num , _den*b._den );
    result.simplify();
    return result;
}
racional& racional::operator -- (){
    _num -= _den;
    return *this;
}
racional racional::operator -- (int dummy){
    racional copy(*this);
    _num -= _den;
    return copy;
}

racional racional::operator * (racional& b){
    racional result(_num * b._num , _den * b._den);
    result.simplify();
    return result;
}

racional racional::operator / (racional& b){
    racional result(_num * b._den , _den * b._num);
    result.simplify();
    return result;
}

/* ----- Comparison ----- */

bool POO22::operator == (const racional& r1, const racional& r2){
    return ((r1._num == r2._num) && (r1._den == r2._den));
}

bool POO22::operator > (const racional& r1, const racional& r2){
    return ( (double(r1) - double(r2)) > 0);
}

bool POO22::operator < (const racional& r1, const racional& r2){
    return ( (double(r2) - double(r1)) > 0);
}

bool POO22::operator ! (const racional& r){
    return (r._num == 0);
}
