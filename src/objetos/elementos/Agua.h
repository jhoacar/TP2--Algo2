#ifndef AGUA_H
#define AGUA_H

#include "Elemento.h"

class Agua : public Elemento
{
	public:
		Agua(Coordenada posicion,string nombre,int cantidad);
		~Agua();
	protected:
};

#endif
