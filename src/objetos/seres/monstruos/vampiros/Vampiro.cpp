#include "Vampiro.h"
#include <iostream>
using std::cout;
using std::endl;
Vampiro::Vampiro():Monstruo(){
    
}
Vampiro::Vampiro(Coordenada posicion,char nombre):Monstruo(posicion,nombre)
{
}
void Vampiro::mostrar(){
    cout<<"Objeto: Vampiro"<<endl;
}
Vampiro::~Vampiro()
{
}
