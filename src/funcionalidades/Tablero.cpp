#include "Tablero.h"
#include <iostream>
using namespace std;

Tablero::Tablero(){
    this->filas=0;
    this->columnas=0;
    objetos=nullptr;
}
Tablero::Tablero(int filas,int columnas)
{
    this->filas=filas;
    this->columnas=columnas;
    objetos = new Objeto**[filas];
    for(int i=0;i<filas;i++)
        objetos[i] = new Objeto*[columnas];
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++)
            objetos[i][j]=nullptr;
    }
}

Tablero::~Tablero()
{
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(objetos[i][j]!=nullptr){
                delete objetos[i][j];
                objetos[i][j]=nullptr;
            }
        }
    }
    for(int i=0;i<filas;i++){
        delete[] objetos[i];
        objetos[i]=nullptr;
    }
    delete [] objetos;
    objetos=nullptr;
}
bool Tablero::posicion_valida(Coordenada posicion){
    Coordenada limite(filas,columnas);
    return posicion<limite;
}
void Tablero::cargar(Objeto *objeto){
    Coordenada posicion = objeto->obtener_posicion();
    if(posicion_valida(posicion)){
        cout<<"Posicion Valida"<<endl;
        //objetos[posicion.obtener_x()][posicion.obtener_y()]=objeto;
    }
}