#include <iostream>

using namespace std;
void la_funcion();

int main()
{
    la_funcion();
    la_funcion();
    la_funcion();
    return 0;
}

void la_funcion(){
    static int exec_count = 0;
    //do something
    exec_count++;
}
