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
            racional(const int& num,const int& den);
            racional(const int& num);

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
            operator double() const;
            void simplify();
            racional operator + (racional b);
            friend racional operator + (double& d,racional& b);
            /* DUDA: Si le paso racional& b, la línea:
            c = a + static_cast<racional>(d); no me reconoce la función,
            pero sí me toma c = a + c si antes hago:
            c = static_cast<racional>(d);*/
            racional& operator += (racional& b);

            racional& operator ++ ();
            racional operator ++ (int dummy);
            racional& operator -- ();
            racional operator -- (int dummy);

            friend racional operator - (racional& r);
            friend racional operator - (double& d, racional& b);
            racional operator - (racional& b);
            racional operator - (double& d);
            racional& operator -= (racional& b);

            racional operator * (racional& b);

            racional operator / (racional& b);

            /* ----- Comparison ----- */
            friend bool operator == (const racional& r1, const racional& r2);
            friend bool operator < (const racional& r1, const racional& r2);
            friend bool operator > (const racional& r1, const racional& r2);
            friend bool operator ! (const racional& r);

    };
    /* ----- Arithmetic ----- */
    int mcd(int a, int b);
    racional operator + (double& d,racional& b);
    racional operator - (racional& r);

    /* ----- I/O methods ----- */
    ostream& operator << (ostream& os,racional& r);
    istream& operator >> (istream& is,racional& r);

    /* ----- Comparison ----- */
    bool operator == (const racional& r1, const racional& r2);
    bool operator < (const racional& r1, const racional& r2);
    bool operator > (const racional& r1, const racional& r2);
    bool operator ! (const racional& r);
}

#endif // CRACIONAL_H_INCLUDED
