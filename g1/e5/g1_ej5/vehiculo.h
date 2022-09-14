#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED
#include <stdlib.h>

typedef struct _vehiculo{

    char* marca;
    int puertas;
    int kilometraje;
    int cilindrada;
    (*crearVehiculo)(char* marca,int puertas, int kilometraje, int cilindrada);



}vehiculo;


vehiculo* crearVehiculo(char* marca,int puertas, int kilometraje, int cilindrada);
void destruirVehiculo(vehiculo* veh);

#endif // VEHICULO_H_INCLUDED
