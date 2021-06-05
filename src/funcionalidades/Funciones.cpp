#include "Funciones.h"

#include <fstream>
#include <sstream>
#include <iostream>

using std::cout;
using std::endl;
using std::stringstream;
using std::fstream;

#ifdef __linux__
#define LIMPIAR "CLEAR"
void gotoxy(short x,short y){
	cout<<0x1B<<"["<<y<<";"<<x<<"f";
}
#endif // __linux__

#ifdef __MINGW32__
#define LIMPIAR "CLS"
#include "windows.h"
void gotoxy(short x,short y){  
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{x,y});  
}  
#endif // __MINGW32__

void limpiar_pantalla(){
	system(LIMPIAR);
}

int minimo(int numero_a, int numero_b){
	return numero_a < numero_b ? numero_a : numero_b;
}

bool es_minuscula(char letra){
	return (int)letra>=(int)'a'&&(int)letra<=(int)'z';
}
char caracter_mayuscula(char caracter){
	if(es_minuscula(caracter))
		caracter=(char)((int)caracter-((int)'a'-(int)'A'));
	return caracter;
}

string cadena_mayuscula(string cadena){
	for(size_t i=0;i<cadena.length();i++)
		cadena[i]=caracter_mayuscula(cadena[i]);
	return cadena;
}

string obtener_texto(const string nombre_fichero){

	fstream archivo(nombre_fichero.c_str(), fstream::in );
	if(!archivo){
		cout<<"No se pudo abrir el fichero "<<nombre_fichero<<endl;
		return "";
	}
  	string datos_texto;
  	getline(archivo,datos_texto,'\0');
  	archivo.close();
  	return datos_texto;
}

Lista<string> dividir_texto(const string texto,const char delim){
	stringstream buffer_texto(texto);
	string cadena;
	Lista<string> informacion;
	while(getline(buffer_texto,cadena,delim))
		informacion.agregar(cadena);
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
	return cadena.length() > 0 ? cadena : "-1"; //Si no habian numeros regresamos -1
}
int convertir_entero(string cadena){
	return stoi(solo_numeros(cadena));
}