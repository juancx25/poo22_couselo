#include "polinomio.h"
#include <cmath>

//monomio

monomio::monomio(){
    _coef = 0;
    _exp = -1;
}

monomio::monomio(double coef,int exp){
    _coef = coef;
    _exp = exp;
}

double monomio::getCoef() const { return _coef; }
int monomio::getExp()const { return _exp; }

void monomio::setCoef(double coef){ _coef = coef; }
void monomio::setExp(int exp){ _exp = exp; }



monomio monomio::operator + (const monomio& b){
    monomio c;
    if (_exp == b._exp){
        c._coef = _coef + b._coef;
        c._exp = _exp;
    }
    return c;
}
monomio& monomio::operator += (const monomio& b){
    if (_exp == b._exp){
        _coef += b._coef;
    }
    return *this;
}


ostream& operator << (ostream& os,const monomio& m){
    os << showpos << m._coef << 'x' << '^' << noshowpos << m._exp;
    return os;
}


// POLINOMIO ------------------------------------------------------------

polinomio::polinomio(){
    _grado = 0;
    _elem = NULL;
}
polinomio::polinomio(int grado){
    _grado = grado;
    _elem = (monomio*)malloc(sizeof(monomio)*_grado);
    for (int i=0;i<_grado;i++){
        monomio* m = new monomio(0,i);
        m->setExp(i);
        this->_elem[i] = *m;
        //delete
    }
}

int polinomio::getGrado(){ return _grado; }
monomio& polinomio::getElem(int exp){ return _elem[exp]; }

void polinomio::setGrado(int grado){
    if (grado > _grado){
        _grado = grado;
        if (!_elem){
            _elem = (monomio*)malloc(sizeof(monomio)*_grado);
        }
        else{
            _elem = (monomio*)realloc(_elem,sizeof(monomio)*_grado);
        }
    }
}

void polinomio::setElem(monomio& m){
    if (m.getExp() < _grado) _elem[m.getExp()] += m;
}

/* Operations */
polinomio& polinomio::operator += (monomio m){
    if (m.getExp() < _grado){
        monomio& aux = getElem(m.getExp());
        aux += m;
    }
    return *this;
}
double polinomio::operator () (double value){
    double result = 0;
    for (int i=0;i<_grado;i++){
        const monomio& aux = _elem[i];
        result += aux.getCoef()*pow(value,i);
    }
    return result;
}

/*  I/O */
ostream& operator << (ostream& os,polinomio& p){
    for (int i=0;i<p._grado;i++){
        const monomio& aux = p._elem[i];
        if (aux.getCoef() != 0) os << aux;
    }
    return os;
}

void polinomio::file_write_b(const char* fname){
    ofstream output;
    output.open(fname,ios::binary);
    output.write(reinterpret_cast<char*>(&_grado),sizeof(int));
    for (int i=0;i<_grado;i++){
        monomio aux = getElem(i);
        output.write(reinterpret_cast<char*>(&aux),sizeof(double)+sizeof(int));
    }
    output.close();
}

polinomio file_read_b(const char* fname){
    ifstream input;
    int grado;
    input.open(fname);
    input.read(reinterpret_cast<char*>(&grado),sizeof(int));
    polinomio* result = new polinomio(grado);
    for (int i=0;i<grado;i++){
        monomio* aux = new monomio();
        input.read(reinterpret_cast<char*>(aux),sizeof(double)+sizeof(int));
        result->_elem[aux->getExp()] += *aux;

    }

    return *result;
}

void polinomio::file_write_t(const char* fname){
    ofstream output;
    output.open(fname);
    output << getGrado() << *this << 'a';
    output.close();
}

polinomio file_read_t(const char* fname){

    ifstream input;
    input.open(fname);
    char dummy;
    int grado;
    input >> grado;
    polinomio* result = new polinomio(grado);
    while (dummy != 'a') {
        double coef=0;int exp=0;
        monomio* aux = new monomio(0,5);
        input >> coef >> dummy >> dummy >> exp;
        aux->setCoef(coef);
        aux->setExp(exp);
        result->_elem[exp] += *aux;
        delete aux;
        input >> dummy;
        input.seekg(-1,ios::cur);
    }
    return *result;
}
