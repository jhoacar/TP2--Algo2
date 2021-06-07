#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
using std::string;

#include "Lista.h"

const int NO_ENCONTRADO = -1;

int minimo(int numero_a, int numero_b);
bool es_minuscula(char letra);
char caracter_mayuscula(char caracter);
string cadena_mayuscula(string cadena);
string obtener_texto(const string nombre_fichero);
Lista<string> dividir_texto(const string texto,const char delim);
string solo_numeros(string &cadena);
int convertir_entero(string cadena);
void gotoxy(short x,short y);
void limpiar_pantalla();

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
	return encontrado? indice : NO_ENCONTRADO;
}
#endif
