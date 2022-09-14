#include <string>
#include <iostream>

using namespace std;

int main(){
    string bigNews("I saw Elvis in a UFO. ");
    cout << bigNews << endl;

    cout << "Size = " << bigNews.size() << endl;            //22 ok

    cout << "Capacity = " << bigNews.capacity() << endl;    //?? --> 22 (Igual al size: fue declarado)


    bigNews.insert(1," thought I");
    cout << bigNews << endl;
    cout << "Size = " << bigNews.size() << endl;            //22+10=32 ok
    cout << "Capacity = " << bigNews.capacity() << endl;    //?? --> 44 (No alcanza 22, se duplica)

    bigNews.reserve(500);
    bigNews.append("I've been working to hard.");
    cout << bigNews << endl;
    cout << "Size = " << bigNews.size() << endl;            //32+26=58 ok
    cout << "Capacity = " << bigNews.capacity() << endl;    //500 ok (lo reservé yo a mano)
    return 0;
}
