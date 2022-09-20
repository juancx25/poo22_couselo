#include "mesa_redonda.h"

/* Circulo */
circulo::circulo(){ radio = 0; }
circulo::circulo(double rad){ radio = rad; }

double circulo::getArea(){ return (PI*radio*radio); }

double circulo::getRadio(){ return radio; }
void circulo::setRadio(double rad){ radio = rad; }

/* Mesa */
mesa::mesa(){ altura = 0; }
mesa::mesa(double alt){ altura = alt; }

double mesa::getAltura(){ return altura; }
void mesa::setAltura(double a){ altura = a; }

/* Mesa redonda */
mesaRedonda::mesaRedonda() : mesa() , circulo() {}
mesaRedonda::mesaRedonda(double rad,double alt,int co) : mesa(alt) , circulo(rad) {
    color = co;
}

int mesaRedonda::getColor(){ return color; }
void mesaRedonda::setColor(int c){ color = c; }
