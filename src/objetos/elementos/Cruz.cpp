#include "Cruz.h"
#include <iostream>
using std::cout;
using std::endl;

Cruz::Cruz():Elemento(){

}
Cruz::Cruz(Coordenada posicion,char nombre,int cantidad):Elemento(posicion,nombre,cantidad)
{
}

Cruz::~Cruz()
{
}
void Cruz::mostrar(){
    cout<<"Objeto: Cruz"<<endl; 
}