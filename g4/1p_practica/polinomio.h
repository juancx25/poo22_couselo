#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include <iostream>
using namespace std;

class monomio {
    protected:
        float _coef;
        int _exp;
    public:

        monomio();
        monomio(float coef,int exp);

        float getCoef();
        int getExp();

        void setCoef(float coef);
        void setExp(int exp);

        friend ostream& operator << (ostream& os,monomio& m);

};

ostream& operator << (ostream& os,monomio& m);

class polinomio : public monomio {

    private:
        monomio* _elem;
        int _size;
    public:

        polinomio();
        polinomio(monomio& m);

        monomio getElem();
        int getSize();

        void setElem(monomio elem);
        void setSize(int size);

        friend ostream& operator << (ostream& os,polinomio& p);

};

#endif // POLINOMIO_H_INCLUDED
