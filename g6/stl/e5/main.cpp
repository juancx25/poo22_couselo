#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> L;
    int aux=1;
    while(aux != 0){
        cout << "Ingrese un numero (fin=0): ";
        cin >> aux;
        if (aux!=0){
            L.push_back(aux);    //Ejercicio 3
            //L.insert(L.begin(),aux);    //Ejercicio 4
        }
    }
    for (list<int>::iterator it = L.begin(); it != L.end(); ++it){
        cout << *it << " ";
    }
    return 0;
}
