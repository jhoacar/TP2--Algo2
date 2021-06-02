#include "Ser.h"

#include <iostream>

Ser::Ser(Coordenada posicion,string nombre):Objeto(posicion,nombre){
	
}

Ser::~Ser()
{
}
void Ser::mostrar(){
    std::cout<<nombre<<std::endl;
}
