#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string data;
    ifstream in;
    in.open("datos.txt",ios::in);


    getline(in,data);

    cout << data;

    return 0;
}
