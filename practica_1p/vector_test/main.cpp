#include <iostream>
#include "fecha.h"
#include "vector.h"

using namespace POO22;
using namespace std;

int main()
{
    fecha f1;fecha f2(6,12,2003);fecha f3(27,1,2015);

    vector v(5);
    v.addEnd(f1);
    v.addEnd(f3);
    v.add(f2,1);
    cout << v << endl;

    v.erase(0);
    cout << v << endl;

    v.eraseEnd();
    cout << v << endl;

    v.add(f2,5);
    cout << v << endl;

    v[1] = f1;
    cout << v << endl;

    fecha ptest = v[0];
    cout << ptest << endl;

    v.addEnd(f3);
    cout << v << endl;

    v.writeFile_B("binario.bin");
    vector v2(1);
    v2.readFile_B("binario.bin");
    cout << endl << v2 << endl;

    return 0;
}
