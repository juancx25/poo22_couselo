#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int size;
    stack<char> s;
    string aux;
    while (aux != "0"){
        cout << "Ingrese una palabra: ";
        cin >> aux;
        if (aux != "0") {
            size = aux.size();
            for (int i=0;i<size;i++){
                char c = aux.at(i);
                s.push(c);
            }
            s.push(' ');
        }
    }
    size = s.size();
    for (int i=0;i<size;i++){
        cout << s.top();
        s.pop();
    }

    return 0;
}
