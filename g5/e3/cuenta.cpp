#include "cuenta.h"


/* ----- Cuenta ----- */

cuenta::cuenta(string tit){
    titular = tit;
    saldo = 0;
}

bool cuenta::extraer(double valor){
    saldo -= valor;
    return true;
}

double cuenta::balance(){
    return saldo;
}

void cuenta::depositar(double valor){
    saldo += valor;
}




/* ----- Cuenta Corriente ----- */





/* ----- Caja de ahorro ----- */
unsigned int caja_ahorro::max_extr = 2;

caja_ahorro::caja_ahorro(string tit) : cuenta(tit){
    extracciones = 0;
}

bool caja_ahorro::extraer(double valor){
    bool r = false;
    if ((saldo < valor) && (extracciones < max_extr)){
        r = cuenta::extraer(valor);
        extracciones++;
    }
    return r;
}
