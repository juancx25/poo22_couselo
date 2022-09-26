#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED
using namespace std;

class CTermino{
    private:
        float coef;
        int exp;
    public:
        CTermino(float coef=0,int exp=0);

        float ObtenerCoeficiente();
        int ObtenerExponente();


}

class CPolinomio{
    private:
        CTermino* polinomio;

    public:

}


#endif // POLINOMIO_H_INCLUDED
