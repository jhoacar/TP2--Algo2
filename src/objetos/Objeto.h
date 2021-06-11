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
        /*
        PRE:
        POST: 
        */
        Objeto():cuadrante(),posicion(){
            this->nombre=0;
        }
        /*
        PRE: La posicion y el nombre 
        POST: Crea el objeto con la informacion brindad
        */
        Objeto(Coordenada posicion,char nombre):nombre(nombre),posicion(posicion){
            this->cuadrante="";        
        }
        /*
        PRE:
        POST: Destruye por defecto cada objeto, destruyendo cada atributo
        */
        virtual ~Objeto() = default;
        /*
        PRE: 
        POST: Metodo virtual puro para la posterior herencia de esta clase abstracta 
        */
        virtual void mostrar()=0;
        /*
        PRE:
        POST: Devuelve la posicion del objeto
        */
        Coordenada obtener_posicion(){
            return this->posicion;
        }
        /*
        PRE:
        POST: Devuelve el cuadrante del objeto
        */
        string obtener_cuadrante(){
            return this->cuadrante;
        }
        /*
        PRE:
        POST: Devuelve el nombre del objeto
        */
        char obtener_nombre(){
            return this->nombre;
        }
        /*
        PRE: Un cuadrante a asignar
        POST: Asigna el cuadrante al objeto
        */
        void asignar_cuadrante(string cuadrante){
            this->cuadrante=cuadrante;
        }
};

#endif