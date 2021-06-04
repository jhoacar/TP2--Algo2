#ifndef SER_H
#define SER_H

#include "../Objeto.h"

class Ser : public Objeto
{
	public:
		Ser(Coordenada posicion,std::string nombre);
		void mostrar();
		~Ser();
};

#endif
