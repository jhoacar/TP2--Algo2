#include "Coordenada.h"

Coordenada::Coordenada(){
	this->x=0;
	this->y=0;
}

Coordenada::Coordenada(int x, int y){
	this->x=x;
	this->y=y;	
}

Coordenada::~Coordenada(){
	
}

Coordenada Coordenada::operator =(Coordenada coordenada){
	this->x=coordenada.x;
	this->y=coordenada.y;
	return *this;
}

bool Coordenada::operator ==(Coordenada coordenada){
	return this->x==coordenada.x && this->y==coordenada.y;
}
bool Coordenada::operator<(Coordenada limite){
	return this->x > 0 && this->x < limite.x &&
		   this->y > 0 && this->y < limite.y;
}
int Coordenada::obtener_x(){
	return x;
}

int Coordenada::obtener_y(){
	return y;
}