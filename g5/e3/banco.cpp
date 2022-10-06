#include "banco.h"

int banco::getCantCuentas(){
    return cuentas.size();
}

cuenta* banco::getCuenta(int pos){
    return cuentas[pos];
}
void banco::addCuenta(cuenta* c){
    cuentas.push_back(c);
}
void banco::setCuenta(cuenta* c,int pos){
    cuentas[pos] = c;
}

void banco::imprimirClientes(){
    for (int i=0;i < getCantCuentas();i++){
        getCuenta(i)->imprimir(); cout << endl;
        //cout << *BBVA->getCuenta(i) << endl;
    }
}
