#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <iostream>
//#define v_elem int

using namespace std;

template <class T> class vector;
template <class T> ostream& operator << (ostream& os,vector<T>& v);
template <class T> istream& operator >> (istream& is,vector<T>& v);

template <class T> class vector {


    private:

        unsigned int _stored;  //Cantidad máxima de elementos a almacenar antes de reasignar memoria.
        T* _elem;
        unsigned int _size; //Cantidad de elementos almacenados actualmente.

        /* Modifica el tamaño del vector.
        Si es mayor, reasigna memoria.
        Si es menor, "ignora" los elementos fuera de rango (se eliminan al liberar) */
        bool resize();
        bool _resize(unsigned int new_size);

    public:
        /* ----- Constructores ----- */
        vector(unsigned int stored=2);   //Con tamaño máximo
        vector(const vector& v);    //Copy
        //vector(vector&& v);         //Move

        /* ----- Destructores ----- */
        ~vector();                  //Estándar


        /* ----- Getters ----- */

        /* Devuelve la cantidad de elementos */
        unsigned int getSize();

        /* Devuelve el tamaño máximo */
        unsigned int getMax();

        /* ----- Setters ----- */

        /* Agrega un elemento en la posicion pos */
        void add(const T& elem,unsigned int pos);

        /* Agrega un elemento al final. Aumenta el tamaño máximo si es necesario */
        void addEnd(const T& elem);

        /* Elimina el último elemento */
        void erase_last();

        /* Elimina el elemento de la posición especificada */
        void erase(unsigned int pos);

        void swap(unsigned int pos1,unsigned int pos2);


        /* ----- Check ----- */
        bool is_empty();
        bool is_full();

        /* ----- Operadores ----- */

        /* Devuelve una REFERENCIA al objeto ubicado en pos */
        T& operator [] (unsigned int pos);

        T& operator = (vector<T>& origen);

        /* ----- Screen I/O ----- */
        friend ostream& operator << <>(ostream& os,vector<T>& v);
        friend istream& operator >> <>(istream& is,vector<T>& v);


};




#include <iostream>
#include <cstring>
#include "vector.h"

using namespace std;

/* ----- Constructores ----- */

template <class T> vector<T>::vector(unsigned int stored){
    _elem = new T[stored];
    _size = 0;
    _stored = stored;
}

template <class T> vector<T>::vector(const vector<T>& v){
    _stored = v._stored;
    _elem = new T[v._stored];
    _size = v._size;
    for (unsigned int i = 0;i<_size;i++){
        _elem[i] = v._elem[i];
    }
}

/*vector::vector(vector&& v) :    _stored{v._stored},
                                _elem{new v_elem[v._stored]},
                                _size{v._size}
{
    for (unsigned int i = 0;i<_size;i++){
        _elem[i] = v._elem[i];
    }
    v._elem = NULL;
    v._size = 0;
    v._stored = 0;
}*/

/* ----- Destructores ----- */
template <class T> vector<T>::~vector(){
    delete[] _elem;
}

/* ----- Getters ----- */

template <class T> unsigned int vector<T>::getSize(){ return _size; }
template <class T> unsigned int vector<T>::getMax(){ return _stored; }

/* ----- Setters ----- */

template <class T> void vector<T>::addEnd(const T& elem){
    if (_stored == 0) _stored = 1;
    if (is_full()){

        this->resize();
    }
    _elem[_size++] = elem;
}

template <class T> void vector<T>::add(const T& elem,unsigned int pos){
    if (is_full()){
        resize();
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

template <class T> void vector<T>::erase_last(){
    if (_size>0) _size--;   //Sólo lo ignora
}

template <class T> void vector<T>::erase(unsigned int pos){
    if (pos<_size){
        for (unsigned int i=pos;i<_size-1;i++){
            _elem[i] = _elem[i+1];
        }
    }
    erase_last();
}

template <class T> void vector<T>::swap(unsigned int pos1,unsigned int pos2){
    if ((pos1 < _size) && (pos2 < _size)){
        T aux = _elem[pos1];
        _elem[pos1] = _elem[pos2];
        _elem[pos2] = aux;
    }
}

template <class T> bool vector<T>::resize(){ return _resize(_stored+(_stored/2)+1); }   // Aumenta en ese factor pero podría ser de cualquier forma

template <class T> bool vector<T>::_resize(unsigned int stored){
    bool result = false;
    if (stored >= _size){
        T* aux = new T[stored];
        //for (unsigned int i=0;i<_size;i++) aux[i] = _elem[i];
        aux = (T*)memcpy((void*)aux,(void*)_elem,sizeof(T)*_size);
        delete[] _elem;
        _elem = aux;
        result = true;
    }
    else {
        _size = stored;
        result = true;
    }
    _stored = stored;
    return result;
}

/* ----- Check ----- */
template <class T> bool vector<T>::is_empty(){ return (_size == 0); }
template <class T> bool vector<T>::is_full(){ return (_size == _stored); }

/* ----- Operadores ----- */
template <class T> T& vector<T>::operator [] (unsigned int pos){
    return _elem[pos];
}

template <class T> T& vector<T>::operator = (vector<T>& origen){

}


/* ----- I/O ----- */
template <class T> ostream& operator << (ostream& os,vector<T>& v){
    for (unsigned int i=0;i<v._size;i++){
        os << v._elem[i] << "  ";
    }
    return os;
}

template <class T> istream& operator >> (istream& is,vector<T>& v){
    for (unsigned int i=0;i<v._stored;i++){
        is >> v._elem[i];
        v._size++;
    }
    return is;
}



#endif // VECTOR_H_INCLUDED
