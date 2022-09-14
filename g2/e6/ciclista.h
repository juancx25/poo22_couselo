#ifndef CICLISTA_H_INCLUDED
#define CICLISTA_H_INCLUDED

#include <vector>
#include <iostream>
#include "../g2_e3/fecha.h"
#include "../g2_e5/persona.h"

using namespace std;

namespace POO22 {

    class ciclista: public persona {

    private:
        int _test1;
        int _test2;

    public:
        /* ----- Constructors ----- */

        ciclista();

        ciclista(string& first_name,string& last_name,fecha& birth_date,
                 int test1,int test2);

        /* ----- Getters ----- */

        int getAge();
        int getTest1();
        int getTest2();

        /* ----- Setters ----- */

        void setTest1(int test1);
        void setTest2(int test2);

        /* ----- I/O methods ----- */

        void insert();
        friend ostream& operator << (ostream& os,ciclista& c);

    };

    ostream& operator << (ostream& os,ciclista& c);
}

#endif // CICLISTA_H_INCLUDED
