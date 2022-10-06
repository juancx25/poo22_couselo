#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED
#include <vector>
#include "cuenta.h"

class banco {

    private:
        vector<cuenta*> cuentas;

    public:
        //banco();

        int getCantCuentas();
        cuenta* getCuenta(int pos);
        void addCuenta(cuenta* c);   //Agrega al final
        void setCuenta(cuenta* c,int pos);

        void imprimirClientes();

};

#endif // BANCO_H_INCLUDED
