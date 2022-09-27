#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <iostream>
#include "fecha.h"
#define v_elem POO22::fecha

using namespace std;

class vector {


    private:

        unsigned int _max;  //Cantidad m�xima de elementos a almacenar antes de reasignar memoria.
        v_elem* _elem;
        unsigned int _size; //Cantidad de elementos almacenados actualmente.

    public:
        /* ----- Constructores ----- */
        vector(unsigned int max);   //Con tama�o m�ximo
        vector(const vector& v);    //Copy
        vector(vector&& v);         //Move

        /* ----- Destructores ----- */
        ~vector();                  //Est�ndar


        /* ----- Getters ----- */

        /* Devuelve la cantidad de elementos */
        unsigned int getSize();

        /* Devuelve el tama�o m�ximo */
        unsigned int getMax();

        /* ----- Setters ----- */

        /* Agrega un elemento en la posicion pos. Si se va de rango, lo agrega al final. */
        void add(const v_elem& elem,unsigned int pos);

        /* Agrega un elemento al final. Aumenta el tama�o m�ximo si es necesario */
        void addEnd(const v_elem& elem);

        /* Elimina el �ltimo elemento */
        void eraseEnd();

        /* Elimina el elemento de la posici�n especificada */
        void erase(unsigned int pos);

        /* Modifica el tama�o del vector.
        Si es mayor, reasigna memoria.
        Si es menor, "ignora" los elementos fuera de rango (se eliminan al liberar) */
        bool resize(unsigned int max);

        /* ----- Check ----- */
        bool isEmpty();
        bool isFull();

        /* ----- Operadores ----- */

        /* Devuelve una REFERENCIA al objeto ubicado en pos */
        v_elem& operator [] (unsigned int pos);

        /* ----- Screen I/O ----- */
        friend ostream& operator << (ostream& os,const vector& v);
        friend istream& operator >> (istream& os,const vector& v);

        /* File I/O */
        void readFile_B(const char* fname);
        void writeFile_B(const char* fname);

};
ostream& operator << (ostream& os,const vector& v);
istream& operator >> (istream& is,const vector& v);

long long unsigned int fileSize(const char* fname);

#endif // VECTOR_H_INCLUDED
