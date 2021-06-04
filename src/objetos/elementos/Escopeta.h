#ifndef ESCOPETA_H
#define ESCOPETA_H

#include "Elemento.h"

class Escopeta : public Elemento
{
	public:
		Escopeta();
		Escopeta(Coordenada posicion,string nombre,int cantidad);
		~Escopeta();
	protected:
};

#endif
