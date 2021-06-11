#include "Menu.h"
#include "../funcionalidades/Funciones.h"
#include <iostream>

using namespace std;

const char OPCIONES_MENU[8] = "ABCDEFQ";

const Coordenada POSICION_FALSA = {-1,-1};

const int MAX_CANTIDAD_ELEMENTO = 10000;

enum {RESUMEN=0,TABLERO,BUSQUEDA,AGREGAR,ELIMINAR,MOSTRAR,SALIR};

Menu::Menu(string nombre_archivo)
{
    datos = new Datos(nombre_archivo);
    
}

Menu::~Menu()
{
    delete datos;
}


bool Menu::mostrar_menu(){

    if(datos->obtener_tablero()==nullptr)
        return false;

    string respuesta=" ";
    
    while(respuesta[0]!=OPCIONES_MENU[SALIR]){
        
        color(CYAN);

        limpiar_pantalla();

        color(CYAN);

       if(!mostrar_fichero("menu_principal")){
            
            limpiar_pantalla();
            
            cout<<"\t\tMENU PRINCIPAL\n\ta)Mostrar Resumen\n\tb)Mostrar Tablero\n\tc)Buscar elemento\n\td)Agregar Elemento\n\te)Eliminar Elemento\n\tMostrar Elemento\n\tq)Salir\nIngrese una letra";
    
        }
        getline(cin,respuesta,'\n');
        respuesta = cadena_mayuscula(respuesta);

        if      (respuesta[0] == OPCIONES_MENU[RESUMEN])    menu_resumen();
        else if (respuesta[0] == OPCIONES_MENU[TABLERO])    menu_tablero();
        else if (respuesta[0] == OPCIONES_MENU[BUSQUEDA])   menu_buscar_objeto();
        else if (respuesta[0] == OPCIONES_MENU[AGREGAR])    menu_agregar_objeto();
        else if (respuesta[0] == OPCIONES_MENU[ELIMINAR])   menu_eliminar_objeto();
        else if (respuesta[0] == OPCIONES_MENU[MOSTRAR])    menu_mostrar_objeto();
        else if (respuesta[0] != OPCIONES_MENU[SALIR])      menu_letra_incorrecta();
    }

    return true;
}

void Menu::menu_tablero(){
    
    color(CYAN);
    limpiar_pantalla();

    if(!mostrar_fichero("tablero")){
        
        limpiar_pantalla();
        cout<<"\t\t\tTABLERO";
    }
    color(RESET);
    
    Tablero *tablero = datos->obtener_tablero();
    
    if(tablero!=nullptr) 
        tablero->mostrar_tablero();
    
    pausa();
}

void Menu::menu_resumen(){
    
    color(CYAN);
    limpiar_pantalla();

    if(!mostrar_fichero("resumen")){

        limpiar_pantalla();
        cout<<"\t\t\tRESUMEN";
    }
    color(RESET);
    cout<<datos->obtener_resumen();
    pausa();

	int respuesta = pedir_dato("\n\n\tDesea visualizar los datos completos de los objetos?\n(1) SI\n(ENTER) NO ","\n\n\tIngrese 1 (SI) o ENTER (NO)\n",1,1,0);
	if(respuesta == 1)
		cout<<datos->obtener_datos();

    pausa();
}

void Menu::menu_letra_incorrecta(){
    
    color(CYAN);

    limpiar_pantalla();
    
    if(!mostrar_fichero("letra_incorrecta")){
        
        limpiar_pantalla();

        cout<<"Ingrese una letra correcta";
    }
    color(RESET);
    pausa();
}

