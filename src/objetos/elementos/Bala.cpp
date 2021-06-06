#include "Bala.h"
#include <iostream>
using std::cout;
using std::endl;

Bala::Bala():Elemento(){

}
Bala::Bala(Coordenada posicion,char nombre,int cantidad):Elemento(posicion,nombre,cantidad)
{
}
void Bala::mostrar(){
    cout<<"Nombre: Bala - Cantidad: "<<this->cantidad<<endl;
}
Bala::~Bala()
{
}
