#include <iostream>
#include <cstring>
#include "vector.h"
#include <fstream>

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
    vector pepe = *this;
    if (_max == 0) _max = 1;
    if (isFull()){

        this->resize((_max/2)+1);   // Aumenta así pero podría ser de cualquier forma
    }
    _elem[_size++] = elem;
}

void vector::add(const v_elem& elem,unsigned int pos){
    vector pepe = *this;
    if (isFull()){
        resize(_max/2+1);
    }
    if (pos < _size){
        for (unsigned int i=_size;i>pos;i--){
            _elem[i] = _elem[i-1];
        }
        _elem[pos] = elem;
        _size++;
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
        os << v._elem[i] << ' ';
    }
    return os;
}

/*istream& operator >> (istream& is,const vector& v){
    for (unsigned int i=0;i<v._size;i++){
        is >> v._elem[i];
    }
    return is;
}*/

/* File I/O */

void vector::writeFile_T(const char* fname){
    ofstream out;
    out.open(fname);
    for (unsigned int i=0;i<_size;i++){
        v_elem aux = _elem[i];
        out << aux << endl;
    }
    out.close();
}

void vector::readFile_T(const char* fname){
    ifstream in;
    in.open(fname);
    string fn,ln,ad; unsigned int dni; int d,m,y;char NaN;
    while(!in.eof()){
        in >> fn >> NaN >> ln >> NaN >> d >> NaN >> m >> NaN >> y >> NaN >> ad >> NaN >> dni;
        v_elem* aux = new v_elem(fn,ln,d,m,y,ad,dni);
        addEnd(*aux);
        cout << *aux;
    }
    in.close();
}

void vector::readFile_B(const char* fname){
    ifstream in;
    int size = fileSize(fname);
    in.open(fname);
    while(in.tellg()<size)
    //while(!in.eof())
    {
        v_elem* aux = new v_elem();
        in.read(reinterpret_cast<char*>(aux),sizeof(v_elem));
        addEnd(*aux);
    }
    in.close();
}

void vector::writeFile_B(const char* fname){
    ofstream out;
    out.open(fname,ios::binary);
    for (unsigned int i=0;i<_size;i++){
        v_elem aux = _elem[i];
        out.write(reinterpret_cast<char*>(&aux),sizeof(v_elem));
    }
    out.close();
    return;
}




long long unsigned int fileSize(const char* fname){
   ifstream file(fname,ios::binary);
   file.seekg(0, ios::end);
   long long unsigned int size = file.tellg();
   file.close();
   return size;
}
