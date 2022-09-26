#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include <iostream>
#include "CTermino.h"
using namespace std;

class CPolinomio{

    private:
        CTermino* _polinomio;
        unsigned int _grado;

    public:
        CPolinomio(unsigned int grado=0);

        /* Getters */
        CTermino getTerm(unsigned int grado);
        unsigned int getGrado();

        /* Setters */
        void setTerm(CTermino& t);
        bool setGrado(unsigned int grado);

        /* Operadores */
        CPolinomio operator + (const CPolinomio& b) const;

        /* I/O */
        friend ostream& operator << (ostream& os,const CPolinomio& pol);
};
ostream& operator << (ostream& os,const CPolinomio& pol);


#endif // POLINOMIO_H_INCLUDED
