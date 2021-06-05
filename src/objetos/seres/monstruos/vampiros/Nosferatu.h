#ifndef NOSFERATU_H
#define NOSFERATU_H

#include "Vampiro.h"

class Nosferatu : public Vampiro
{
	public:
		Nosferatu();
		Nosferatu(Coordenada posicion,char nombre);
		~Nosferatu();
	protected:
};

#endif
