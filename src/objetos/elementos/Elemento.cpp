#include "Elemento.h"

#include <iostream>

Elemento::Elemento(Coordenada posicion, string nombre ,int cantidad):Objeto(posicion,nombre){
	this->cantidad=cantidad;
}

Elemento::~Elemento()
{

}

void Elemento::mostrar(){
	std::cout<<nombre<<std::endl;
}