char Menu::pedir_objeto(){

    string menu_OPCIONES_MENU;
    string menu_error;

    menu_OPCIONES_MENU = "\nIngrese el numero del objeto que desea:\n";
    menu_OPCIONES_MENU +="\t01) Agua \n";
    menu_OPCIONES_MENU +="\t02) Bala \n";
    menu_OPCIONES_MENU +="\t03) Cruz \n";
    menu_OPCIONES_MENU +="\t04) Estaca \n";
    menu_OPCIONES_MENU +="\t05) Escopeta \n";
    menu_OPCIONES_MENU +="\t06) Humano \n";
    menu_OPCIONES_MENU +="\t07) Humano Cazador \n";
    menu_OPCIONES_MENU +="\t08) Humano Vanesa \n";
    menu_OPCIONES_MENU +="\t09) Vampiro \n";
    menu_OPCIONES_MENU +="\t10) Vampiro Vampirella \n";
    menu_OPCIONES_MENU +="\t11) Vampiro Nosferatu \n";
    menu_OPCIONES_MENU +="\t12) Zombi \n\n";
    menu_OPCIONES_MENU +="\tq) Regresar: ";
    menu_error = "\n\n\tIngrese un numero comprendido entre 1 y 12, o 'q' para salir";

    int opcion = pedir_dato(menu_OPCIONES_MENU , menu_error , 1 , 12 , OPCIONES_MENU[SALIR]);

    if(opcion==NO_ENCONTRADO)
        return OPCIONES_MENU[SALIR];
    else
        return NOMBRES_CHAR[opcion-1];
}

Coordenada Menu::pedir_posicion(){

    int fila = this->datos->obtener_tablero()->obtener_filas();
    int columna = this->datos->obtener_tablero()->obtener_columnas();

    int numero_fila=0;
    int numero_columna=0;

    string menu_OPCIONES_MENU;
    string menu_error;

    menu_OPCIONES_MENU  ="\n\n\tIngrese un numero comprendido entre 1 y "+to_string(fila);
    menu_OPCIONES_MENU +="\n\n\t(Numero de la fila donde desea posicionarlo o 'q' para salir) : ";
    menu_error     ="\n\n\tDebe ingresar un numero comprendido entre 1 y "+to_string(fila)+" o'q' para salir";
    
    numero_fila= pedir_dato(menu_OPCIONES_MENU,menu_error,1,fila,OPCIONES_MENU[SALIR]);

    if(numero_fila!=NO_ENCONTRADO){

        menu_OPCIONES_MENU ="\n\n\tIngrese un numero comprendido entre 1 y "+to_string(columna);
        menu_OPCIONES_MENU+="\n\n\t(Numero de la columna donde desea posicionarlo o 'q' para salir) : ";
        menu_error   ="\n\n\tDebe ingresar un numero comprendido entre 1 y "+to_string(columna)+" o 'q' para salir)";

        numero_columna = pedir_dato(menu_OPCIONES_MENU,menu_error,1,columna,OPCIONES_MENU[SALIR]);
    }

    if(numero_fila==NO_ENCONTRADO||numero_columna==NO_ENCONTRADO)
        return POSICION_FALSA;
    else{
        Coordenada posicion(numero_columna,numero_fila);
        return posicion;
    }
    
}

char Menu::pedir_cuadrante(){
    
    string menu_OPCIONES_MENU;
    string menu_error;

    menu_OPCIONES_MENU = "\nIngrese el numero del cuadrante que desea:\n";
    menu_OPCIONES_MENU +="\t1) NO : Norte Oeste \n";
    menu_OPCIONES_MENU +="\t2) SO : Sur Oeste \n";
    menu_OPCIONES_MENU +="\t3) NE : Norte Este \n";
    menu_OPCIONES_MENU +="\t4) SE : Sur Este \n\n";
    menu_OPCIONES_MENU +="\tq) Regresar: ";
    menu_error = "\n\n\tIngrese un numero comprendido entre 1 y 4, o 'q' para salir";

    int opcion = pedir_dato(menu_OPCIONES_MENU,menu_error,1,4,OPCIONES_MENU[SALIR]);

    if(opcion==NO_ENCONTRADO)
        return OPCIONES_MENU[SALIR];
    else
        return (char)opcion;
    
}

