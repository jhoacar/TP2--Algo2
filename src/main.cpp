#include "interfaz/Menu.h"
#include <iostream>
int main(int argc, char *argv[]){
    
    string archivo = "estado.txt";
    
    if(argc>1)
        archivo = argv[1];
    Menu menu(archivo);
    menu.mostrar_menu();
    std::cin.ignore();
    return 0;
}