#ifndef DATOS_H
#define DATOS_H

#include "../objetos/Objeto.h"
#include "Tablero.h"
#include <string>
using std::string;
using std::type_info;

const size_t MAX_OBJETOS = 12;

const string CAZADOR = "CV";

const string OBJETOS[MAX_OBJETOS]=	{"agua","bala","cruz","estaca","escopeta","humano","humano CV","Vanesa","vampiro","Vampirella","Nosferatu","zombi"};

const char NOMBRES[MAX_OBJETOS]=	{'a',	'b',	'c',	'e',	'E',		'h',		'H',	'W',		'v',		'V',		'N',	'z'};

enum {AGUA=0,BALA,CRUZ,ESTACA,ESCOPETA,HUMANO,HUMANO_CAZADOR,VANESA,VAMPIRO,VAMPIRELLA,NOSFERATU,ZOMBIE};


class Datos
{
	Lista_Punteros<Objeto *> objetos;
	Tablero *tablero;

	/*
	PRE: Linea de texto con informacion de las dimensiones del tablero separadas por un espacio
	POST: crea un tablero con las dimensiones extraidas
	*/
	void crear_tablero(const string &dimensiones);
	/*
	PRE: Una lista de strings donde cada posicion es el detalle de cada objeto a cargar
	POST: guarda en la lista de punteros de objeto cada tipo de objeto encontrado en las cadena de string
	*/
	void cargar_objetos( Lista<string> &datos);
	/*
	PRE:  
	POST: Carga el tablero en la posicion que posea cada objeto de la lista de objetos
	*/
	void cargar_tablero();
	/*
	PRE: Un puntero de objeto con la informacion cargada 
	POST: Devuelve si pertenece al conjunto de elementos que tiene cantidad
	*/
	bool tiene_cantidad(Objeto *objeto);
	/*
	PRE: Una lista de string con la informacion de la linea del fichero
	POST: Decodifica la informacion y devuelve la posicion que encontro en la linea
	*/
	Coordenada 	convertir_posicion(const string &linea);
	/*
	PRE: Una lista de string con la informacion de la linea del fichero
	POST: Decodifica la informacion y devuelve el nombre que encontro en la linea
	*/
	string 		convertir_nombre  (	Lista<string> &datos);
	/*
	PRE: Una lista de string con la informacion de la linea del fichero
	POST: Decodifica la informacion y devuelve la cantidad que encontro en la linea
	*/
	int 		convertir_cantidad(	Lista<string> &datos);

	public:
		/*
		PRE: El nombre del fichero donde esta almacenada la informacion
		POST: Decodifica y carga los datos en el tablero y en la lista de objetos 
		*/
		Datos(const string nombre_archivo);
		/*
		PRE:
		POST: Destruye todos los elementos del tablero incluyendo los datos de la lista de objetos
		*/
		~Datos();
		/*
		PRE:
		POST: Muestra el resumen estadistico de los objetos, con el porcentaje de cada uno
		*/
		void mostrar_resumen();
		/*
		PRE:
		POST: Muestra en detalle cada objeto y sus atributos 
		*/
		void mostrar_datos();
		/*
		PRE:
		POST: Devuelve el tablero 
		*/
		Tablero* obtener_tablero();
		/*
		PRE: Un nombre del objeto a buscar
		POST: Obtiene la cantidad que exista del objeto, acumulando la cantidad si es Agua o Bala 
		*/
		int obtener_cantidad(int tipo_objeto);
		/*
		PRE: Una cadena referente al cuadrante y el nombre del objeto a buscar
		POST: Devuelve un puntero del objeto encontrado 
		*/
		Objeto* buscar_objeto(string cuadrante,char nombre);
		/*
		PRE: Una posicion del objeto a buscar
		POST: Devuelve un puntero del objeto encontrado  
		*/
		Objeto* buscar_objeto(Coordenada posicion);
		/*
		PRE: Un tipo de objeto (agua, bala,...) el nombre que tendra, la posicion y la cantidad si es que la tiene
		POST: Devuelve el objeto creado con dichas especificaciones
		*/
		Objeto* crear_objeto(const int tipo,const char nombre,Coordenada posicion,const int cantidad);
		
	protected:
};

#endif
