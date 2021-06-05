#ifndef ESTACA_H
#define ESTACA_H

#include "Elemento.h"

class Estaca : public Elemento{
	public:
		Estaca();
		Estaca(Coordenada posicion,char nombre,int cantidad);
		~Estaca();
	protected:
};

#endif
