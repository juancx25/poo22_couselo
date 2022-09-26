#ifndef CRELOJ_H_INCLUDED
#define CRELOJ_H_INCLUDED
#include <iostream>
#include <cstring>
using namespace std;

class cTime
{
    private:
        unsigned int hora;
        unsigned int minuto;
        unsigned int segundo;
    public:
        cTime(unsigned int h=0,unsigned int m=0,unsigned int s=0);

        unsigned int getHora();
        unsigned int getMin();
        unsigned int getSeg();

        void setHora(unsigned int h);
        void setMin(unsigned int m);
        void setSeg(unsigned int s);

        friend ostream& operator << (ostream& os,const cTime& time);

};
ostream& operator << (ostream& os,const cTime& time);

class cReloj
{
    protected:
        cTime time;
        char* marca;
    public:
        cReloj(unsigned int h=0,unsigned int m=0,unsigned int s=0,char* mar=NULL);
        cReloj(cTime& t,char* mar=NULL);

        cTime getTiempo();
        char* getMarca();
        void setTiempo(unsigned int h,unsigned int m,unsigned int s);
        void setMarca(char* m);

        void incrementarTiempo();
};

enum TipoDeBanda {AM, FM};
class cRadio
{
    protected:
        float frecuencia;
        TipoDeBanda banda;
        bool prendido;
    public:
        cRadio(float f = 95.5,TipoDeBanda b = FM,bool prend = false);

        float getFrec();
        TipoDeBanda getTipoBanda();
        bool getPrendido();

        void setFrec(float f);
        void setBanda(TipoDeBanda tipo);
        void setPrendido(bool value);
};

enum TipoAlarma {Musica, Timbre};
class cRadioReloj: public cRadio, public cReloj
{
    protected:
        cTime alarma;
        TipoAlarma tipo;
        bool prendido;
    public:
        cRadioReloj(cTime tim,TipoAlarma t = Timbre,bool prend = false);
        cRadioReloj(cTime tim,cTime alarm,TipoAlarma t = Timbre,bool prend = false);

        cTime getAlarma();
        TipoAlarma getTipo();
        bool verificarAlarma();

        void setAlarma(cTime alarm);
        void setAlarma(unsigned int h,unsigned int m,unsigned int s);
        void setTipo(TipoAlarma t);
        void setPrendido(bool pren);
};



#endif // CRELOJ_H_INCLUDED
