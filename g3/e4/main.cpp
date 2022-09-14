#include <cassert>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s("A piece of text");
    int start = 0;
    string repl;
    int found = -1;
    while (found != 0){
        getline(cin,repl);
        found = s.find(repl);
    }

    s.replace(start,repl.size(),repl);
    cout << s;
    return 0;
}
