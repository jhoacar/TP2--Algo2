#ifndef CRUZ_H
#define CRUZ_H

#include "Elemento.h"

class Cruz : public Elemento
{
	public:
		Cruz();
		Cruz(Coordenada posicion,char nombre,int cantidad);
		void mostrar();
		~Cruz();
	protected:
};

#endif
