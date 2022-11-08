#include <iostream>
#include "../e7/empleado.h"
#include <stack>

int main()
{
    std::stack<empleado*> s;
    char quit = 'N';
    while (quit!='S'){
        std::cout << "Agregando empleado...\n";
        empleado* aux = new empleado();
        s.push(aux);
        std::cout << "Desea dejar de ingresar? (S/N): ";
        std::cin >> quit;
        quit = toupper(quit);
    }
    while(!s.empty()){
        std::cout << *(s.top()) << std::endl;
        s.pop();
    }
    return 0;
}
