#include "Elemento.h"
#include <iostream>

Elemento::Elemento():Objeto(){

}

Elemento::Elemento(Coordenada posicion, char nombre ,int cantidad):Objeto(posicion,nombre){
	this->cantidad=cantidad;
}

Elemento::~Elemento()
{

}

void Elemento::mostrar(){	
	std::cout<<"Nombre: "<<this->nombre<<" Cantidad: "<<this->cantidad<<std::endl;
}
int Elemento::obtener_cantidad(){
	return this->cantidad;
}
