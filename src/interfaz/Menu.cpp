#include "Menu.h"
#include "../funcionalidades/Funciones.h"
#include <iostream>
using namespace std;

const char opciones[8] = "ABCDEFQ";
enum {RESUMEN=0,TABLERO,BUSQUEDA,AGREGAR,ELIMINAR,MOSTRAR,SALIR};

Menu::Menu(string nombre)
{
    datos = new Datos(nombre);
}

Menu::~Menu()
{
    delete datos;
}
void Menu::mostrar_menu(){

    string menu=obtener_texto("src\\interfaz\\menu_principal.txt");
    if(menu.length()>0)
        menu.replace(menu.find("\\"),1,"\\\\");
    else
        menu="\t\tMENU PRINCIPAL\n\ta)Mostrar Resumen\n\tb)Mostrar Tablero\n\tc)Buscar elemento\n\td)Agregar Elemento\n\te)Eliminar Elemento\n\tMostrar Elemento\n\tq)Salir\nIngrese una letra";
    char respuesta=0;
    
    while(respuesta!=opciones[SALIR]){
        limpiar_pantalla();
        cout<<menu;

        respuesta=caracter_mayuscula((char)getchar());
        
        if      (respuesta == opciones[RESUMEN])    menu_resumen();
        else if (respuesta == opciones[TABLERO])    menu_tablero();
        else if (respuesta == opciones[BUSQUEDA])   menu_buscar_elemento();
        else if (respuesta == opciones[AGREGAR])    menu_agregar_elemento();
        else if (respuesta == opciones[ELIMINAR])   menu_eliminar_elemento();
        else if (respuesta == opciones[MOSTRAR])    menu_mostrar_elemento();
        else if (respuesta != opciones[SALIR])      menu_letra_incorrecta();
    }
}

void Menu::menu_tablero(){
    limpiar_pantalla();
    string menu=obtener_texto("src\\interfaz\\tablero.txt");
    if(menu.length()>0)
        menu.replace(menu.find("\\"),1,"\\\\");
    else
        menu="\t\t\tTABLERO";
    cout<<menu;
    datos->mostrar_tablero();
    cin.ignore();
    cin.get();

}

void Menu::menu_resumen(){
    limpiar_pantalla();
    string menu=obtener_texto("src\\interfaz\\resumen.txt");
    if(menu.length()>0)
        menu.replace(menu.find("\\"),1,"\\\\");
    else
        menu="\t\t\tRESUMEN";
    cout<<menu;
    datos->mostrar_resumen();
    cin.ignore();
    cin.get();
}

void Menu::menu_letra_incorrecta(){
    limpiar_pantalla();
    string menu=obtener_texto("src\\interfaz\\letra_incorrecta.txt");
    if(menu.length()>0)
        menu.replace(menu.find("\\"),1,"\\\\");
    else
        menu="Ingrese una letra correcta";
    cout<<menu;
    cin.ignore();
    cin.get();
}

void Menu::menu_buscar_elemento(){

}
void Menu::menu_agregar_elemento(){

}
void Menu::menu_eliminar_elemento(){

}
void Menu::menu_mostrar_elemento(){

}