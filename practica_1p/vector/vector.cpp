#include <iostream>
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
v_elem          vector::getElem(unsigned int pos){ return _elem[pos]; }
unsigned int    vector::getSize(){ return _size; }
unsigned int    vector::getMax(){ return _max; }

/* ----- Setters ----- */
void vector::setElem(v_elem elem,unsigned int pos){}

void vector::addEnd(v_elem elem){
    if (_max == 0) _max = 1;    //REVISAR
    if (_size >= _max){
        _max += (_max/2)+1;
        this->resize(_max);
    }
    _elem[_size++] = elem;
}

bool vector::resize(unsigned int max){
    bool result = false;
    if (max >= _size){
        v_elem* aux = new v_elem[max];
        for (unsigned int i=0;i<_size;i++){ //Esto hace que el orden sea de n, no puedo copiar la memoria directamente?
            aux[i] = _elem[i];
        }
        delete[] _elem;
        _elem = aux;
        _max = max;
        result = true;
    }
    return result;
}

/* ----- Operadores ----- */



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
