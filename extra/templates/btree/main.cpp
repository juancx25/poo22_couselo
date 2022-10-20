#include <iostream>
#include "btree.h"

using namespace std;

int main()
{
    bt_node<> marisa;
    marisa.setValue(6);
    bt_node<> marisa_left;
    marisa_left.setValue(5);
    marisa.setLeft(&marisa_left);
    cout << marisa.getLeft()->getValue();
    return 0;
}
