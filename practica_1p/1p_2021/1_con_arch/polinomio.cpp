// polinomio.cpp - Implementaci�n de la clase CPolinomio
//
#include <iostream>
#include <cmath>
#include "polinomio.h"

/////////////////////////////////////////////////////////////////
// Constructor
CPolinomio::CPolinomio()
{
    polinomio.reserve(10); // reservar memoria para 10 t�rminos
}

// Asigna un t�rmino al polinomio coloc�ndolo en orden ascendente
// del exponente.
void CPolinomio::AsignarTermino(CTermino termino)
{
    if (termino.ObtenerCoeficiente() == 0) return;
    float c, coef = termino.ObtenerCoeficiente();
    int exp = termino.ObtenerExponente();

    // Insertar un nuevo t�rmino en orden ascendente del exponente.
    int i = polinomio.size() - 1;
    while (i >= 0 && termino.ObtenerExponente() < polinomio[i].ObtenerExponente())
        i--;
        if (i >= 0 && exp == polinomio[i].ObtenerExponente())
        {
            c = coef + polinomio[i].ObtenerCoeficiente();
            // T�rmino existente. Sumar los coeficientes.
            if (c)
                polinomio[i].AsignarCoeficiente(c);
            else
                polinomio.erase(polinomio.begin()+i);
        }
        else
            // Insertar un nuevo t�rmino
            polinomio.insert(polinomio.begin()+(i+1), termino);
}

// Sumar dos polinomios
CPolinomio CPolinomio::operator+(CPolinomio& polB)
{
    unsigned ipa = 0, ipb = 0;
    size_t na = ObtenerNroTerminos(), nb = polB.ObtenerNroTerminos();
    float coefA, coefB;
    int expA, expB;
    CPolinomio polR;

    // Sumar polA con polB
    while (ipa < na && ipb < nb)
    {
        coefA = polinomio[ipa].ObtenerCoeficiente();
        coefB = polB.polinomio[ipb].ObtenerCoeficiente();
        expA = polinomio[ipa].ObtenerExponente();
        expB = polB.polinomio[ipb].ObtenerExponente();
        if (polinomio[ipa] == polB.polinomio[ipb])
        {
            if (coefA + coefB != 0)
                polR.AsignarTermino(CTermino(coefA + coefB, expA));
                ipa++, ipb++;
        }
        else if (polinomio[ipa] < polB.polinomio[ipb])
        {
            polR.AsignarTermino(CTermino(coefA, expA));
            ipa++;
        }
        else
        {
            polR.AsignarTermino(CTermino(coefB, expB));
            ipb++;
        }
    }

    // T�rminos restantes de polA o de polB
    while (ipa < na)
    {
        coefA = polinomio[ipa].ObtenerCoeficiente();
        expA = polinomio[ipa].ObtenerExponente();
        polR.AsignarTermino(CTermino(coefA, expA));
        ipa++;
    }
    while (ipb < nb)
    {
        coefB = polB.polinomio[ipb].ObtenerCoeficiente();
        expB = polB.polinomio[ipb].ObtenerExponente();
        polR.AsignarTermino(CTermino(coefB, expB));
        ipb++;
    }
    return polR;
}

// Visualizar los t�rminos de un polinomio.
// Operador de inserci�n.
ostream& operator<<(ostream& os, CPolinomio& polX)
{
    int i = polX.ObtenerNroTerminos();

    while ( i-- )
        polX.polinomio[i].VisualizarTermino();
    return os;
}

// Operador llamada a funci�n
double CPolinomio::operator()(double x)
{
    double v = 0;
    for (int i = 0; i < ObtenerNroTerminos(); i++)
        v += polinomio[i].ObtenerCoeficiente() *
        pow(x, polinomio[i].ObtenerExponente());
    return v;
}

// Operador de conversi�n de CPolinomio a double
CPolinomio::operator double()
{
    return (*this)(1); // invoca al operador ()
}
/////////////////////////////////////////////////////////////////

