#include <iostream>
#include "../persona/persona.h"
#include "../../g2_e3/fecha.h"

using namespace std;

namespace POO22 {

    class empleado: public persona {
        protected:

            fecha _hiring_date;

        public:
            /* ----- Constructors ----- */

            /**
             * @brief Standard Empleado class constructor
             *
             */
            empleado();


            empleado(string& first_name,string& last_name,fecha& birth_date,
                     string& address,string& dni,fecha& hiring_date);

            empleado(string& first_name,string& last_name,int b_day,int b_month,int b_year,
                     string& address,string& dni,int h_day,int h_month,int h_year);

            /* ----- Getters ----- */

            fecha& getHiringDate();

            /* ----- Setters ----- */

            void setHiringDate(fecha& h_date);

            void setHiringDate(int day,int month,int year);

            /* ----- I/O utilities ----- */

            friend ostream& operator <<(ostream& os,empleado& e);
    };
    ostream& operator <<(ostream& os,empleado& e);
}
