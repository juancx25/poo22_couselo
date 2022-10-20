#include <iostream>
#include "btree.h"

using namespace std;

int main()
{
    btree<int>* arbolito = new btree<int>(1);
    cout << *arbolito;

    return 0;
}
