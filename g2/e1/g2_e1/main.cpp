#include <iostream>

using namespace std;

int main ()
{
 string cadena;
 cin >> cadena;
/*  cin no lee el \n, por lo que lo primero que lee getline es \n y finaliza la lectura,
    sobreescribiendo lo escrito anteriormente*/
 //getline(cin, cadena);
 cout << "La cadena ingresada es: " << cadena << endl;
 return 0;
}
