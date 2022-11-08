#include "empleado.h"

empleado::empleado(){
    std::cout << "Nombre: "; std::cin >> nombre;
    std::cout << "Apellido: "; std::cin >> apellido;
}

empleado::empleado(std::string n,std::string a){
    nombre = n;
    apellido = a;
}

std::string empleado::getNombre()const{ return nombre; }
std::string empleado::getApellido()const{ return apellido; }

void empleado::setNombre(std::string n){ nombre = n; }
void empleado::setApellido(std::string a){ apellido = a; }

std::ostream& operator << (std::ostream& os,const empleado& e){
    os << e.apellido << ", " << e.nombre;
    return os;
}
