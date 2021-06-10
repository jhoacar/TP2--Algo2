#ifndef MENU_H
#define MENU_H

#include "../funcionalidades/Datos.h"
#include <string>
using std::string;
class Menu
{
	Datos *datos;
	public:
		/*
		PRE:
		POST: Crea un menu con todos los datos del fichero 
		*/
		Menu(string archivo);
		/*
		PRE:
		POST: Elimina todos los datos reservados
		*/
		~Menu();
		/*
		PRE:
		POST: Muestra el menu solicitando los datos
		*/
		void mostrar_menu();
		/*
		PRE:
		POST: Muestra el resumen solicitando una impresion completa de los datos
		*/
		void menu_resumen();
		/*
		PRE:
		POST: Muestra el tablero
		*/
		void menu_tablero();
		/*
		PRE:
		POST: Muestra el menu de buscar el objeto por cuadrante
		*/
		void menu_buscar_objeto();
		/*
		PRE:
		POST: Muestra el menu de agregar el objeto 
		*/
		void menu_agregar_objeto();
		/*
		PRE:
		POST:
		*/
		void menu_eliminar_objeto();
		/*
		PRE:
		POST:
		*/
		void menu_mostrar_objeto();
		/*
		PRE:
		POST:
		*/
		void menu_letra_incorrecta();
		/*
		PRE:
		POST: Devuelve la opcion de salir (Q) si decide salir
			o un numero comprendido entre los cuatro cardinales en formato char (n<4)
		*/
		char pedir_cuadrante();
		/*
		PRE:
		POST: Devuelve la opcion de salir (Q) si decide salir
			o un numero comprendido entre la cantidad de objetos en formato char (n<MAX_OBJETOS)
		*/
		char pedir_objeto();
		/*
		PRE:
		POST: Devuelve la POSICION_FALSA (-1,-1) si decide salir
			o una posicion comprendida y conformes a las dimensiones del tablero
		*/
		Coordenada pedir_posicion();
		
	protected:
};

#endif
