#ifndef MESA_REDONDA_INCLUDED
#define MESA_REDONDA_INCLUDED
#define PI 3.14159

class circulo {

    private:
        double radio;
    public:
        circulo();
        circulo(double rad);

        double getArea();

        double getRadio();
        void setRadio(double rad);

};

class mesa {

    private:
        double altura;
    public:
        mesa();
        mesa(double alt);

        double getAltura();
        void setAltura(double a);

};

class mesaRedonda : public mesa , public circulo{

    private:
        int color;
    public:
        mesaRedonda();
        mesaRedonda(double rad,double alt,int co);

        int getColor();
        void setColor(int c);

};

#endif // MESA_REDONDA_INCLUDED
