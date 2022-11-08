#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int aux=1;
    vector<int> v;
    while(aux != 0){
        cout << "Ingrese un numero (fin=0): ";
        cin >> aux;
        if (aux!=0){
            v.insert(v.begin(),aux);
        }
    }
    int size = int(v.size());
    for (int i=0;i<size;i++){
        cout << v[i] << " ";
    }
    return 0;
}
