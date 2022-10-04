#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <malloc.h>
#include <iostream>
#include <string.h>

using namespace std;

namespace POO22 {

    class fecha{
        private:
            int _day;
            int _month;
            int _year;
            static int _format;
            static const char* _months[];
        public:
            fecha(int day=1,int month=1, int year=1970);
            //~fecha();

            void setFecha(int day, int month, int year);
            void setDay(int day);
            void setMonth(int month);
            void setYear(int year);
            void setFormat(int value);

            int getFormat();
            int getDay();
            int getMonth();
            int getYear();

            void ingresarFecha();
            void imprimir();
            char* mesLetras();
            bool validarFecha();
            friend ostream& operator << (ostream& co, fecha& date);
    };
    ostream& operator << (ostream& co, fecha& date);
}






#endif // FECHA_H_INCLUDED
