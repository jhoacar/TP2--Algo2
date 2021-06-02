#ifndef ESTACA_H
#define ESTACA_H

#include "Elemento.h"

class Estaca : public Elemento{
	public:
		Estaca(Coordenada posicion,string nombre,int cantidad);
		~Estaca();
	protected:
};

#endif
