#include <iostream>
#include "mesa_redonda.h"

using namespace std;

int main()
{
    mesaRedonda mr(2,1.5,255);
    cout << "Mesa redonda. Radio: " << mr.getRadio()
    << " | Altura: " << mr.getAltura() << " | Color num.: " << mr.getColor() << endl;
    return 0;
}
