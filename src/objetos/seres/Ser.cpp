#include "Ser.h"

#include <iostream>

Ser::Ser():Objeto(){

}

Ser::Ser(Coordenada posicion,string nombre):Objeto(posicion,nombre){
	
}

Ser::~Ser()
{
}
void Ser::mostrar(){
    std::cout<<"Nombre: "<<this->nombre<<std::endl;
}
