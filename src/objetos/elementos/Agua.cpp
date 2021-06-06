#include "Agua.h"

#include <iostream>
using std::cout;
using std::endl;
Agua::Agua():Elemento(){

}
Agua::Agua(Coordenada posicion,char nombre,int cantidad):Elemento(posicion,nombre,cantidad)
{
}

Agua::~Agua()
{
}

void Agua::mostrar(){
    cout<<"Objeto: Agua - Cantidad: "<<this->cantidad<<endl;
}