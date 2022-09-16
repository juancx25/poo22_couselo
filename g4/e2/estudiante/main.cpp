#include <iostream>
#include "estudiante.h"

using namespace std;
using namespace POO22;

int main()
{
    string fn = "Alfredo";string ln = "Montes de Oca";string ad = "1 y 57";string ca = "Periodismo deportivo";
    estudiante alfred(fn,ln,1,4,1980,ad,30221433,ca,20,4,3,1998,6.78);
    cout << alfred << endl;
    return 0;
}
