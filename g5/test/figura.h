#ifndef FIGURA_INCLUDED
#define FIGURA_INCLUDED

class figura{
    protected:
        int cant_lados;
    public:
        virtual void dibujar();
};

class circulo : public figura{
    private:
        int a,b,c;
    public:
        void dibujar();
};

class cuadrado : public figura{
    public:
        cuadrado();
        void dibujar();
        double d,e,f;

};

#endif // FIGURA_INCLUDED
