#include <iostream>
#include <utility>

using namespace std;

pair<char,char> minusc_mayusc(int value){
    pair<char,char> result;
    if (value>=97){
        result.first = value;
        result.second = value-32;
    }
    else{
        result.first = value+32;
        result.second = value;
    }
    return result;
}

int main()
{
    int value = 0;

    while(((value<65) || (value>90)) && ((value<97) || (value>122))){
        cout << "Ingrese un numero en los rangos 65-90 o 97-122: ";
        cin >> value;
    }

    pair<char,char> r = minusc_mayusc(value);

    cout << "Minuscula: " << r.first << endl << "Mayuscula: " << r.second << endl;

    return 0;
}
