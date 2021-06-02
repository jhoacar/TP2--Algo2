#include "Tablero.h"

Tablero::Tablero(){
    this->filas=0;
    this->columnas=0;
    objetos=nullptr;
}
Tablero::Tablero(int filas,int columnas)
{
    this->filas=filas;
    this->columnas=columnas;
    objetos = new Lista<Objeto *>[filas];
    for(int i=0;i<filas;i++)
        objetos[i] = Lista<Objeto *>(columnas);
}

Tablero::~Tablero()
{
    delete [] objetos;
}
bool Tablero::posicion_valida(Coordenada posicion){
    Coordenada limite(filas,columnas);
    return posicion<limite;
}
void Tablero::cargar(Objeto *objeto){
    Coordenada posicion = objeto->obtener_posicion();
    if(posicion_valida(posicion))
        objetos[posicion.obtener_x()][posicion.obtener_y()]=objeto;
    
}



