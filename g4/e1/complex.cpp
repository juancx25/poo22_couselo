#include "complex.h"
#include <math.h>

using namespace std;
using namespace POO22;

/* ----- Constructors ----- */
complex::complex(){
    _real = 0;
    _imag = 0;
}

complex::complex(double real,double imag){
    _real = real;
    _imag = imag;
}

/* ----- Getters ----- */
double complex::getReal() const { return _real; }
double complex::getImag() const { return _imag; }

/* ----- Setters ----- */
void complex::setReal(double real) { _real = real; }
void complex::setImag(double imag) { _imag = imag; }

/* ----- I/O methods ----- */
istream& POO22::operator >> (istream& is,complex& c){
    cout << "Real: ";
    is >> c._real;
    cout << endl << "Imag: ";
    is >> c._imag;
    return is;
}

ostream& POO22::operator << (ostream& os,complex& c){
    os << c._real << showpos << c._imag << "j" << noshowpos;
    return os;
}

/* ----- Polar notations -----
double complex::mod(){
    return sqrt(pow(getReal(),2)+pow(getImag(),2));
}
double complex::angle(){
    return atan2(getImag(),getReal());
}*/

/* ----- Operations ----- */

complex complex::operator + (const complex& b){
    return complex(getReal()+b.getReal(),getImag()+b.getImag());
}
complex complex::operator + (const double& b){
    return complex(getReal()+b,getImag());
}
complex operator + (const double& a,const complex& b){
    return complex(a+b.getReal(),b.getImag());
}


complex complex::operator - (const complex& b){
    return complex(getReal()-b.getReal(),getImag()-b.getImag());
}
complex complex::operator - (const double& b){
    return complex(getReal()-b,getImag());
}
complex operator - (const double& a,const complex& b){
    return complex(a-b.getReal(),b.getImag());
}


complex complex::operator * (const complex& b){
    return complex(getReal()*b.getReal()-getImag()*b.getImag(),
                   getReal()*b.getImag()+getImag()*b.getReal());
}
complex complex::operator * (const double& b){
    return complex(getReal()*b,getImag()*b);
}
complex operator * (const double& a,const POO22::complex& b){
    return complex(a*b.getReal(),a*b.getImag());
}


complex complex::operator / (const complex& cb){
    double a = getReal(); double b = getImag();
    double c = cb.getReal(); double d = cb.getImag();
    return complex((a*c+b*d)/(c*c+d*d),(b*c-a*d)/(c*c+d*d));
}
complex complex::operator / (const double& b){
    return complex(getReal()/b,getImag()/b);
}
complex operator / (const double& a,const POO22::complex& cb){
    double c = cb.getReal(); double d = cb.getImag();
    return complex((a*c)/(c*c+d*d),(-a*d)/(c*c+d*d));
}
