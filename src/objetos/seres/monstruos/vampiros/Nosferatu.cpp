#include "Nosferatu.h"
#include <iostream>
using std::cout;
using std::endl;
Nosferatu::Nosferatu():Vampiro(){

}
Nosferatu::Nosferatu(Coordenada posicion,char nombre):Vampiro(posicion,nombre)
{
}
void Nosferatu::mostrar(){
    cout<<"Objeto: Nosferatu"<<endl;
}
Nosferatu::~Nosferatu()
{
}
