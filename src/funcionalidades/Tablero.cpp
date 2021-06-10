#include "Tablero.h"
#include <iostream>
#include "Funciones.h"

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

    for(int i=0; i < filas; i++)
        objetos[i] = new Objeto*[columnas];


    for(int i=0; i < filas ;i++){

        for(int j=0; j < columnas ;j++)
            objetos[i][j]=nullptr;
    }

}

Tablero::~Tablero()
{
    for(int i=0; i < filas ; i++){

        for(int j=0; j < columnas ; j++){

            if(objetos[i][j] != nullptr){

                delete objetos[i][j];

                objetos[i][j]=nullptr;

            }
        }
    }

    for(int i=0 ; i < filas ;i++){
    
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
    
        return CARDINALES[NO];
    
    else if(posicion.obtener_x()>columnas/2 && posicion.obtener_y()>filas/2)
    
        return CARDINALES[SE];
    
    else if(posicion.obtener_x()>=columnas/2 && posicion.obtener_y()<=filas/2)
    
        return CARDINALES[NE];
    
    else
    
        return CARDINALES[SO];
}

bool Tablero::posicion_valida(Coordenada posicion){

    Coordenada limite( columnas , filas );

    return posicion<limite;

}
void Tablero::cargar_objeto(Objeto *objeto){
    
    if(objeto!=nullptr){

        Coordenada posicion = objeto->obtener_posicion();

        posicion-=1; //Le resto una posicion para guardarla correctamente en el tablero arrancando en (0,0)

        if(posicion_valida(posicion)){

            objeto->asignar_cuadrante( obtener_cuadrante ( posicion ) );
    
            objetos[ posicion.obtener_y() ][ posicion.obtener_x() ] = objeto;
    
        }

    }    
}

int Tablero::obtener_filas(){
    
    return this->filas;

}
int Tablero::obtener_columnas(){

    return this->columnas;

}

bool Tablero::eliminar_objeto(Coordenada posicion){

    if(posicion_valida(posicion)){
        
        if(objetos[posicion.obtener_y()][posicion.obtener_x()]!=nullptr){
            
            delete objetos[posicion.obtener_y()][posicion.obtener_x()];
            
            objetos[posicion.obtener_y()][posicion.obtener_x()]=nullptr;
            
            return true;
        }
    }
    return false;
}

void Tablero::mostrar_tablero(){

	for(int i=0; i < filas ; i++){

        if(i==0){
            cout<<"    ";
            for(int j=0; j < columnas; j++){
                
                if(j % (columnas/2) == 0 ){
                    cout<<" | ";
                }
                cout<<" "<<(j+1)<<" ";
            }

            cout<<endl;
        }


        if(i % (filas/2) == 0 ){

            for(int j=0; j < columnas + 3 ; j++)
                cout<<" _ ";

            cout<<endl;
        }
		
        for(int j=-1; j < columnas ; j++){

            if(j==-1)
                cout<<" "<< (i < 9? " "+to_string(i+1) : to_string(i+1) )<<" ";
            else{
                
                if(j % (columnas/2) == 0 ){
                    cout<<" | ";
                }    

                if(objetos[i][j]!=nullptr){
                    cout<<" "<<objetos[i][j]->obtener_nombre()<<" ";
                }
                else{
                    cout<<" * ";
                }
            }
        }    

        cout<<" | "<<endl;
	}

    for(int j=0; j < columnas + 3 ; j++)
        
        cout<<" - ";

    cout<<endl;

}