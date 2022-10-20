#include <iostream>
#include <cmath>
#include "trapecios.h"

double fx(double x){ return sin(x); }

int main()
{
    double tc = trapecios_compuesto(fx,0,1,10);
    std::cout << tc;
    return 0;
}
