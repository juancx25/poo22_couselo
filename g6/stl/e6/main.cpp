#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> q;
    int aux=1;
    while(aux != 0){
        cout << "Ingrese un numero (fin=0): ";
        cin >> aux;
        if (aux!=0){
            //q.push_back(aux);    //Ejercicio 3
            q.insert(q.begin(),aux);    //Ejercicio 4
        }
    }
    for (deque<int>::iterator it = q.begin() ; it != q.end() ; ++it){
        cout << *it << " ";
    }
    return 0;
}
