#include <iostream>
#include "CPolinomio.h"


int main()
{
    CTermino t11(3,2);CTermino t12(1,-1);CTermino t13(0,8.25);
    CTermino t21(5,5);CTermino t22(3,-2);CTermino t23(2,7);CTermino t24(0,-3);

    CPolinomio p1;
    p1.setTerm(t11);
    p1.setTerm(t12);
    p1.setTerm(t13);
    CPolinomio p2;
    p2.setTerm(t21);
    p2.setTerm(t22);
    p2.setTerm(t23);
    p2.setTerm(t24);

    CPolinomio p3 = p1 + p2;

    cout << p1 << " mas " << p2 << " es igual a " << p3 << endl;
    return 0;
}
