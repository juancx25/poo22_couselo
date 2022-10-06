#include "banco.h"


int main()
{
    banco* BBVA = new banco();
    BBVA->addCuenta(new caja_ahorro("Juan Perez"));
    BBVA->addCuenta(new caja_ahorro("Daniel Martinez"));
    BBVA->addCuenta(new cuenta_corriente("Henry Ford",-100000));

    BBVA->imprimirClientes();

    cuenta_corriente* ford = dynamic_cast<cuenta_corriente*>(BBVA->getCuenta(2));

    cout << "Depositando 500k (Ford)" << endl;
    ford->depositar(500000);

    cout << "Extrayendo 1M (Ford)" << endl;
    bool r = ford->extraer(1000000);
    if (!r) cout << "Maximo de giro en descubierto alcanzado" << endl;

    cout << "Extrayendo 100k (Ford)" << endl;
    r = ford->extraer(100000);
    if (!r) cout << "Maximo de giro en descubierto alcanzado" << endl;

    caja_ahorro* perez = dynamic_cast<caja_ahorro*>(BBVA->getCuenta(0));

    cout << "Depositando 10k (Perez)" << endl;
    perez->depositar(10000);

    cout << "Extrayendo 5k (Perez)" << endl;
    perez->extraer(5000);

    cout << "Extrayendo 2k (Perez)" << endl;
    perez->extraer(2000);

    BBVA->imprimirClientes();
    return 0;
}
