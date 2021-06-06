#ifndef VAMPIRO_H
#define VAMPIRO_H

#include "../Monstruo.h"

class Vampiro : public Monstruo
{
	public:
		Vampiro();
		Vampiro(Coordenada posicion,char nombre);
		void mostrar();
		~Vampiro();
	protected:
};

#endif
