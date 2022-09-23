#include "polinomio.h"

int main()
{
    monomio m1(5,2);
    monomio m2(6,1);
    monomio m3(7,0);
    polinomio p(5);
    p.addElem(m1);p.addElem(m2);p.addElem(m3);
    double pepito = p(2);
    cout << p << "\np(2) = " << pepito;
    return 0;
}
