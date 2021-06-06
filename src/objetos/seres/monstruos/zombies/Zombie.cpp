#include "Zombie.h"
#include <iostream>
using std::cout;
using std::endl;
Zombie::Zombie():Monstruo(){
    
}
Zombie::Zombie(Coordenada posicion,char nombre):Monstruo(posicion,nombre)
{
}
void Zombie::mostrar(){
    cout<<"Objeto: Zombie"<<endl;
}
Zombie::~Zombie()
{
}
