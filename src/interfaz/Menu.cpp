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

bool Menu::mostrar_fichero(string name){
    
    string fichero = "src/interfaz/"+name+".txt";

    string mostrar = obtener_texto(fichero);
    
    if(mostrar.length()>0){

        mostrar.replace(mostrar.find("\\"),1,"\\\\");

        cout<<mostrar;

        return true;
    }
    else
        return false;
}

void Menu::mostrar_menu(){

    char respuesta=0;
    
    while(respuesta!=opciones[SALIR]){
        
        limpiar_pantalla();
        
        if(!mostrar_fichero("menu_principal")){
            
            limpiar_pantalla();
            
            cout<<"\t\tMENU PRINCIPAL\n\ta)Mostrar Resumen\n\tb)Mostrar Tablero\n\tc)Buscar elemento\n\td)Agregar Elemento\n\te)Eliminar Elemento\n\tMostrar Elemento\n\tq)Salir\nIngrese una letra";
    
        }
            
        respuesta=caracter_mayuscula((char)getchar());
        
        if      (respuesta == opciones[RESUMEN])    menu_resumen();
        else if (respuesta == opciones[TABLERO])    menu_tablero();
        else if (respuesta == opciones[BUSQUEDA])   menu_buscar_objeto();
        else if (respuesta == opciones[AGREGAR])    menu_agregar_elemento();
        else if (respuesta == opciones[ELIMINAR])   menu_eliminar_elemento();
        else if (respuesta == opciones[MOSTRAR])    menu_mostrar_elemento();
        else if (respuesta != opciones[SALIR])      menu_letra_incorrecta();
    }
}

void Menu::menu_tablero(){
    
    limpiar_pantalla();

    if(!mostrar_fichero("tablero")){
        
        limpiar_pantalla();
        cout<<"\t\t\tTABLERO";
    }
    
    Tablero *tablero = datos->obtener_tablero();
    
    if(tablero!=nullptr) 
        tablero->mostrar_tablero();
    
    cin.ignore();
    cin.get();
}

void Menu::menu_resumen(){
    
    limpiar_pantalla();

    if(!mostrar_fichero("resumen")){

        limpiar_pantalla();
        cout<<"\t\t\tRESUMEN";
    }
    
    datos->mostrar_resumen();
    
    cin.ignore();
    cin.get();
}

void Menu::menu_letra_incorrecta(){
    limpiar_pantalla();
    
    if(!mostrar_fichero("letra_incorrecta")){
        
        limpiar_pantalla();

        cout<<"Ingrese una letra correcta";
    }

    cin.get();
}

char Menu::pedir_objeto(){

    string respuesta="";
    bool bandera=false;
    while(respuesta!=opciones[SALIR]+"" && !bandera){
        
        limpiar_pantalla();

        if(!mostrar_fichero("elegir_objeto")){

            limpiar_pantalla();

            cout<<"ELEGIR OBJETO";
        }
        cout<<"\nIngrese el numero del objeto que desea:\n";
        cout<<"\t01) Agua \n";
        cout<<"\t02) Bala \n";
        cout<<"\t03) Cruz \n";
        cout<<"\t04) Estaca \n";
        cout<<"\t05) Escopeta \n";
        cout<<"\t06) Humano \n";
        cout<<"\t07) Humano Cazador \n";
        cout<<"\t08) Humano Vanesa \n";
        cout<<"\t09) Vampiro \n";
        cout<<"\t10) Vampiro Vampirella \n";
        cout<<"\t11) Vampiro Nosferatu \n";
        cout<<"\t12) Zombi \n\n";
        cout<<"\tq) Regresar";
        cin.ignore();
        cin>>respuesta;
        bandera = respuesta!=opciones[SALIR]+"" && convertir_entero(respuesta) > 0 && convertir_entero(respuesta) < 13;

        if(!bandera)
            menu_letra_incorrecta();
    }
    if(respuesta==opciones[SALIR]+"")
        return opciones[SALIR];

    else
        return NOMBRES[convertir_entero(respuesta)-1];
}

char Menu::pedir_cuadrante(){
    
    char respuesta=0;
    bool bandera=false;
    while(respuesta!=opciones[SALIR] && !bandera){

        limpiar_pantalla();
        if(!mostrar_fichero("elegir_cuadrante")){

            limpiar_pantalla();

            cout<<"ELEGIR CUADRANTE";
        }

        cout<<"\nIngrese el numero del cuadrante que desea:\n";
        cout<<"\t1) NO : Norte Oeste \n";
        cout<<"\t2) NE : Norte Este \n";
        cout<<"\t3) SO : Sur Oeste \n";
        cout<<"\t4) SE : Sur Este \n\n";
        cout<<"\tq) Regresar: ";
        cin.ignore();
        respuesta = (char)getchar();
        bandera = respuesta!=opciones[SALIR] && (int)respuesta > (int)'0' && (int)respuesta < (int)'5';
        
        if(!bandera)
            menu_letra_incorrecta();
    }
    if(respuesta==opciones[SALIR])
        return opciones[SALIR];

    else
        return (char)((int)respuesta-(int)'1');
}

Objeto* Menu::buscar_objeto(int cuadrante, char nombre){
    
    return this->datos->obtener_tablero()->obtener_objeto(CARDINALES[cuadrante],nombre);

}

void Menu::menu_buscar_objeto(){
    
    limpiar_pantalla();
    
    if(!mostrar_fichero("busqueda_cuadrante")){

        limpiar_pantalla();
        cout<<"Busqueda Cuadrante\n";
    }
    char cuadrante=0;
	char nombre=opciones[SALIR];
    Objeto *objeto=nullptr;

    while(nombre==opciones[SALIR]){

        cuadrante = pedir_cuadrante();

        if(cuadrante != opciones[SALIR]){
            
            nombre = pedir_objeto();

            if(nombre != opciones[SALIR]){

                objeto = buscar_objeto( (int)cuadrante , nombre);

                if(objeto!=nullptr){

                    int indice_nombre = buscar_dato(NOMBRES,MAX_OBJETOS,objeto->obtener_nombre());
                    cout<<"Se encontro el Objeto"<<ELEMENTOS[indice_nombre];
                    cout<<" en la posicion: ( "<<objeto->obtener_posicion().obtener_x()<<" - "<<objeto->obtener_posicion().obtener_y()<<" )"<<endl;
                    
                }
            }

        }
        else
            nombre=0;
    }
}
void Menu::menu_agregar_elemento(){

}
void Menu::menu_eliminar_elemento(){

}
void Menu::menu_mostrar_elemento(){

}