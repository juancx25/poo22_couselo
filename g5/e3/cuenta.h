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

};

class cuenta_corriente : public cuenta{

    private:
    public:
        bool extraer(double valor) override;

};


class caja_ahorro : public cuenta{
    private:
        static unsigned int max_extr;
        unsigned int extracciones;
    public:
        caja_ahorro(string tit);

        bool extraer(double valor) override;

};


#endif // CUENTA_H_INCLUDED
