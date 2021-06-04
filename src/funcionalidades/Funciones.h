#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <fstream>
#include <sstream>
#include "Lista.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::fstream;

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
template <class Dato>
int buscar_dato(const Dato vector[],const size_t tope,Dato dato){
	size_t indice = 0;
	bool encontrado=false;
	while(!encontrado&&indice<tope){
		if(vector[indice]==dato)
			encontrado=true;
		else
			indice++;
	}
	return encontrado? indice : -1;
}

#endif
