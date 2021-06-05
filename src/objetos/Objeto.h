#ifndef OBJETO_H
#define OBJETO_H

#include <string>
#include "Coordenada.h"
using std::string;

class Objeto{
    protected:
        char nombre;
        string cuadrante;
        Coordenada posicion;
    public:
        Objeto():cuadrante(),posicion(){
            this->nombre=0;
        }
        Objeto(Coordenada posicion,char nombre):nombre(nombre),posicion(posicion){
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
        char obtener_nombre(){
            return this->nombre;
        }
};

#endif