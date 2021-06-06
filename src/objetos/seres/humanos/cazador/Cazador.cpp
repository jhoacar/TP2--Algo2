#include "Cazador.h"
#include <iostream>
using std::cout;
using std::endl;
Cazador::Cazador():Humano(){

}
Cazador::Cazador(Coordenada posicion,char nombre):Humano(posicion,nombre){
}
void Cazador::mostrar(){
    cout<<"Objeto: Cazador"<<endl;
}
Cazador::~Cazador()
{
}