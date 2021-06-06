#ifndef ESTACA_H
#define ESTACA_H

#include "Elemento.h"

class Estaca : public Elemento{
	public:
		Estaca();
		Estaca(Coordenada posicion,char nombre,int cantidad);
		void mostrar();
		~Estaca();
	protected:
};

#endif
