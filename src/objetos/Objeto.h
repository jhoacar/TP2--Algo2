#ifndef OBJETO_H
#define OBJETO_H

#include <string>
#include "Coordenada.h"
using std::string;

class Objeto{
    protected: 
        string nombre;
        string cuadrante;
        Coordenada posicion;
    public:
        Objeto():nombre(),cuadrante(),posicion(){
            this->nombre="";
            this->cuadrante="";
            this->posicion={0,0};
        }
        Objeto(Coordenada posicion,string nombre):nombre(nombre),posicion(posicion){
            this->cuadrante="";        
        }
        ~Objeto(){
        }
        virtual void mostrar()=0;
        
        Coordenada obtener_posicion(){
            return this->posicion;
        }
        string obtener_cuadrante(){
            return this->cuadrante;
        }
};

#endif