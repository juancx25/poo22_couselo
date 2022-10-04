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
    vector v3 = move(v1);
    cout << v1 << "  ||  " << v3 << endl;
    int test = v2[1];cout << test << endl;
    bool full = v2.isFull();
    bool mt = v2.isEmpty();
    cout << full << ", " << mt << endl;

    v2.eraseEnd(); cout << v2 << endl;
    v2.erase(0); cout << v2 << endl;
    v2.resize(1); cout << v2 << endl;
    v2.resize(2); cout << v2 << endl;
    return 0;
}
