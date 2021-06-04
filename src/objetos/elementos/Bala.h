#ifndef BALA_H
#define BALA_H

#include "Elemento.h"

class Bala : public Elemento
{
	public:
		Bala();
		Bala(Coordenada posicion,string nombre,int cantidad);
		~Bala();
	protected:
};

#endif
