#include "Tablero.h"
#include <iostream>
using namespace std;

const string CARDINALES[4] = {"NO","SO","NE","SE"};
enum {NO=0,SO,NE,SE};

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
string Tablero::obtener_cuadrante(Coordenada posicion){
    if(!posicion_valida(posicion))
        return "";
    else if(posicion.obtener_x()<columnas/2 && posicion.obtener_y()<filas/2)
        return CARDINALES[NE];
    else if(posicion.obtener_x()>columnas/2 && posicion.obtener_y()<filas/2)
        return CARDINALES[NO];
    else if(posicion.obtener_x()<columnas/2 && posicion.obtener_y()>filas/2)
        return CARDINALES[SE];
    else
        return CARDINALES[SO];
}

bool Tablero::posicion_valida(Coordenada posicion){
    Coordenada limite(filas,columnas);
    return posicion<limite;
}
void Tablero::cargar_objeto(Objeto *objeto){
    Coordenada posicion = objeto->obtener_posicion();
    if(posicion_valida(posicion)){
        objeto->asignar_cuadrante(obtener_cuadrante(objeto->obtener_posicion()));
        objetos[posicion.obtener_x()][posicion.obtener_y()]=objeto;
    }    
}
bool Tablero::existe_objeto(Coordenada posicion){
    return posicion_valida(posicion) && objetos[posicion.obtener_x()][posicion.obtener_y()]!=nullptr;
}
int Tablero::obtener_filas(){
    return this->filas;
}
int Tablero::obtener_columnas(){
    return this->columnas;
}

Objeto *Tablero::obtener_objeto(Coordenada posicion){
    Objeto *objeto = nullptr; 
    if(posicion_valida(posicion))
        objeto = objetos[posicion.obtener_x()][posicion.obtener_y()];
    return objeto;
}
void Tablero::mostrar_tablero(){

	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(objetos[i][j]!=nullptr)
				cout<<" "<<objetos[i][j]->obtener_nombre()<<" ";
			else
				cout<<" * ";
		}
		cout<<endl;
	}
}