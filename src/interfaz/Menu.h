#ifndef MENU_H
#define MENU_H

#include "../funcionalidades/Datos.h"
#include <string>
using std::string;
class Menu
{
	Datos *datos;
	public:
		Menu(string archivo);
		~Menu();
		void mostrar_menu();
		void menu_resumen();
		void menu_tablero();
		void menu_buscar_objeto();
		void menu_agregar_objeto();
		void menu_eliminar_objeto();
		void menu_mostrar_objeto();
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
