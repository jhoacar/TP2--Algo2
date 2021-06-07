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
		bool mostrar_fichero(string name);
		void menu_resumen();
		void menu_tablero();
		void menu_buscar_objeto();
		Objeto* buscar_objeto(int cuadrante,char nombre);
		void menu_agregar_elemento();
		void menu_eliminar_elemento();
		void menu_mostrar_elemento();
		void menu_letra_incorrecta();
		char pedir_cuadrante();
		char pedir_objeto();
		Coordenada pedir_posicion();
		
	protected:
};

#endif
