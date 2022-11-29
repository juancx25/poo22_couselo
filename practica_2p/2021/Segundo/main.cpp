#include "ManejadorFiguras.h"

using namespace std;

int main()
{
    ManejadorFiguras mf;

    mf.recuperarFiguras("figuras_entrada.txt");
    //mf.recuperarFiguras_bin("figuras_salida.bin");

    cout << mf << endl << endl;

    mf.guardarFiguras("figuras_salida.txt");
    mf.guardarFiguras_bin("figuras_salida.bin");
    //mf.agregarFigura("Circulo", 0xFF0000, 0xFF00, 3.1);
    //mf.agregarFigura("Rectangulo", 0xFF, 0xFFFF00, 4.5, 6.7);
   // mf.agregarFigura("Triangulo", 0xFF000, 0xF0F00, 7.5, 9.7);

    //cout << mf << endl << endl;

    mf.ordenar("figuras_area.txt", "area");
    mf.ordenar("figuras_perimetro.txt", "perimetro");

    return 0;
}
