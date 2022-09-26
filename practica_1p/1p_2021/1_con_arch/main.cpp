// polinomios.cpp - Trabajo con polinomios
//
#include <iostream>
#include "polinomio.h"
using namespace std;

CTermino IntroducirTermino(void);

int main() // funci�n principal
{
    CPolinomio PolinomioR, PolinomioB, PolinomioA;
    CTermino tx;

    cout << "T�rminos del polinomio A\n"
       << "(para finalizar introduzca 0 para el\n"
       << "coeficiente y para el exponente):\n\n";
    tx = IntroducirTermino();
    while (tx.ObtenerCoeficiente() || tx.ObtenerExponente())
    {
        PolinomioA.AsignarTermino(tx);
        tx = IntroducirTermino();
    }

    cout << "T�rminos del polinomio B\n"
       << "(para finalizar introduzca 0 para el\n"
       << "coeficiente y para el exponente):\n\n";
    tx = IntroducirTermino();
    while (tx.ObtenerCoeficiente() || tx.ObtenerExponente())
    {
        PolinomioB.AsignarTermino(tx);
        tx = IntroducirTermino();
    }

    // Operador +
    // Operador de asignaci�n por omisi�n
    PolinomioR = PolinomioA + PolinomioB;
    // Constructor copia por omisi�n
    CPolinomio Polinomio = PolinomioR;

    cout << "\nPolinomio A: "; cout << PolinomioA;
    cout << "\nPolinomio B: "; cout << PolinomioB;
    cout << "\nPolinomio R: "; cout << Polinomio;
    cout << endl;

    cout << "valor del polinomio para x = 5: " << PolinomioR(5) << endl;
    double v = PolinomioR; // valor del polinomio para x = 1
    cout << "valor del polinomio para x = 1: " << v << endl;
}

CTermino IntroducirTermino()
{
    float coef;
    int exp;
    cout << "Introduce coeficiente:    "; cin >> coef;
    cout << "Introduce exponente en X: "; cin >> exp;
    cout << endl;
    return CTermino(coef, exp);
}

