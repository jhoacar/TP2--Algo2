#include "funcionalidades/Datos.h"
#include "objetos/elementos/Estaca.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    
    string archivo = "estado.txt";
    
    if(argc>1)
        archivo = argv[1];
    
    Datos datos(archivo);

    cout<<"Datos cargados"<<endl;
}