#ifndef BECARIO_H_INCLUDED
#define BECARIO_H_INCLUDED

//#include "persona/persona.h"
#include "estudiante/estudiante.h"
#include "empleado/empleado.h"
#include <iostream>

using namespace std;

namespace POO22{

    class becario : public empleado , public estudiante{

        private:
            string _type;
            int _duration;
            string _lab;
            string _director;
        public:

            /* ----- Constructors ----- */
            becario();
            becario(string& first_name,string& last_name,fecha& birth_date,string& address,unsigned int dni,
                    string& career,int subjects,fecha& entry_date,float average,
                    string& category,fecha& start_date,float salary,
                    string& type,int duration,string& lab, string& director);

            /* ----- Getters ----- */
            string getType();
            int getDuration();
            string getLab();
            string getDirector();

            /* ----- Setters ----- */
            void setType(string& type);
            void setDuration(int duration);
            void setLab(string& lab);
            void setDirector(string& director);

            /* ----- I/O methods ----- */
            friend ostream& operator << (ostream& os,becario& b);

    };
    /* ----- I/O methods ----- */
    ostream& operator << (ostream& os,becario& b);


}


#endif // BECARIO_H_INCLUDED
