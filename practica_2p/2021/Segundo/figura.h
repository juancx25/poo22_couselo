#ifndef FIGURA_H_INCLUDED
#define FIGURA_H_INCLUDED
#include "CColor.h"
#include <iomanip>
#include <cmath>

class figura{
    protected:
        string tipo_figura;
        CColor fore_color;
        CColor back_color;
        double base;
        double altura;
    public:
        figura(string tipo_figura,uint32_t fore_color,uint32_t back_color,double base,double altura);

        string getTipo();
        double getBase();
        double getAltura();
        CColor& getForeColor();
        CColor& getBackColor();
        void setBase();
        void setAltura();

        virtual double getArea() = 0;
        virtual double getPerimetro() = 0;

        virtual void print(std::ostream& os) = 0;
        friend std::ostream& operator << (std::ostream& os,figura& f);

        void filewrite_txt(std::ostream& os);
};
std::ostream& operator << (std::ostream& os,figura& f);

class rectangulo: public figura{
        public:
        rectangulo(string tipo_figura,uint32_t fore_color,uint32_t back_color,double base,double altura)
        : figura{tipo_figura,fore_color,back_color,base,altura}{}
        double getArea(){ return getBase()*getAltura(); }
        double getPerimetro(){ return (getBase()+getAltura())*2; }

        void print(std::ostream& os);
};

class circulo: public figura{
    public:
        circulo(string tipo_figura,uint32_t fore_color,uint32_t back_color,double base,double altura)
        : figura{tipo_figura,fore_color,back_color,base,altura}{}
        double getArea(){ return M_PI*getBase()*getBase(); }
        double getPerimetro(){ return M_PI*getBase()*2; }

        void print(std::ostream& os);
};

class triangulo: public figura{
    public:
        triangulo(string tipo_figura,uint32_t fore_color,uint32_t back_color,double base,double altura)
        : figura{tipo_figura,fore_color,back_color,base,altura}{}
        double getArea(){ return (getBase()*getAltura())/2; }
        double getPerimetro(){ return 3*getBase(); }

        void print(std::ostream& os);
};

figura::figura(string tipo_figura,uint32_t fore_color,uint32_t back_color,double base,double altura){
    this->tipo_figura = tipo_figura;
    this->fore_color = fore_color;
    this->back_color = back_color;
    this->base = base;
    this->altura = altura;

}

string figura::getTipo(){ return tipo_figura; }
double figura::getBase(){ return base; }
double figura::getAltura(){ return altura; }
CColor& figura::getForeColor(){ return fore_color; }
CColor& figura::getBackColor(){ return back_color; }



void figura::filewrite_txt(std::ostream& os){
    os << tipo_figura << ';' << getForeColor() << ';' << getBackColor() << ';' << getBase();
    if (tipo_figura != "Circulo") os << ';' << getAltura();
    os << std::endl;
}

std::ostream& operator << (std::ostream& os,figura& f){
    os << std::fixed;
    os << std::setprecision(2);
    os << "Soy un " << f.tipo_figura << " con color " << f.fore_color << " sobre " << f.back_color << endl;
    f.print(os);
    return os;
}

void rectangulo::print(std::ostream& os){
    os << "\tBase = " << base << ", altura = " << altura << ", area = " << getArea() << " y perimetro = " << getPerimetro() << endl;
}

void circulo::print(std::ostream& os){
    os << "\tRadio = " << base << ", area = " << getArea() << " y perimetro = " << getPerimetro() << endl;
}

void triangulo::print(std::ostream& os){
    os << "\tBase = " << base << ", altura = " << altura << ", area = " << getArea() << " y perimetro = " << getPerimetro() << endl;
}

#endif // FIGURA_H_INCLUDED
