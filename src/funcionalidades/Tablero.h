#ifndef TABLERO_H
#define TABLERO_H

#include "../objetos/Objeto.h"
#include "Lista.h"

const string CARDINALES[4] = {"NO","SO","NE","SE"};

enum {NO=0,SO,NE,SE};

class Tablero
{
	Objeto ***objetos;
	int filas;
    int columnas;
	public:
        Tablero();
		Tablero(int filas,int columnas);
		bool posicion_valida(Coordenada posicion);
		bool existe_objeto(Coordenada posicion);
		int obtener_filas();
		int obtener_columnas();
		Objeto* obtener_objeto(Coordenada posicion);
		Objeto* obtener_objeto(string cuadrante,char nombre);
		string obtener_cuadrante(Coordenada posicion);
		void cargar_objeto(Objeto *objeto);
		void mostrar_tablero();
		~Tablero();
	protected:
};

#endif