#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada
{
	int x;
	int y;
	public:
		Coordenada();
		Coordenada(int x, int y);
		~Coordenada();
		int obtener_x();
		int obtener_y();
		Coordenada operator =(Coordenada coordenada);
		bool operator ==(Coordenada coordenada);
		bool operator	<(Coordenada coordenada);
};

#endif
