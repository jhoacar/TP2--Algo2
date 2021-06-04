#ifndef CRUZ_H
#define CRUZ_H

#include "Elemento.h"

class Cruz : public Elemento
{
	public:
		Cruz();
		Cruz(Coordenada posicion,string nombre,int cantidad);
		~Cruz();
	protected:
};

#endif
