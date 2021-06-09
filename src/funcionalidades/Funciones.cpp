#include "Funciones.h"

#include <fstream>
#include <sstream>

using std::stringstream;
using std::fstream;
using std::cin;

const string NO_NUMERO = "-1";

const size_t CANTIDAD_COLORES = 3; 

const string COLORES [CANTIDAD_COLORES] = {"VERDE","AMARILLO"};

enum {VERDE=0,AMARILLO};

const string ANSI_COLOR[CANTIDAD_COLORES] = {};

#ifdef __linux__
#define LIMPIAR "clear"
void pausa(){
	cout<<"Pulse una tecla para continuar...";
	cin.get();
}
#endif // __linux__

#ifdef __MINGW32__
#define LIMPIAR "CLS"
void pausa(){
	system("pause");
}
#endif // __MINGW32__

void color(string color){

	int indice_color = buscar_dato(COLORES,CANTIDAD_COLORES,color);

	if(indice_color != NO_ENCONTRADO)

		cout<<"\033[0;"<<ANSI_COLOR[indice_color]<<";32m";
}

void limpiar_pantalla(){

	system(LIMPIAR);
}

bool es_minuscula(char letra){

	return (int)letra >= (int)'a' && (int)letra <= (int)'z';

}
char caracter_mayuscula(char caracter){

	if(es_minuscula(caracter))

		caracter = (char)( (int)caracter - ( (int)'a' - (int)'A' ));

	return caracter;

}

string cadena_mayuscula(string cadena){

	for( size_t i=0 ; i < cadena.length() ; i++)
	
		cadena[i] = caracter_mayuscula(cadena[i]);
	
	return cadena;
}

string obtener_texto(const string nombre_fichero){

	fstream archivo( nombre_fichero.c_str() , fstream::in );

	if(!archivo){
	
		cout<<"No se pudo abrir el fichero "<<nombre_fichero<<endl;
	
		return "";
	
	}
  	
	string datos_texto;
  	
	getline(archivo,datos_texto,'\0');
  	
	archivo.close();

  	return datos_texto;
}

Lista<string>* dividir_texto(const string texto,const char delim){

	stringstream buffer_texto(texto);

	string cadena;
	
	Lista<string> *informacion = new Lista<string>();
	
	while(getline(buffer_texto,cadena,delim))
	
		informacion->agregar(cadena);
	
	return informacion;
}

string solo_numeros(string &cadena){

	size_t i=0;

	while (i < cadena.length()) {
  	
	  	if (!isdigit(cadena[i]))	
	
		  cadena.erase(i,1);
	
		else	
	
			i++; // Incrementamos siempre que no eliminemos un caracter
  	}
	
	return cadena.length() > 0 ? cadena : NO_NUMERO; //Si no habian numeros regresamos -1

}
int convertir_entero(string cadena){

	return stoi(solo_numeros(cadena));

}

int pedir_dato(string opciones,string error,int inicio,int fin,char opcion_salir){

	string respuesta;
	bool bandera = false;

	while(!bandera){

		limpiar_pantalla();

		cout<<opciones;
		
		getline(cin,respuesta,'\n');
		
		respuesta = cadena_mayuscula(respuesta);

		if(respuesta[0]==opcion_salir)
			return NO_ENCONTRADO;
		else
			bandera = convertir_entero(respuesta)>=inicio && convertir_entero(respuesta)<=fin;

		if(!bandera){
			cout<<error<<endl;
			pausa();
		}
	}
	return convertir_entero(respuesta);
}

bool mostrar_fichero(string name){
    
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
