#include "polinomio.h"

using namespace std;

int main()
{
    monomio m0(3,5);
    monomio m1(5,2);
    monomio m2(6,1);
    monomio m3(-7,0);
    polinomio p(6);
    p += m0;p += m1;p += m2;p += m3;

    double pepito = p(2);
    cout << p << endl << "p(2) = " << pepito << endl;

    p.file_write_t("out.txt");
    polinomio p2 = file_read_t("out.txt");
    cout << p2 << endl;

    p.file_write_b("b_out.txt");
    polinomio p3 = file_read_b("b_out.txt");
    cout << p3;
    return 0;
}
