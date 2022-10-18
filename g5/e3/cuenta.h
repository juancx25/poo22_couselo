#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED
#include "cuenta.h"
#include <iostream>

using namespace std;

class cuenta {

    protected:
        double saldo;
        string titular;
    public:
        cuenta(string tit);

        virtual bool extraer(double valor);
        double balance();
        void depositar(double valor);

        void setTitular(string tit);
        string getTitular();

        virtual void imprimir();
        friend ostream& operator << (ostream& os,cuenta& c);

};
ostream& operator << (ostream& os,cuenta& c);

class cuenta_corriente : public cuenta{

    private:
        double min_descubierto;
    public:
        cuenta_corriente(string tit,double min_desc);

        virtual bool extraer(double valor);

        virtual void imprimir();
        friend ostream& operator << (ostream& os,cuenta_corriente& cc);
};
ostream& operator << (ostream& os,cuenta_corriente& cc);

class caja_ahorro : public cuenta{
    private:
        static unsigned int max_extr;
        unsigned int extracciones;
    public:
        caja_ahorro(string tit);

        virtual bool extraer(double valor);

        virtual void imprimir();
        friend ostream& operator << (ostream& os,caja_ahorro& ca);
};
ostream& operator << (ostream& os,caja_ahorro& ca);

#endif // CUENTA_H_INCLUDED
