#ifndef EXCEP_H_INCLUDED
#define EXCEP_H_INCLUDED
#include <string>

class mi_excepcion{

    protected:
        std::string info;
    public:
        mi_excepcion(std::string i){ info = i; }
        std::string getInfo(){ return info; }

};

#endif // EXCEP_H_INCLUDED
