#include <iostream>
#include <string>
#include "../../../g2/e3/fecha.h"

namespace POO22 {

    class persona{
        protected:
            string _first_name;
            string _last_name;
            fecha _birth_date;
            string _address;
            unsigned int _dni;
        public:
            /* ----- Constructors/Destructors ----- */

            /*
            * @brief Creates a new persona instance
            */
            persona();

            /*
            * @brief Creates a new persona instance (from data)
            * @param first_name First Name
            * @param last_name  Last Name
            * @param birth_date Birth Date (fecha object)
            * @param address    Home Address
            * @param dni        National ID Number (Documento Nacional de Identidad)
            */
            persona(string& first_name,string& last_name,fecha& birth_date,
                    string& address,unsigned int dni);


            /*
            * @brief Creates a new persona instance (from even more data)
            * @param first_name First Name
            * @param last_name  Last Name
            * @param day        Birth Day
            * @param month        Birth Month
            * @param year        Birth Year
            * @param address    Home Address
            * @param dni        National ID Number (Documento Nacional de Identidad)
            */
            persona(string& first_name,string& last_name,int day,int month,int year,
                    string& address,unsigned int dni);

            /*
            * @brief Standard desctructor.
            */
            //~persona();

            /* ----- Getters ----- */

            /**
             * @brief Get the First Name
             *
             * @return string containing first name
             */
            string getFirstName();

            /**
             * @brief Get the Last Name
             *
             * @return string containing Last Name
             */
            string getLastName();

            /**
             * @brief Get the Birth Date
             *
             * @return fecha object containing Birth Date
             */
            fecha& getBirthDate();

            /**
             * @brief Get the Birth Day
             *
             * @return (int) Day of Birth
             */
            int getBirthDay();

            /**
             * @brief Get the Home Address
             *
             * @return string containing Home Address
             */
            string getAddress();

            /**
             * @brief Get National ID Number
             *
             * @return uint containing DNI
             */
            unsigned int getDNI();

            /* ----- Setters ----- */

            /**
             * @brief Set First Name
             *
             * @param first_name
             */
            void setFirstName(string& first_name);

            /**
             * @brief Set Last Name
             *
             * @param last_name
             */
            void setLastName(string& last_name);

            /**
             * @brief Set Birth Date from fecha object
             *
             * @param (fecha) birth_date
             */
            void setBirthDate(fecha& birth_date);

            /**
             * @brief Set Birth Date from int data
             *
             * @param day   Birth day
             * @param month Birth month
             * @param year  Birth year
             *
             * @return (bool) confirms successfull operation
             */
            bool setBirthDate(int day,int month,int year);

            /**
             * @brief Set Home Address from string
             *
             * @param address (string)
             */
            void setAddress(string& address);

            /**
             * @brief Set National ID from string
             *
             * @param dni
             */
            void setDNI(unsigned int& dni);

            /* ----- I/O methods ----- */

            friend ostream& operator << (ostream& os, persona& p);
    };
    ostream& operator << (ostream& os, persona& p);
}
