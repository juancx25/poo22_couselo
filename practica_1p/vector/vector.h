#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <iostream>
#define v_elem int

using namespace std;

class vector {

    protected:
        unsigned int _max;  //Cantidad máxima de elementos a almacenar antes de reasignar memoria.
        v_elem* _elem;
        unsigned int _size; //Cantidad de elementos almacenados actualmente.



    public:
        /* ----- Constructores ----- */
        vector(unsigned int max);   //Con tamaño máximo
        vector(const vector& v);    //Copy
        vector(vector&& v);         //Move

        /* ----- Destructores ----- */
        ~vector();                  //Estándar


        /* ----- Getters ----- */
        v_elem getElem(unsigned int pos);
        unsigned int getSize();
        unsigned int getMax();

        /* ----- Setters ----- */
        void setElem(v_elem elem,unsigned int pos);
        void addEnd(v_elem elem);
        bool resize(unsigned int max);

        /* ----- Operadores ----- */

        /* ----- Screen I/O ----- */
        friend ostream& operator << (ostream& os,const vector& v);
        friend istream& operator >> (istream& os,const vector& v);
        /* ----- File I/O ----- */


};
ostream& operator << (ostream& os,const vector& v);
istream& operator >> (istream& is,const vector& v);

#endif // VECTOR_H_INCLUDED
