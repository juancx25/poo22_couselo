#include <iostream>

using namespace std;

namespace POO22 {

    class complex {

        protected:
            double _real;
            double _imag;

        public:

            /* ----- Constructors ----- */
            complex();
            complex(double real,double imag);

            /* ----- Getters ----- */
            double getReal() const;
            double getImag() const;

            /* ----- Setters ----- */
            void setReal(double real);
            void setImag(double imag);

            /* ----- I/O methods ----- */
            friend istream& operator << (istream& is,complex& c);
            friend ostream& operator << (ostream& os,complex& c);

            /* ----- Polar notations ----- */
            double mod();
            double angle();

            /* ----- Operators ----- */
            complex operator + (const complex& b);
            complex operator + (const double& b);

            complex operator - (const complex& b);
            complex operator - (const double& b);

            complex operator * (const complex& b);
            complex operator * (const double& b);

            complex operator / (const complex& b);
            complex operator / (const double& b);

    };
    ostream& operator << (ostream& os,complex& c);
    istream& operator << (istream& is,complex& c);
    //complex operator + (const double& a,const POO22::complex& b);


}
POO22::complex operator + (const double& a,const POO22::complex& b);
POO22::complex operator - (const double& a,const POO22::complex& b);
POO22::complex operator * (const double& a,const POO22::complex& b);
POO22::complex operator / (const double& a,const POO22::complex& b);
