#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED
#include <iostream>
using namespace std;

class vehiculo{

    protected:
        string _marca;
        int _puertas;
        int _kilometraje;
        int _cilindrada;

    public:

        virtual void acelerar() = 0;
        virtual void frenar() = 0;

};

class camion : public virtual vehiculo{

    private:

    public:
        void acelerar() override;
        void frenar() override;
};


#endif // VEHICULO_H_INCLUDED
