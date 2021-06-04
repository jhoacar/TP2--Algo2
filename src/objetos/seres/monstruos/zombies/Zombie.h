#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../Monstruo.h"

class Zombie : public Monstruo
{
	public:
		Zombie();
		Zombie(Coordenada posicion,std::string nombre);
		~Zombie();
	protected:
};

#endif
