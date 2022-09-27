#include <iostream>
#include "persona.h"
#include "vector.h"
using namespace std;
using namespace POO22;

int main()
{
    string fn1="Juan";string ln1="Perez";string ad1="CalleFalsa123";
    string fn2="Martin";string ln2="Rodriguez";string ad2="CalleVerdadera123";
    string fn3="Jesus";string ln3="Dios";string ad3="Pepito666";
    string fn4="Paloma";string ln4="Koksal";string ad4="Batman Av.1469";
    persona p1(fn1,ln1,1,2,1993,ad1,34042101);
    persona p2(fn2,ln2,9,6,1973,ad2,23142414);
    persona p3(fn3,ln3,7,7,1993,ad3,36116211);
    persona p4(fn4,ln4,24,3,2013,ad4,54042101);

    vector v(4);v.addEnd(p1);v.addEnd(p2);v.addEnd(p3);v.addEnd(p4);

    cout << v << endl << endl << endl;

    v.writeFile_T("coso.csv");

    vector v2(1);
    v2.readFile_T("coso.csv");
    cout << v2 << endl;
    return 0;
}
