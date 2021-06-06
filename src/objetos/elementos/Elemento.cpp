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
int Elemento::obtener_cantidad(){
	return this->cantidad;
}
