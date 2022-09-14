/**
 * @file main.cpp
 * @author Juan Couselo
 * @brief Test file for Persona class and its methods.
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022, UNMdP
 *
 */

#include "persona.h"
using namespace POO22;


int main(){
    string fn = "Juan";
    string ln = "Perez";
    string ad = "Calle falsa 123";
    string dni = "43185723";
    persona p1 = persona(fn,ln,3,3,2001,ad,dni);
    cout << p1;
    return 0;
}

