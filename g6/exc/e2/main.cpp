#include <iostream>

using namespace std;

int main()
{
    char ch;
    try{
        cin >> ch;
        if (ch == '0') throw ch;
    }
    catch(char e){
        cout << "Excepcion: Se ingreso el caracter '0'" << endl;
    }
    return 0;
}
