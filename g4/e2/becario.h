#ifndef BECARIO_H_INCLUDED
#define BECARIO_H_INCLUDED

#include "persona/persona.h"
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

    };

}


#endif // BECARIO_H_INCLUDED
