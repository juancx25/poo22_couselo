#include "becario.h"

using namespace std;
using namespace POO22;

int main()
{
    string fn = "Juan";string ln = "Couselo"; string ad = "Calle Falsa 123";
    string car = "Ing. Computacion";string cat = "Vasallo";string ty = "No remunerado";
    string lab = "Lab. de boludeces";string dir = "Cristo Dios";
    fecha bd(3,3,2001);fecha ed(1,3,2020);fecha sd(14,7,2022);

    becario juancito(fn,ln,bd,ad,43185723,car,15,ed,6.82,cat,sd,0,ty,12,lab,dir);
    cout << juancito;

    return 0;
}
