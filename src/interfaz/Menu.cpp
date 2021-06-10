#include "Menu.h"
#include "../funcionalidades/Funciones.h"
#include <iostream>

using namespace std;

const char opciones[8] = "ABCDEFQ";

const Coordenada POSICION_FALSA = {-1,-1};

const int MAX_CANTIDAD_ELEMENTO = 10000;

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

    string respuesta=" ";
    
    while(respuesta[0]!=opciones[SALIR]){
        
        limpiar_pantalla();
        
        if(!mostrar_fichero("menu_principal")){
            
            limpiar_pantalla();
            
            cout<<"\t\tMENU PRINCIPAL\n\ta)Mostrar Resumen\n\tb)Mostrar Tablero\n\tc)Buscar elemento\n\td)Agregar Elemento\n\te)Eliminar Elemento\n\tMostrar Elemento\n\tq)Salir\nIngrese una letra";
    
        }
        getline(cin,respuesta,'\n');
        respuesta = cadena_mayuscula(respuesta);

        if      (respuesta[0] == opciones[RESUMEN])    menu_resumen();
        else if (respuesta[0] == opciones[TABLERO])    menu_tablero();
        else if (respuesta[0] == opciones[BUSQUEDA])   menu_buscar_objeto();
        else if (respuesta[0] == opciones[AGREGAR])    menu_agregar_objeto();
        else if (respuesta[0] == opciones[ELIMINAR])   menu_eliminar_objeto();
        else if (respuesta[0] == opciones[MOSTRAR])    menu_mostrar_objeto();
        else if (respuesta[0] != opciones[SALIR])      menu_letra_incorrecta();
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
    
    pausa();
}

void Menu::menu_resumen(){
    
    limpiar_pantalla();

    if(!mostrar_fichero("resumen")){

        limpiar_pantalla();
        cout<<"\t\t\tRESUMEN";
    }
    
    datos->mostrar_resumen();
    
    pausa();
}

void Menu::menu_letra_incorrecta(){
    
    limpiar_pantalla();
    
    if(!mostrar_fichero("letra_incorrecta")){
        
        limpiar_pantalla();

        cout<<"Ingrese una letra correcta";
    }
    pausa();
}

char Menu::pedir_objeto(){

    string menu_opciones;
    string menu_error;

    menu_opciones = "\nIngrese el numero del objeto que desea:\n";
    menu_opciones +="\t01) Agua \n";
    menu_opciones +="\t02) Bala \n";
    menu_opciones +="\t03) Cruz \n";
    menu_opciones +="\t04) Estaca \n";
    menu_opciones +="\t05) Escopeta \n";
    menu_opciones +="\t06) Humano \n";
    menu_opciones +="\t07) Humano Cazador \n";
    menu_opciones +="\t08) Humano Vanesa \n";
    menu_opciones +="\t09) Vampiro \n";
    menu_opciones +="\t10) Vampiro Vampirella \n";
    menu_opciones +="\t11) Vampiro Nosferatu \n";
    menu_opciones +="\t12) Zombi \n\n";
    menu_opciones +="\tq) Regresar: ";
    menu_error = "\n\tIngrese un numero comprendido entre 1 y 12, o 'q' para salir";

    int opcion = pedir_dato(menu_opciones,menu_error,1,12,opciones[SALIR]);

    if(opcion==NO_ENCONTRADO)
        return opciones[SALIR];
    else
        return NOMBRES[opcion-1];
}

Coordenada Menu::pedir_posicion(){

    int fila = this->datos->obtener_tablero()->obtener_filas();
    int columna = this->datos->obtener_tablero()->obtener_columnas();

    int numero_fila=0;
    int numero_columna=0;

    string menu_opciones;
    string menu_error;

    menu_opciones  ="\nIngrese un numero comprendido entre 1 y "+to_string(fila);
    menu_opciones +="\n(Numero de la fila donde desea posicionarlo o 'q' para salir) : ";
    menu_error     ="\nDebe ingresar un numero comprendido entre 1 y "+to_string(fila);
    menu_error    +="\n(Numero de la fila donde desea posicionarlo o'q' para salir)";
    
    numero_fila= pedir_dato(menu_opciones,menu_error,1,fila,opciones[SALIR]);

    if(numero_fila!=NO_ENCONTRADO){

        menu_opciones ="\nIngrese un numero comprendido entre 1 y "+to_string(columna);
        menu_opciones+="\n(Numero de la columna donde desea posicionarlo o 'q' para salir) : ";
        menu_error   ="\nDebe ingresar un numero comprendido entre 1 y "+to_string(columna);
        menu_error  +="\n(Numero de la columna donde desea posicionarlo o 'q' para salir)";

        numero_columna = pedir_dato(menu_opciones,menu_error,1,columna,opciones[SALIR]);
    }

    if(numero_fila==NO_ENCONTRADO||numero_columna==NO_ENCONTRADO)
        return POSICION_FALSA;
    else{
        Coordenada posicion(numero_columna,numero_fila);
        return posicion;
    }
    
}

