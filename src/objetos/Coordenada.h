#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada
{
	int x;
	int y;
	public:
		/*
		PRE:
		POST: Crea una coordenada a (0,0)
		*/
		Coordenada();
		/*
		PRE: Una coordenada en X e Y
		POST: Crea una coordenada con la posicion (x,y)
		*/
		Coordenada(int x, int y);
		~Coordenada();
		/*
		PRE: Devuelve la x
		POST: 
		*/
		int obtener_x();
		/*
		PRE:
		POST: Devuelve la y
		*/
		int obtener_y();
		/*
		PRE: Una coordenada a asignar
		POST: Asigna la coordenada que fue brindada 
		*/
		Coordenada& operator =(Coordenada coordenada);
		/*
		PRE: Una coordenada a evaluar
		POST: Devuelve verdadero si son diferentes , falso caso contrario
		*/
		bool operator !=(Coordenada coordenada);
		/*
		PRE: Una coordenada a evaluar
		POST: Devuelva verdadero si son iguales, falso caso contrario
		*/
		bool operator ==(Coordenada coordenada);
		/*
		PRE: Una coordenada a evaluar
		POST: Devuelve verdadero si tanto en X como en Y es menor a las componentes de la coordenada
		*/
		bool operator	<(Coordenada coordenada);
		/*
		PRE: Un numero de decremento
		POST: Le resta tanto a X como a Y el valor del decremento
		*/
		void operator -=(const int decremento);
};

#endif
