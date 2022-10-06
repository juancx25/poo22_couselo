#include <iostream>
#include "coche.h"
using namespace std;

int main()
{
    vehiculo* veh[3];

    veh[0] = new sedan();
    veh[1] = new furgoneta();
    veh[2] = new camion();

    for (int i=0;i<3;i++){
        veh[i]->acelerar();
        veh[i]->frenar();
    }

    return 0;
}
