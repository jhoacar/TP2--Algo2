#include "Humano.h"
#include <iostream>
using std::cout;
using std::endl;
Humano::Humano():Ser(){

}
Humano::Humano(Coordenada posicion,char nombre):Ser(posicion,nombre)
{
}
void Humano::mostrar(){
    cout<<"Objeto: Humano "<<endl;
}
Humano::~Humano()
{
}
