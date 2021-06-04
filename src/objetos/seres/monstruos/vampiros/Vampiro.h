#ifndef VAMPIRO_H
#define VAMPIRO_H

#include "../Monstruo.h"

class Vampiro : public Monstruo
{
	public:
		Vampiro();
		Vampiro(Coordenada posicion,std::string nombre);
		~Vampiro();
	protected:
};

#endif
