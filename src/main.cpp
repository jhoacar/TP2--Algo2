#include "interfaz/Menu.h"
#include "funcionalidades/Funciones.h"
#include <iostream>
int main(int argc, char *argv[]){
    
    string archivo = "estado.txt";
    
    if(argc>1)
        archivo = argv[1];

    Menu menu(archivo);
    
    if(!menu.mostrar_menu())
        std::cout<<"\nNo se pudieron cargar los datos"<<std::endl;
    
    pausa();
    return 0;
}