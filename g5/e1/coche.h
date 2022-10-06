#ifndef COCHE_H_INCLUDED
#define COCHE_H_INCLUDED
#include "vehiculo.h"

class coche : public virtual vehiculo{

    private:

    public:
        void acelerar() = 0;
        void frenar() = 0;

};

class sedan : public virtual coche{

    private:

    public:
        void acelerar() override;
        void frenar() override;

};

class furgoneta : public virtual coche{

    private:

    public:
        void acelerar() override;
        void frenar() override;

};



#endif // COCHE_H_INCLUDED
