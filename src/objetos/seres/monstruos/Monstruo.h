#ifndef MONSTRUO_H
#define MONSTRUO_H

#include "../Ser.h"

class Monstruo : public Ser
{
	public:
		Monstruo();
		Monstruo(Coordenada posicion,char nombre);
		~Monstruo();
		void mostrar();
	protected:
};

#endif
