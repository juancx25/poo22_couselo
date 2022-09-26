#include "CPolinomio.h"
/* ------------------------------------- TERMINO ------------------------------------- */

/* Constructores */

CTermino::CTermino(unsigned int exp,double coef){
    _exp = exp;
    _coef = coef;
}

/* Getters */
unsigned int CTermino::getExp(){ return _exp; }
double CTermino::getCoef(){ return _coef; }

/* Setters */
void CTermino::setExp(unsigned int exp){ _exp = exp; }
void CTermino::setCoef(double coef){ _coef = coef; }

/* Operadores */
CTermino CTermino::operator + (const CTermino& b)const{
    CTermino c;
    if (_exp == b._exp){
        c._exp = _exp;
        c._coef = _coef + b._coef;
    }
    return c;                                       // Si son de exponente distinto devuelve 0x^0
}
CTermino& CTermino::operator += (const CTermino& b){
    _coef += b._coef;
    return *this;
}

/* I/O */
ostream& operator << (ostream& os,const CTermino& term){
    os << showpos << term._coef << noshowpos << "x^" << term._exp;
    return os;
}

/* ------------------------------------- POLINOMIO ------------------------------------- */


CPolinomio::CPolinomio(unsigned int grado){
    _grado = grado;
    _polinomio = new CTermino[grado+1];
    /*for (unsigned int i=0;i<grado+1;i++){
        CTermino aux;;
        _polinomio[i].setExp(i);
    }*/
}

/* Getters */
CTermino CPolinomio::getTerm(unsigned int grado){ return _polinomio[grado]; }
unsigned int CPolinomio::getGrado(){ return _grado; }

/* Setters */
void CPolinomio::setTerm(CTermino& t){
    unsigned int gr = t.getExp();
    if(gr > _grado){
        setGrado(gr);
    }
    _polinomio[gr] += t;
}

bool CPolinomio::setGrado(unsigned int grado){
    bool result = false;
    if (grado > _grado){
        CTermino* aux;
        aux = new CTermino[grado+1];
        for (unsigned int i=0;i<grado+1;i++){
            if (i<_grado) aux[i] = _polinomio[i];
            aux[i].setExp(i);
        }
        delete[] _polinomio;
        _polinomio = aux;
        _grado = grado;
        result = true;
    }
    return result;
}

/* Operadores */
CPolinomio CPolinomio::operator + (const CPolinomio& b) const{
    unsigned int grado_max = max(this->_grado,b._grado);
    unsigned int grado_min = min(this->_grado,b._grado);
    CPolinomio c(grado_max);
    for (unsigned int i=0;i<=grado_max;i++){
        if (i<=grado_min){
            c._polinomio[i] = this->_polinomio[i] + b._polinomio[i];
        }
        else{
            if (_grado == grado_max) c._polinomio[i] = this->_polinomio[i];
            else c._polinomio[i] = b._polinomio[i];
        }

    }
    return c;
}

/* I/O */
ostream& operator << (ostream& os,const CPolinomio& pol){
    CTermino aux;
    for (unsigned int i=0;i<pol._grado+1;i++){
        aux = pol._polinomio[i];
        if (aux.getCoef() != 0) os << aux;
    }
    return os;
}

