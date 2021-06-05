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
	Tablero *tablero;

	void crear_tablero(string dimensiones);
	void cargar_objetos(Lista<string> datos);
	void cargar_tablero();
	
	Objeto* crear_objeto(const int opcion,const char nombre,Coordenada posicion,const int cantidad);
	bool es_elemento(Objeto *objeto);

	Coordenada convertir_posicion(Lista<string> &datos);
	string convertir_nombre(Lista<string> &datos);
	int convertir_cantidad(Lista<string> &datos);

	public:
		Datos(const string nombre_archivo);
		~Datos();
		void mostrar_resumen();
		void mostrar_tablero();
		int obtener_cantidad(const char *objeto);
	protected:
};

#endif
