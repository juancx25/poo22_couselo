#include "cRadioReloj.h"
//TIME
cTime::cTime(unsigned int h,unsigned int m,unsigned int s){
    hora = h;
    minuto = m;
    segundo = s;
}

unsigned int cTime::getHora(){ return hora; }
unsigned int cTime::getMin(){ return minuto; }
unsigned int cTime::getSeg(){ return segundo; }

void cTime::setHora(unsigned int h){ hora = h; }
void cTime::setMin(unsigned int m){ minuto = m; }
void cTime::setSeg(unsigned int s){ segundo = s; }

ostream& operator << (ostream& os,const cTime& time){
    os << time.hora << ':' << time.minuto << ':' << time.segundo;
    return os;
}

//RELOJ

cReloj::cReloj(unsigned int h,unsigned int m,unsigned int s,char* mar)
{
    time = cTime(h,m,s);
    marca = mar;
}
cReloj::cReloj(cTime& t,char* mar){
    time = t;
    marca = mar;
}

cTime cReloj::getTiempo() { return time; }
char* cReloj::getMarca(){ return marca; }
void cReloj::setTiempo(unsigned int h,unsigned int m,unsigned int s){
    time.setHora(h);
    time.setMin(m);
    time.setSeg(s);
}
void cReloj::setMarca(char* m){ marca = m; }

void cReloj::incrementarTiempo(){
    unsigned int h=time.getHora();unsigned int m=time.getMin();unsigned int s=time.getSeg();
    if (s<59) time.setSeg(s+1);
    else if (m<59){
        time.setSeg(0);
        time.setMin(m+1);
    }
    else if (h<23){
        time.setSeg(0);
        time.setMin(0);
        time.setHora(h+1);
    }
    else{
        time.setSeg(0);
        time.setMin(0);
        time.setHora(0);
    }
}


//RADIO
cRadio::cRadio(float f,TipoDeBanda b,bool prend){
    frecuencia = f;
    banda = b;
    prendido = prend;
}

float cRadio::getFrec(){ return frecuencia; }
TipoDeBanda cRadio::getTipoBanda(){ return banda; }
bool cRadio::getPrendido(){ return prendido; }

void cRadio::setFrec(float f){ frecuencia = f; }
void cRadio::setBanda(TipoDeBanda tipo){ banda = tipo; }
void cRadio::setPrendido(bool value){ prendido = value; }


//RADIO RELOJ
cRadioReloj::cRadioReloj(cTime tim,TipoAlarma t,bool prend) : cRadio(100.1),  cReloj(tim)
{
    alarma = cTime();
    tipo = t;
    prendido = prend;
}

cRadioReloj::cRadioReloj(cTime tim,cTime alarm,TipoAlarma t,bool prend) : cRadio(),  cReloj(tim)
{
    alarma = alarm;
    tipo = t;
    prendido = prend;
}

cTime cRadioReloj::getAlarma(){ return alarma; }
TipoAlarma cRadioReloj::getTipo(){ return tipo; }
bool cRadioReloj::verificarAlarma(){ return prendido; }

void cRadioReloj::setAlarma(cTime alarm){ alarma = alarm; }
void cRadioReloj::setAlarma(unsigned int h,unsigned int m,unsigned int s){ alarma = cTime(h,m,s); }
void cRadioReloj::setTipo(TipoAlarma t){ tipo = t; }
void cRadioReloj::setPrendido(bool pren){ prendido = pren; }
