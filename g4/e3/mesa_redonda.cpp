#include "mesa_redonda.h"

/* Circulo */
circulo(){ radio = 0; }
circulo(double rad){ radio = rad; }

double circulo::getArea(){ return (PI*radio*radio); }

double circulo::getRadio(){ return radio; }
void circulo::setRadio(double rad){ radio = rad; }

/* Mesa */
mesa(){ altura = 0; }
mesa(double alt){ altura = alt; }

double mesa::getAltura(){ return altura; }
void mesa::setAltura(double a){ altura = a; }

/* Mesa redonda */
mesaRedonda() : mesa() , circulo() {}
mesaRedonda(double rad,double alt,int co) : circulo(rad) , mesa(alt){
    color = co;
}

int mesaRedonda::getColor(){ return color; }
void mesaRedonda::setColor(int c){ color = c; }
