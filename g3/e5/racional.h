#ifndef CRACIONAL_H_INCLUDED
#define CRACIONAL_H_INCLUDED
#include <iostream>

using namespace std;

namespace POO22{

    class racional {

        private:
            int _num;
            int _den;
        public:

            /* ----- Constructors ----- */
            racional();
            racional(int num, int den);

            /* ----- Getters ----- */
            int getNum();
            int getDen();

            /* ----- Setters ----- */
            void setNum(int num);
            void setDen(int den);

            /* ----- I/O methods ----- */
            friend ostream& operator << (ostream& os,racional& r);
            friend istream& operator >> (istream& is,racional& r);

            /* ----- Arithmetic ----- */
            void simplify(racional& r;
            racional operator +(racional& b);
    };
    ostream& operator << (ostream& os,racional& r);
    istream& operator >> (istream& is,racional& r);
}

#endif // CRACIONAL_H_INCLUDED
