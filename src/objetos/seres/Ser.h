#ifndef SER_H
#define SER_H

#include "../Objeto.h"

class Ser : public Objeto
{
	public:
		Ser();
		Ser(Coordenada posicion,char nombre);
		~Ser();
};

#endif
