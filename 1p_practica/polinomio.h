#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include <iostream>
#include <cstdlib>

using namespace std;

class monomio {
    protected:
        double _coef;
        int _exp;
    public:

        monomio();
        monomio(double coef,int exp);

        double getCoef();
        int getExp();

        void setCoef(double coef);
        void setExp(int exp);

        friend ostream& operator << (ostream& os,monomio& m);

};

ostream& operator << (ostream& os,monomio& m);

class polinomio : public monomio {

    private:
        monomio* _elem;
        int _used;
        int _size;
    public:

        polinomio();
        polinomio(int size);

        monomio* getElem(int pos);
        int getSize();

        void setElem(monomio elem,int pos);
        void setSize(int size);
        void addElem(monomio elem) const;

        friend ostream& operator << (ostream& os,polinomio& p);
        double operator () (double value);

};

#endif // POLINOMIO_H_INCLUDED
