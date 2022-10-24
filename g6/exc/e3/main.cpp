#include <iostream>
#include "excep.h"

using namespace std;

void leeme_el_num_3(){
    int r;
    cout << "ingrese el numero 3: ";
    try{
        cin >> r;
        if (r!=3) throw mi_excepcion("NO INGRESASTE EL 3, MALA PERSONA");
        cout << "GRACIAS, TE QUIERO" << endl;
    }
    catch(mi_excepcion& e){
        cout << e.getInfo() << endl;
    }
}

int main()
{
    leeme_el_num_3();
    return 0;
}
