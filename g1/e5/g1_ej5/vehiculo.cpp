#include "vehiculo.h"

vehiculo* crearVehiculo(char* marca,int puertas,int kilometraje,int cilindrada){
    vehiculo* new_veh = (vehiculo*)malloc(sizeof(vehiculo));
    new_veh->marca = marca;
    new_veh->puertas = puertas;
    new_veh->kilometraje = kilometraje;
    new_veh->cilindrada = cilindrada;
    return new_veh;
}


void destruirVehiculo(vehiculo* veh){
    free(veh->marca);
    free(veh);
    return;
}

