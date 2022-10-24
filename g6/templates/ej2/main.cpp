#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    vector<int> prueba(5);

    cin >> prueba;
    cout << prueba;
    prueba.swap(2,4);
    cout << "Con swap: " << prueba << endl;
    prueba.addEnd(8);
    cout << "Tamaño actual: " << prueba.getSize() << " de " << prueba.getMax() << endl;

    cout << prueba << endl;
    vector<int> igualado;
    igualado = prueba;
    cout << igualado << endl;


    return 0;
}
