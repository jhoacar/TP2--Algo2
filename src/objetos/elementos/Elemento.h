#ifndef ELEMENTO_H
#define ELEMENTO_H

#include "../Objeto.h"

class Elemento : public Objeto
{
	public:
		Elemento(Coordenada posicion,string nombre,int cantidad);
		void mostrar();
		~Elemento();
	protected:
		int cantidad;
};

#endif
