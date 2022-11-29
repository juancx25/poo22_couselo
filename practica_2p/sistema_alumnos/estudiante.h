#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED
#include "persona.h"
#include <iostream>
#include <fstream>

using namespace std;


namespace POO22{

    class estudiante: public persona{

        protected:
            string _career;
            int _subjects;
            fecha _entry_date;
            float _average;

        public:

            /* ----- Constructors ----- */
            estudiante();

            estudiante(string& first_name,string& last_name,fecha& birth_date,
                       string& address,unsigned int dni,string& career,int subjects,fecha entry_date,float average);

            estudiante(string& first_name,string& last_name,int b_day,int b_month,int b_year,string& address,unsigned int dni,string& career,int subjects,int e_day,int e_month,int e_year,float average);

            /* ----- Getters ----- */
            string getCareer();
            int getSubjects();
            fecha& getEntryDate();
            float getAverage();

            /* ----- Setters ----- */
            void setCareer(string& career);
            void setSubjects(int subjects);
            void setEntryDate(fecha& entry_date);
            void setEntryDate(int e_day,int e_month,int e_year);
            void setAverage(float average);

            /* ----- I/O ----- */
            friend ostream& operator << (ostream& os,estudiante& est);
            void export_bin(const string& file_name);
    };

    /* ----- I/O ----- */
    ostream& operator << (ostream& os,estudiante& est);
}

#endif // ESTUDIANTE_H_INCLUDED
