#ifndef DATOS_H
#define DATOS_H
#include <typeinfo>

#include "../objetos/Objeto.h"
#include "Tablero.h"
#include <string>
using std::string;
using std::type_info;

class Datos
{
	Lista<Objeto *> objetos;
	Tablero tablero;
	public:
		Datos();
		Datos(string nombre_archivo);
		~Datos();
		void crear_tablero(string dimensiones);
		void cargar_objetos(Lista<string> datos);
		void cargar_tablero();
		int obtener_cantidad(type_info objeto);	
	protected:
};

#endif
