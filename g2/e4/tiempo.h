#include <iostream>
#include <iomanip>

using namespace std;

namespace POO22 {

    class tiempo {
        private:
            unsigned int _hora;
            unsigned int _min;
            unsigned int _seg;

            static int _format;
            
        public:
            tiempo();
            tiempo(int h,int m,int s);

            void setHora(int h);
            void setMinutos(int m);
            void setSegundos(int s);
            void setTiempo(int h,int m,int s);

            int getHora();
            int getMinutos();
            int getSegundos();
            int getFormat();

            bool validar();
            void acarrear();

            void ingresarDatos();
            
            friend ostream& operator << (ostream& os,tiempo& t);
        protected:
    };
    ostream& operator << (ostream& os,tiempo& t);
}