char Menu::pedir_cuadrante(){
    
    string menu_opciones;
    string menu_error;

    menu_opciones = "\nIngrese el numero del cuadrante que desea:\n";
    menu_opciones +="\t1) NO : Norte Oeste \n";
    menu_opciones +="\t2) SO : Sur Oeste \n";
    menu_opciones +="\t3) NE : Norte Este \n";
    menu_opciones +="\t4) SE : Sur Este \n\n";
    menu_opciones +="\tq) Regresar: ";
    menu_error = "\n\tIngrese un numero comprendido entre 1 y 4, o 'q' para salir";

    int opcion = pedir_dato(menu_opciones,menu_error,1,4,opciones[SALIR]);

    if(opcion==NO_ENCONTRADO)
        return opciones[SALIR];
    else
        return (char)opcion;
    
}

void Menu::menu_buscar_objeto(){

    char cuadrante=0;
	char nombre=opciones[SALIR];
    Objeto *objeto=nullptr;
    int indice_nombre;

    while(nombre==opciones[SALIR]){

        cuadrante = pedir_cuadrante();

        if(cuadrante != opciones[SALIR]){
            
            nombre = pedir_objeto();

            if(nombre != opciones[SALIR]){

                objeto = datos->buscar_objeto( CARDINALES[(int)cuadrante-1] , nombre);
                
                indice_nombre = buscar_dato(NOMBRES,MAX_OBJETOS,nombre);
                    
                if(objeto!=nullptr){

                    cout<<"Se encontro el objeto de Nombre: "<<OBJETOS[indice_nombre];
                    cout<<" en la posicion: ( "<<objeto->obtener_posicion().obtener_x()+1<<" , "<<objeto->obtener_posicion().obtener_y()+1<<" )"<<endl;

                }
                else
                    cout<<"No se encontro el objeto de Nombre: "<<OBJETOS[indice_nombre]<<" en el Cuadrante: "<<CARDINALES[cuadrante]<<endl;

                pausa();
            }

        }
        else
            nombre=0;
    }
}


void Menu::menu_agregar_objeto(){
    
    char nombre;    
    int cantidad=1;
    Coordenada posicion;
    Objeto *objeto=nullptr;
    int indice_nombre;

    nombre = pedir_objeto();

    if(nombre!=opciones[SALIR]){
        
        if(nombre == NOMBRES[AGUA] || nombre == NOMBRES[BALA])
            cantidad = pedir_dato("\nIngrese la cantidad (mayor a 0): ","\nIngrese una cantidad mayor a 0 ",1,MAX_CANTIDAD_ELEMENTO,opciones[SALIR]);

        posicion = pedir_posicion();

        if(posicion!=POSICION_FALSA){

            objeto = datos->buscar_objeto(posicion);
                    
            if(objeto!=nullptr){

                indice_nombre = buscar_dato(NOMBRES,MAX_OBJETOS,objeto->obtener_nombre());
            
                cout<<"Se encontro el objeto de Nombre: "<<OBJETOS[indice_nombre];
                cout<<" en la posicion: ( "<<objeto->obtener_posicion().obtener_x()<<" , "<<objeto->obtener_posicion().obtener_y()<<" )"<<endl;
                cout<<"No se pudo agregar el objeto. "<<endl;
            }
            else{
                
                indice_nombre = buscar_dato(NOMBRES,MAX_OBJETOS,nombre);
            
                objeto = datos->crear_objeto(indice_nombre,nombre,posicion,cantidad);

                datos->obtener_tablero()->cargar_objeto(objeto);

                cout<<"Se agrego el objeto de Nombre: "<<OBJETOS[indice_nombre];
                cout<<" en la posicion: ( "<<posicion.obtener_x()+1<<" , "<<posicion.obtener_y()+1<<" )"<<endl;
            }

            pausa();
        }
    }                

}
void Menu::menu_eliminar_objeto(){

    Coordenada posicion;
    bool eliminado=false;
    
    posicion = pedir_posicion();

    if(posicion!=POSICION_FALSA){

        eliminado = datos->obtener_tablero()->eliminar_objeto(posicion);

        if(eliminado)
            cout<<"\n\tSe ha eliminado el objeto satisfactoriamente"<<endl;
        else   
            cout<<"\n\tNo se ha encontrado algun objeto en la posicion"<<endl;
    }
    pausa();
}

void Menu::menu_mostrar_objeto(){

    Coordenada posicion;
    Objeto *objeto;
    
    posicion = pedir_posicion();

    if(posicion!=POSICION_FALSA){

        objeto = datos->buscar_objeto(posicion);

        if(objeto!=nullptr)
            objeto->mostrar();
        else   
            cout<<"\n\tNo se ha encontrado algun objeto en la posicion"<<endl;
    }   
    pausa();
}