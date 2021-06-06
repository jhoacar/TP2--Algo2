#include "Escopeta.h"
#include <iostream>
using std::cout;
using std::endl;
Escopeta::Escopeta():Elemento(){
    
}
Escopeta::Escopeta(Coordenada posicion,char nombre,int cantidad):Elemento(posicion,nombre,cantidad)
{
}
void Escopeta::mostrar(){
    cout<<"Objeto - Escopeta"<<endl;
}
Escopeta::~Escopeta()
{
}
