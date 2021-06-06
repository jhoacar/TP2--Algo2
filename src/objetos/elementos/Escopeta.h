#ifndef ESCOPETA_H
#define ESCOPETA_H

#include "Elemento.h"

class Escopeta : public Elemento
{
	public:
		Escopeta();
		Escopeta(Coordenada posicion,char nombre,int cantidad);
		void mostrar();
		~Escopeta();
	protected:
};

#endif
