#include "Estaca.h"
#include <iostream>
using std::cout;
using std::endl;
Estaca::Estaca():Elemento(){
    
}
Estaca::Estaca(Coordenada posicion,char nombre,int cantidad):Elemento(posicion,nombre,cantidad)
{
}
void Estaca::mostrar(){
    cout<<"Objeto: Estaca"<<endl;
}
Estaca::~Estaca()
{
}
