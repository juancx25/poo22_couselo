#ifndef POLAR_H_INCLUDED
#define POLAR_H_INCLUDED
#include <iostream>
#include "complex.h"

using namespace std;

namespace POO22{

    class polar : public complex {

        protected:
            double _mod;
            double _phase;

        public:
            /* ----- Constructors ----- */
            polar();
            polar(const complex& c);
            polar(double a,double b,bool is_polar);

            /* ----- Getters ----- */
            double getMod();
            double getPhase();

            /* ----- Setters ----- */
            void setMod(double mod);
            void setPhase(double phase);

            /* ----- I/O methods ----- */
            friend ostream& operator << (ostream& os,const polar& p);

    };
    /* ----- I/O methods ----- */
    ostream& operator << (ostream& os,const polar& p);

}

#endif // POLAR_H_INCLUDED
