#ifndef MONSTRUO_H
#define MONSTRUO_H

#include "../Ser.h"

class Monstruo : public Ser
{
	public:
		Monstruo();
		Monstruo(Coordenada posicion,std::string nombre);
		~Monstruo();
	protected:
};

#endif
