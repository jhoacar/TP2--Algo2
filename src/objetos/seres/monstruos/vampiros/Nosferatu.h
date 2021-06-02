#ifndef NOSFERATU_H
#define NOSFERATU_H

#include "Vampiro.h"

class Nosferatu : public Vampiro
{
	public:
		Nosferatu(Coordenada posicion,std::string nombre);
		~Nosferatu();
	protected:
};

#endif
