#ifndef CTERMINO_H_INCLUDED
#define CTERMINO_H_INCLUDED
#include <iostream>

using namespace std;

class CTermino{

    protected:
        unsigned int _exp;
        double _coef;

    public:
        /* Constructores */
        CTermino(unsigned int exp=0,double coef=0);

        /* Getters */
        unsigned int getExp();
        double getCoef();

        /* Setters */
        void setExp(unsigned int exp);
        void setCoef(double coef);

        /* Operadores */
        CTermino operator + (const CTermino& b)const;
        CTermino& operator += (const CTermino& b);

        /* I/O */
        friend ostream& operator << (ostream& os,const CTermino& term);
};
ostream& operator << (ostream& os,const CTermino& term);

#endif // CTERMINO_H_INCLUDED
