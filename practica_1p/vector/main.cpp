#include "vector.h"



int main()
{
    vector v1(2);
    cout << v1.getSize() << " de " << v1.getMax() << endl;
    v1.addEnd(1);v1.addEnd(2);v1.addEnd(3);
    cout << v1.getSize() << " de " << v1.getMax() << endl;
    v1.resize(5);
    v1.addEnd(4);v1.addEnd(5);
    cout << v1.getSize() << " de " << v1.getMax() << endl;
    vector v2 = v1;
    cout << v1 << "  ||  " << v2 << endl;
    vector v3 = v1;
    cout << v1 << "  ||  " << v3 << endl;
    return 0;
}
