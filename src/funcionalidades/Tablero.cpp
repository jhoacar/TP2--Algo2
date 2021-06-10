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

    posicion-=1; //Le resto una posicion para eliminarlo correctamente en el tablero arrancando en (0,0)

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
                    color(ROJO);
                    cout<<" | ";
                    color(RESET);
                }
                color(CYAN);
                cout<<" "<<(j+1)<<" ";
                color(RESET);
            }

            cout<<endl;
        }


        if(i % (filas/2) == 0 ){

            for(int j=0; j < columnas + 3 ; j++){
                
                color(ROJO);
                cout<<" _ ";
                color(RESET);
            }

            cout<<endl;
        }
		
        for(int j=-1; j < columnas ; j++){

            if(j==-1){
                color(CYAN);
                cout<<" "<< (i < 9? " "+to_string(i+1) : to_string(i+1) )<<" ";
                color(RESET);
            }
            else{
                
                if(j % (columnas/2) == 0 ){
                    color(ROJO);
                    cout<<" | ";
                    color(RESET);
                }    

                if(objetos[i][j]!=nullptr){
                    
                    color(AMARILLO);
                    cout<<" "<<objetos[i][j]->obtener_nombre()<<" ";
                    color(RESET);
                    
                }
                else{
                    cout<<" * ";
                }
            }
        }    
        color(ROJO);
        cout<<" | "<<endl;
        color(RESET);
	}

    for(int j=0; j < columnas + 3 ; j++){

        color(ROJO);
        cout<<" - ";
        color(RESET);
    }
    cout<<endl;

    mostrar_leyenda();
}


void Tablero::mostrar_leyenda(){

    cout<<"\n\tCONVENCION USADA: "<<endl;
    cout<<"\n-*: vacio";
    cout<<"\n- h: humano simple";
    cout<<"\n- H: humano caza vampiros-zombis";
    cout<<"\n- W: Vanesa";
    cout<<"\n- z: zombi";
    cout<<"\n- v: vampiro";
    cout<<"\n- V: Vampirella"; 
    cout<<"\n- N: Nosferatu ";
    cout<<"\n- c: cruz ";
    cout<<"\n- a: agua bendita ";
    cout<<"\n- e: estaca ";
    cout<<"\n- E: escopeta ";
    cout<<"\n- b: balas"<<endl;
}