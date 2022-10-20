#include <iostream>
#include <limits>

using namespace std;

double leerDouble(){

    cin.exceptions(ios::failbit | ios::badbit);             // Obliga a devolver una excepcion cuando se obtenga failbit o badbit

    double dato = 0.0;                                      // Inicializo el valor a leer
    try
    {
        cin >> dato;                                        //Operacion de lectura
    }
            // Por que usa el &?
    catch(ios_base::failure & e) //Captura una excepción
    {   //Si hubo excepcion:
        cout << e.what() << ": dato no valido" << endl;

        cin.clear();                                        // Limpia los flags de cin

        cin.ignore(numeric_limits<int>::max(), '\n');       // Vuelve a setear cin para leer infinitos caracteres
                                                            // hasta que se encuentre \n
    }

    // Duda: Tengo alguna forma de hacer una operacion si NO se devolvio excepcion? o solo revisando si !e
    return dato;
}

int main()
{
    double test = leerDouble();
    cout << "valor ingresado: " << test;    // Si me dio la excepcion sigue dando esto. hay forma de que no pase?
    return 0;
}
