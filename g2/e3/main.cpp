#include "fecha.h"

using namespace std;
using namespace POO22;
int main()
{
    fecha test;
    test.ingresarFecha();
    test.imprimir();
    cout << test << endl;

    fecha *f2 = new fecha(1,3,2005);
    cout << *f2 << " es una fecha ";
    if (f2->validarFecha()) cout << "valida" << endl;
    else cout << "invalida" << endl;
    f2->setFormat(1);
    cout << "Formato YYYY/MM/DD: ";
    f2->imprimir();
    return 0;
}
