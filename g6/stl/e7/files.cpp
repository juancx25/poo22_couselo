#include "files.h"

void leer_empleados(const char* fname, std::vector<empleado>& v){
    std::ifstream in;
    in.open(fname);

    std::string line = "";
    while(getline(in,line)){

        std::stringstream str_in(line);
        std::string n;
        std::string a;

        getline(str_in,n,',');
        getline(str_in,a);

        empleado* aux = new empleado(n,a);
        v.push_back(*aux);

    }
    in.close();
    return;
}

void guardar_empleados(const char* fname, const std::vector<empleado>& v){
    std::ofstream out;
    out.open(fname);

    for(std::vector<empleado>::const_iterator it=v.begin() ; it != v.end() ; ++it){
        empleado e = *it;
        out << e.getNombre() << "," << e.getApellido() << std::endl;
    }

    out.close();
}
