#include <iostream>
#include <cstring>
#include "vector.h"

using namespace std;

/* ----- Constructores ----- */

vector::vector(unsigned int max){
    _elem = new v_elem[max];
    _size = 0;
    _max = max;
}

vector::vector(const vector& v) :   _max{v._max},
                                    _elem{new v_elem[v._max]},
                                    _size{v._size}
{
    for (unsigned int i = 0;i<_size;i++){
        _elem[i] = v._elem[i];
    }
}

vector::vector(vector&& v) :    _max{v._max},
                                _elem{new v_elem[v._max]},
                                _size{v._size}
{
    for (unsigned int i = 0;i<_size;i++){
        _elem[i] = v._elem[i];
    }
    v._elem = NULL;
    v._size = 0;
    v._max = 0;
}

/* ----- Destructores ----- */
vector::~vector(){
    delete[] _elem;
}

/* ----- Getters ----- */

unsigned int vector::getSize(){ return _size; }
unsigned int vector::getMax(){ return _max; }

/* ----- Setters ----- */

void vector::addEnd(const v_elem& elem){
    if (_max == 0) _max = 1;
    if (isFull()){

        this->resize(_max+(_max/2)+1);   // Aumenta así pero podría ser de cualquier forma
    }
    _elem[_size++] = elem;
}

void vector::add(const v_elem& elem,unsigned int pos){
    if (isFull()){
        resize(_max+(_max/2)+1);
    }
    if (pos < _size){
        for (unsigned int i=_size;i>pos;i++){
            _elem[i] = _elem[i-1];
        }
        _elem[pos] = elem;
    }
    else{
        addEnd(elem);
    }
}

void vector::eraseEnd(){
    if (_size>0) _size--;   //Sólo lo ignora
}

void vector::erase(unsigned int pos){
    if (pos<_size){
        for (unsigned int i=pos;i<_size-1;i++){
            _elem[i] = _elem[i+1];
        }
    }
    eraseEnd();
}

bool vector::resize(unsigned int max){
    bool result = false;
    if (max >= _size){
        v_elem* aux = new v_elem[max];
        //for (unsigned int i=0;i<_size;i++) aux[i] = _elem[i];
        aux = (v_elem*)memcpy((void*)aux,(void*)_elem,sizeof(v_elem)*_size);
        delete[] _elem;
        _elem = aux;
        result = true;
    }
    else {
        _size = max;
        result = true;
    }
    _max = max;
    return result;
}

/* ----- Check ----- */
bool vector::isEmpty(){ return (_size == 0); }
bool vector::isFull(){ return (_size == _max); }

/* ----- Operadores ----- */
v_elem& vector::operator [] (unsigned int pos){
    return _elem[pos];
}


/* ----- I/O ----- */
ostream& operator << (ostream& os,const vector& v){
    for (unsigned int i=0;i<v._size;i++){
        os << v._elem[i] << "  ";
    }
    return os;
}

istream& operator >> (istream& is,const vector& v){
    for (unsigned int i=0;i<v._size;i++){
        is >> v._elem[i];
    }
    return is;
}