void Menu::menu_buscar_objeto(){

    char cuadrante=0;
	char nombre=OPCIONES_MENU[SALIR];
    Objeto *objeto=nullptr;
    int indice_nombre;

    while(nombre==OPCIONES_MENU[SALIR]){

        cuadrante = pedir_cuadrante();

        if(cuadrante != OPCIONES_MENU[SALIR]){
            
            nombre = pedir_objeto();

            if(nombre != OPCIONES_MENU[SALIR]){

                objeto = datos->obtener_objeto( datos->buscar_objeto( CARDINALES[(int)cuadrante-1] , nombre)) ;
                
                indice_nombre = buscar_dato(NOMBRES_CHAR,MAX_NOMBRES,nombre);
                    
                if(objeto!=nullptr){

                    cout<<"\n\n\tSe encontro el objeto de Nombre: ";
                    cout<<NOMBRES_STRING[indice_nombre];
                    cout<<" en la posicion: ( ";
                    cout<<objeto->obtener_posicion().obtener_x()+1;
                    cout<<" , ";
                    cout<<objeto->obtener_posicion().obtener_y()+1;
                    cout<<" )"<<endl;

                }
                else{
                    cout<<"\n\n\tNo se encontro el objeto de Nombre: ";
                    cout<<NOMBRES_STRING[indice_nombre];
                    cout<<" en el Cuadrante: ";
                    cout<<CARDINALES[(int)cuadrante]<<endl;
                }
                
                cout<<endl;
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

    if(nombre!=OPCIONES_MENU[SALIR]){
        
        if(nombre == NOMBRES_CHAR[AGUA] || nombre == NOMBRES_CHAR[BALA])
            cantidad = pedir_dato("\n\n\tIngrese la cantidad (mayor a 0): ","\n\n\tIngrese una cantidad mayor a 0 ",1,MAX_CANTIDAD_ELEMENTO,OPCIONES_MENU[SALIR]);

        posicion = pedir_posicion();

        if(posicion!=POSICION_FALSA){

            objeto = datos->obtener_objeto(datos->buscar_objeto(posicion));
                    
            if(objeto!=nullptr){

                indice_nombre = buscar_dato(NOMBRES_CHAR,MAX_NOMBRES,objeto->obtener_nombre());
            
                cout<<"\n\n\tSe encontro el objeto de Nombre: "<<NOMBRES_STRING[indice_nombre];
                cout<<" en la posicion: ( "<<objeto->obtener_posicion().obtener_x()<<" , "<<objeto->obtener_posicion().obtener_y()<<" )"<<endl;
                cout<<"\n\tNo se pudo agregar el objeto. "<<endl;
            }
            else{
                
                indice_nombre = buscar_dato(NOMBRES_CHAR,MAX_NOMBRES,nombre);

                objeto = datos->crear_objeto(indice_nombre,nombre,posicion,cantidad);

                datos->agregar_objeto(objeto);
                
                cout<<"\n\n\tSe agrego el objeto de Nombre: "<<NOMBRES_STRING[indice_nombre];
                cout<<" en la posicion: ( "<<posicion.obtener_x()<<" , "<<posicion.obtener_y()<<" )"<<endl;
            }
            cout<<endl;
            pausa();
        }
    }                

}
void Menu::menu_eliminar_objeto(){

    Coordenada posicion;
    bool eliminado=false;
    
    posicion = pedir_posicion();

    if(posicion!=POSICION_FALSA){

        string nombre=" ";
        int indice = NO_ENCONTRADO;
        Objeto *objeto = datos->obtener_objeto(datos->buscar_objeto(posicion));
        
        if(objeto!=nullptr)
            indice = buscar_dato(NOMBRES_CHAR,MAX_NOMBRES,objeto->obtener_nombre());


        if(indice!=NO_ENCONTRADO)
            nombre = NOMBRES_STRING[indice];
        
        eliminado = datos->eliminar_objeto(posicion);

        if(eliminado)
            cout<<"\n\n\tSe ha eliminado el objeto "<<nombre<<" satisfactoriamente"<<endl;
        else   
            cout<<"\n\n\tNo se ha encontrado algun objeto en la posicion"<<endl;
    }
    cout<<endl;
    pausa();
}

void Menu::menu_mostrar_objeto(){

    Coordenada posicion;
    Objeto *objeto;
    
    posicion = pedir_posicion();

    if(posicion!=POSICION_FALSA){

        objeto = datos->obtener_objeto(datos->buscar_objeto(posicion));
        
        if(objeto!=nullptr){
            cout<<endl<<"Objeto encontrado (detalles): \n\n\t";
            objeto->mostrar();
        }
        else   
            cout<<"\n\tNo se ha encontrado algun objeto en la posicion"<<endl;
    }   
    cout<<endl;
    pausa();
}