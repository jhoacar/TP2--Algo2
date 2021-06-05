#ifndef ELEMENTO_H
#define ELEMENTO_H

#include "../Objeto.h"

class Elemento : public Objeto
{
	public:
		Elemento();
		Elemento(Coordenada posicion,char nombre,int cantidad);
		void mostrar();
		int obtener_cantidad();
		~Elemento();
	protected:
		int cantidad;
};

#endif
