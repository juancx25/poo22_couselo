#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include <string>
#include <iostream>

class empleado{

    private:

        std::string nombre;
        std::string apellido;

    public:
        empleado();
        empleado(std::string n,std::string a);

        std::string getNombre()const;
        std::string getApellido()const;

        void setNombre(std::string n);
        void setApellido(std::string a);

        friend std::ostream& operator << (std::ostream& os,const empleado& e);

};

std::ostream& operator << (std::ostream& os,const empleado& e);

#endif // EMPLOYEE_H_INCLUDED
