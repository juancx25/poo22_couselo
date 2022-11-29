#ifndef MANEJADORFIGURAS_H_INCLUDED
#define MANEJADORFIGURAS_H_INCLUDED
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include "figura.h"

class ManejadorFiguras{
    private:
        std::vector<figura*> figuras;
    public:
        void recuperarFiguras(const char* file_name);
        void guardarFiguras(const char* file_name);

        void guardarFiguras_bin(const char* file_name);
        void recuperarFiguras_bin(const char* file_name);

        void ordenar(const char* file_name,const char* criterio);

        friend std::ostream& operator << (std::ostream& os,ManejadorFiguras& mf);

};

bool compararArea(figura* f1,figura* f2){
    if (f1->getArea() > f2->getArea()) return true;
    else return false;
}

bool compararPerimetro(figura* f1,figura* f2){
    if (f1->getPerimetro() < f2->getPerimetro()) return true;
    else return false;
}

void ManejadorFiguras::ordenar(const char* file_name,const char* criterio){
    string crit(criterio);
    if (crit == "area"){
        std::sort(figuras.begin(),figuras.end(),&compararArea);
        this->guardarFiguras(file_name);
    }
    if (crit == "perimetro"){
        std::sort(figuras.begin(),figuras.end(),&compararPerimetro);
        this->guardarFiguras(file_name);
    }
}

std::ostream& operator << (std::ostream& os,ManejadorFiguras& mf){
    for (vector<figura*>::iterator it = mf.figuras.begin() ; it != mf.figuras.end() ; ++it ){
        os << **it << endl;
    }
    return os;
}

/* ------------------------------------- TXT ------------------------------------- */

void ManejadorFiguras::recuperarFiguras(const char* file_name){
    std::ifstream in;
    in.exceptions ( ifstream::badbit );
    try{
        in.open(file_name);
        string tipo_figura;uint32_t fore_color;uint32_t back_color;
        double base;double altura;
        string line = "";
        while(getline(in,line)){
            stringstream str_in(line);
            string str_temp;

            getline(str_in,str_temp,';');
            tipo_figura = str_temp;

            getline(str_in,str_temp,';');
            fore_color = stoul(str_temp);

            getline(str_in,str_temp,';');
            back_color = stoul(str_temp);

            getline(str_in,str_temp,';');
            base = stod(str_temp);

            if (tipo_figura == "Rectangulo"){
                getline(str_in,str_temp,';');
                altura = stod(str_temp);
                rectangulo* aux = new rectangulo(tipo_figura,fore_color,back_color,base,altura);
                figuras.push_back(aux);
            }
            if (tipo_figura == "Circulo"){
                circulo* aux = new circulo(tipo_figura,fore_color,back_color,base,0);
                figuras.push_back(aux);
            }
            if (tipo_figura == "Triangulo"){
                getline(str_in,str_temp,';');
                altura = stod(str_temp);
                triangulo* aux = new triangulo(tipo_figura,fore_color,back_color,base,altura);
                figuras.push_back(aux);
            }
        }
    }catch(const ifstream::failure& e) {
        cout << "Excepcion al abrir/leer el archivo\n";
    }
    in.close();
}

void ManejadorFiguras::guardarFiguras(const char* file_name){
    std::ofstream out;
    out.exceptions ( ofstream::badbit );

    try{
        out.open(file_name);
        for (vector<figura*>::iterator it = figuras.begin() ; it != figuras.end() ; ++it ){
            (**it).filewrite_txt(out);
        }
    }catch(const ofstream::failure& e) {
        cout << "Excepcion al abrir/escribir el archivo\n";
    }
    out.close();
}

/* ------------------------------------- BIN ------------------------------------- */

long long unsigned int fileSize(const char* fname){
   ifstream file(fname,ios::binary);
   file.seekg(0, ios::end);
   long long unsigned int size = file.tellg();
   file.close();
   return size;
}

void ManejadorFiguras::guardarFiguras_bin(const char* file_name){
    std::ofstream out;
    out.exceptions ( ofstream::badbit );

    try{
        out.open(file_name, ios::binary);
        for (vector<figura*>::iterator it = figuras.begin() ; it != figuras.end() ; ++it ){
            figura* aux = *it;

            string tipo = aux->getTipo();
            uint32_t size = tipo.size();
            out.write(reinterpret_cast<const char*>(&size),sizeof(uint32_t));
            out.write(tipo.c_str(),size);

            out.write(reinterpret_cast<const char*>(&(aux->getForeColor())),sizeof(uint32_t));

            out.write(reinterpret_cast<const char*>(&(aux->getBackColor())),sizeof(uint32_t));

            double base = aux->getBase();
            out.write(reinterpret_cast<const char*>(&base),sizeof(double));
            double altura = aux->getAltura();
            out.write(reinterpret_cast<const char*>(&altura),sizeof(double));

        }
    }catch(const ofstream::failure& e) {
        cout << "Excepcion al abrir/escribir el archivo\n";
    }
    out.close();
}

void ManejadorFiguras::recuperarFiguras_bin(const char* file_name){
    std::ifstream in;
    in.exceptions ( ifstream::badbit );
    try{
        unsigned int file_size = fileSize(file_name);
        in.open(file_name, ios::binary);
        string tipo_figura;uint32_t fore_color;uint32_t back_color;
        double base;double altura;
        while(in.tellg()<file_size){

            int len;
            in.read((char*)&len,sizeof(uint32_t));
            char* temp = new char[len+1];
            in.read(temp,len);
            temp[len] = '\0';
            tipo_figura = temp;
            delete [] temp;

            in.read((char*)&fore_color,sizeof(uint32_t));
            in.read((char*)&back_color,sizeof(uint32_t));

            in.read((char*)&base,sizeof(double));
            in.read((char*)&altura,sizeof(double));

            if (tipo_figura == "Rectangulo"){
                rectangulo* aux = new rectangulo(tipo_figura,fore_color,back_color,base,altura);
                figuras.push_back(aux);
            }
            if (tipo_figura == "Circulo"){
                circulo* aux = new circulo(tipo_figura,fore_color,back_color,base,0);
                figuras.push_back(aux);
            }
            if (tipo_figura == "Triangulo"){
                triangulo* aux = new triangulo(tipo_figura,fore_color,back_color,base,altura);
                figuras.push_back(aux);
            }

        }

    }catch(const ifstream::failure& e) {
        cout << "Excepcion al abrir/leer el archivo\n";
    }
    in.close();
}



#endif // MANEJADORFIGURAS_H_INCLUDED
