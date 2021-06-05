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
		void menu_buscar_elemento();
		void menu_agregar_elemento();
		void menu_eliminar_elemento();
		void menu_mostrar_elemento();
		void menu_letra_incorrecta();
	protected:
};

#endif
