#include "complex.h"

using namespace std;
using namespace POO22;

int main(){

    complex c1 = complex(-2,-3);
    complex c2 = complex(1,-3);

    complex c3 = c1 / c2 / 0.1;
    cout << c3 << endl;

    complex c4 = 10 / c3;
    cout << c4 << endl;

    double pepe = c1.angle();
    cout << pepe;

    return 0;
}
