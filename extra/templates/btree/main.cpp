#include <iostream>
#include "btree.h"

using namespace std;

int main()
{
    btree<int>* arbolito = new btree<int>(1);
    //arbolito.insert();

    cout << *arbolito << "\nCant. elementos: " << arbolito->getCount();

    return 0;
}
