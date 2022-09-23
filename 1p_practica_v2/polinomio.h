#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class monomio {
    protected:
        double _coef;
        int _exp;
    public:

        monomio();
        monomio(double coef,int exp);

        double getCoef() const;
        int getExp() const;

        void setCoef(double coef);
        void setExp(int exp);

        /* Operations */
        monomio operator + (const monomio& b);
        monomio& operator += (const monomio& b);

        /* I/O */
        friend ostream& operator << (ostream& os,const monomio& m);


};

class polinomio : public monomio{

    private:
        int _grado;
        monomio* _elem;
    public:

        polinomio();
        polinomio(int grado);

        int getGrado();
        monomio& getElem(int exp);

        void setGrado(int grado);
        void setElem(monomio& m);

        double operator () (double value);
        polinomio& operator += (monomio m);

        friend ostream& operator << (ostream& os,polinomio& p);

        void file_write_b(const char* fname);
        void file_write_t(const char* fname);
        friend polinomio file_read_t(const char* fname);
        friend polinomio file_read_b(const char* fname);

};
polinomio file_read_t(const char* fname);
polinomio file_read_b(const char* fname);
#endif // POLINOMIO_H_INCLUDED
