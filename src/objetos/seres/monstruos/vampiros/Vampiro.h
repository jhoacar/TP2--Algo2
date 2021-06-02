#ifndef VAMPIRO_H
#define VAMPIRO_H

#include "../Monstruo.h"

class Vampiro : public Monstruo
{
	public:
		Vampiro(Coordenada posicion,std::string nombre);
		~Vampiro();
	protected:
};

#endif
