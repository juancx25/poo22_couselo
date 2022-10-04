#include <iostream>
#include "figura.h"

using namespace std;

int main()
{
    figura formas[2];
    formas[0] = *(new circulo());
    formas[1] = *(new cuadrado());
    int _size = sizeof(*formas);

    for (int i=0;i<2;i++){
        formas[i].dibujar();
    }
    cout << "Vector size:" << _size << endl;
    cout << "d = " << formas[1].d << "; e = " << formas[1].e << "; f = " << formas[1].f;
    return 0;
}
