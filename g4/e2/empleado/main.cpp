#include "empleado.h"

using namespace POO22;
using namespace std;

int main(){
    string fn = "Juan";string ln = "Perez";string ad = "Calle falsa 123";string cat = "Manager";

    empleado e = empleado(fn,ln,31,12,1978,ad,43185723,cat,1,7,1999,120000);
    cout << e;
    return 0;
}
