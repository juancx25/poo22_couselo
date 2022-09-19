#include "polar.h"
#include "math.h"

using namespace std;
using namespace POO22;

polar::polar(){
    _mod = 0;
    _phase = 0;
}
polar::polar(const complex& c){
    _mod = sqrt(pow(c.getReal(),2)+pow(c.getImag(),2));
    _phase = atan2(c.getImag(),c.getReal());
}
polar::polar(double a,double b,bool is_polar){
    if (is_polar){
        _mod = a;
        _phase = b;
    } else{
        _mod = sqrt(pow(a,2)+pow(b,2));
        _phase = atan2(b,a);
    }
}

/* ----- Getters ----- */
double polar::getMod(){ return _mod; }
double polar::getPhase(){ return _phase; }

/* ----- Setters ----- */
void polar::setMod(double mod){ _mod = mod; }
void polar::setPhase(double phase){ _phase = phase; }

/* ----- I/O methods ----- */
ostream& POO22::operator << (ostream& os,const polar& p){
    os << p._mod << " | " << p._phase;
    return os;
}
