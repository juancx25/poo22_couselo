#include "figura.h"
#include <iostream>
using namespace std;

void figura::dibujar(){
    cout << "Soy una figura" << endl;
}

void circulo::dibujar(){
    cout << "Soy circulo" << endl;
}

cuadrado::cuadrado(){
    d=8;e=666;f=33.9;
}

void cuadrado::dibujar(){
    cout << "Soy cuadrado" << endl;
}
