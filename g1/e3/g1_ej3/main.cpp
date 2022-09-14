#include <iostream>

using namespace std;

int main()
{
    int a,b;
    float r_c,r_cpp;
    a=5;
    b=2;
    //En C haríamos:
    r_c = (float)a/b;
    //Pero en C++ podemos hacer:
    r_cpp = float(a)/float(b);

    cout << "En C: " << r_c << " | En C++: " << r_cpp << endl;
    //Igual es lo mismo en C++, porque incluye a C.
    return 0;
}
