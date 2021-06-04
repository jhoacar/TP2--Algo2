#ifndef HUMANO_H
#define HUMANO_H

#include "../Ser.h"

class Humano : public Ser
{
	public:
		Humano();
		Humano(Coordenada posicion,string nombre);
		~Humano();
	protected:
};

#endif
