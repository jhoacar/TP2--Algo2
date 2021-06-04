#ifndef TABLERO_H
#define TABLERO_H

#include "../objetos/Objeto.h"
#include "Lista.h"
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
		void cargar(Objeto *objeto);
		~Tablero();
	protected:
};

#endif