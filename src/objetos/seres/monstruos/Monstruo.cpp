#include "Monstruo.h"
#include <iostream>
using std::cout;
using std::endl;
Monstruo::Monstruo():Ser(){

}
Monstruo::Monstruo(Coordenada posicion,char nombre):Ser(posicion,nombre)
{
}
void Monstruo::mostrar(){
    cout<<"Objeto: Monstruo "<<endl;
}
Monstruo::~Monstruo()
{
}
