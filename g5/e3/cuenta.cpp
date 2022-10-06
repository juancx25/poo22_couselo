#include "cuenta.h"


/* ----- Cuenta ----- */

cuenta::cuenta(string tit){
    titular = tit;
    saldo = 0;
}

void cuenta::setTitular(string tit){ titular = tit; }
string cuenta::getTitular(){ return titular; }

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

void cuenta::imprimir(){
    cout << "Titular: " << getTitular() << " | "
        << "Saldo: " << balance();
}
ostream& operator << (ostream& os,cuenta& c){
    os << "Titular: " << c.getTitular() << " | "
        << "Saldo: " << c.balance();
    return os;
}

/* ----- Cuenta Corriente ----- */

cuenta_corriente::cuenta_corriente(string tit,double min_desc) : cuenta(tit) {
    min_descubierto = min_desc;
}

bool cuenta_corriente::extraer(double valor){
    bool r = false;
    if (saldo-valor >= min_descubierto){
        r = cuenta::extraer(valor);
    }
    return r;
}
void cuenta_corriente::imprimir(){
    cuenta::imprimir();
    cout << " | Cuenta corriente" ;
}
ostream& operator << (ostream& os,cuenta_corriente& cc){
    os << "Titular: " << cc.getTitular()
        << " | Saldo: " << cc.balance() << " | "
        << "Cuenta corriente" ;
    return os;
}

/* ----- Caja de ahorro ----- */
unsigned int caja_ahorro::max_extr = 2;

caja_ahorro::caja_ahorro(string tit) : cuenta(tit){
    extracciones = 0;
}

bool caja_ahorro::extraer(double valor){
    bool r = false;
    if ((saldo >= valor) && (extracciones < max_extr)){
        r = cuenta::extraer(valor);
        extracciones++;
    }
    return r;
}

void caja_ahorro::imprimir(){
    cuenta::imprimir();
    cout << " | Caja de ahorro | Transacciones: " << extracciones << '/' << max_extr;
}


ostream& operator << (ostream& os,caja_ahorro& ca){
    os << "Titular: " << ca.getTitular()
        << " | Saldo: " << ca.balance() << " | "
        << "Caja de ahorro" ;
    return os;
}
