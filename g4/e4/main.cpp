#include <iostream>
using namespace std;

class ClaseA {
    public:
        ClaseA() : valorA(10) {}
        int LeerValor() const { return valorA; }
    protected:
        int valorA;
};

class ClaseB {
    public:
        ClaseB() : valorB(20) {}
        int LeerValor() const { return valorB; }
    protected:
        int valorB;
};

class ClaseC : public ClaseA , public ClaseB{};


int main()
{
    ClaseC CC;
    //Esta opci�n es ambigua: no sabe si leer el valor de ClaseA o de ClaseB.
    //cout << CC.LeerValor() << endl;

    //Esta opci�n imprimir� 20
    //cout << CC.ClaseB::LeerValor() << endl;

    //Esta opci�n imprimir� 10
    cout << CC.ClaseA::LeerValor() << endl;
    return 0;
}
