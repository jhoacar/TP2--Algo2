#include "Vampirella.h"
#include <iostream>
using std::cout;
using std::endl;
Vampirella::Vampirella():Vampiro(){

}
Vampirella::Vampirella(Coordenada posicion,char nombre):Vampiro(posicion,nombre)
{
}
void Vampirella::mostrar(){
    cout<<"Objeto: Vampirella"<<endl;
}
Vampirella::~Vampirella()
{
}
