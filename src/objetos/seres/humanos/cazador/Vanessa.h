#ifndef VANESSA_H
#define VANESSA_H

#include "Cazador.h"

class Vanessa : public Cazador
{
	public:
		Vanessa();
		Vanessa(Coordenada posicion,std::string nombre);
		~Vanessa();
	protected:
};

#endif
