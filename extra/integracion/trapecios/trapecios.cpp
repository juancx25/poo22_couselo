#include "trapecios.h"

double trapecios_simple(double f(double),double a,double b){
    double h = b-a;
    return h*(f(a)+f(b))/2;
}

double trapecios_compuesto(double f(double),double a,double b, double n){
    double h = (b-a)/n;
    double r = 0;
    for (int i=1;i<n;i++){
        r += f(double(a+i*h));
    }
    return h*(f(a)+f(b)+2*r)/2;
}
