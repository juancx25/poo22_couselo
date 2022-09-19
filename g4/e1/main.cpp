#include <iostream>
#include "polar.h"

using namespace POO22;
using namespace std;

int main()
{
    complex c1(1,1);
    polar p1(c1);
    polar p2(4,3);
    polar p3 = p1 + p2;
    cout << "Notación Rectangular: " << c1 << endl;
    cout << "Notación Polar: " << p1 << endl;
    return 0;
}
