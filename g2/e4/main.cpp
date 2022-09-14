#include "tiempo.cpp"
using namespace POO22;

int main(){
    tiempo t(1,2,3);
    cout << "Ingrese un tiempo:" << endl;
    t.ingresarDatos();

    cout << t << endl;
    return 0;
}