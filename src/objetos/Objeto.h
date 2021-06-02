#ifndef OBJETO_H
#define OBJETO_H

#include <string>
#include "Coordenada.h"
using std::string;
class Objeto{
    protected: 
        string nombre;
        Coordenada posicion;
    public:
        Objeto(Coordenada posicion,string nombre):nombre(nombre),posicion(posicion){
        }
        ~Objeto(){    
        }
        virtual void mostrar()=0;
        Coordenada  obtener_posicion(){
            return posicion;
        }
};

#endif