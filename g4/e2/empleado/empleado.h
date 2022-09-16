#include <iostream>
#include "../persona/persona.h"
#include "../../../g2/e3/fecha.h"

using namespace std;

namespace POO22 {

    class empleado: public persona {
        protected:
            string _category;
            fecha _start_date;
            float _salary;
        public:
            /* ----- Constructors ----- */

            /**
             * @brief Standard Empleado class constructor
             *
             */
            empleado();


            empleado(string& first_name,string& last_name,fecha& birth_date,
                     string& address,unsigned int dni,string& category,fecha& start_date, float salary);

            empleado(string& first_name,string& last_name,int b_day,int b_month,int b_year,
                     string& address,unsigned int dni,string& category,int s_day,int s_month,int s_year,float salary);

            /* ----- Getters ----- */

            string getCategory();
            fecha& getStartDate();
            float getSalary();

            /* ----- Setters ----- */

            void setCategory(string& category);
            void setStartDate(fecha& s_date);
            void setStartDate(int day,int month,int year);
            void setSalary(float salary);

            /* ----- I/O utilities ----- */

            friend ostream& operator <<(ostream& os,empleado& e);
    };
    ostream& operator <<(ostream& os,empleado& e);
}
