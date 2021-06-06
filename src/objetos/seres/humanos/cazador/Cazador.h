#ifndef CAZADOR_H
#define CAZADOR_H

#include "../Humano.h"

class Cazador : public Humano
{
	public:
		Cazador();
		Cazador(Coordenada posicion,char nombre);
		void mostrar();
		~Cazador();
	protected:
};

#endif
