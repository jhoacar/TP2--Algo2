#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

template <class Dato>
class Lista
{
	Nodo<Dato> *inicio;
	Nodo<Dato> *fin;
	unsigned int tamano;
	public:
		Lista(const unsigned int tamano);
		Lista();
		~Lista();
		void agregar(Dato dato);
		unsigned int obtener_tamano();
		bool es_valido(const unsigned int indice);
		Nodo<Dato>* buscar_nodo(const unsigned int indice);
		Dato operator[](const unsigned int indice);
		void operator=(const Lista);
	protected:
};

template <class Dato>
Lista<Dato>::Lista()
{
	this->inicio = new Nodo<Dato>();
	this->fin=this->inicio;
	this->tamano=0;
}

template <class Dato>
Lista<Dato>::Lista(const unsigned int tamano){
	if(tamano>0){
		this->tamano=tamano;
		this->inicio = new Nodo<Dato>();
		fin=inicio;	
		unsigned int i=0;
		while(i<tamano){
			fin->siguiente= new Nodo<Dato>();
			fin=fin->siguiente;
			i++;
		}
	}
}
template <class Dato>
Lista<Dato>::~Lista()
{
	delete inicio;	
	inicio=nullptr;
	fin=nullptr;
	tamano=0;
}
template <class Dato>
void Lista<Dato>::agregar(Dato dato){
	fin->dato=dato;
	fin->siguiente = new Nodo<Dato>();
	fin=fin->siguiente;
	tamano+=1;
}
template <class Dato>
unsigned int Lista<Dato>::obtener_tamano(){
	return tamano;
}
template <class Dato>
bool Lista<Dato>::es_valido(const unsigned int indice){
	return indice>=0&&indice<=tamano;
}

template <class Dato>
Nodo<Dato>* Lista<Dato>::buscar_nodo(const unsigned int indice){
	if(!es_valido(indice))
		return nullptr;
	Nodo<Dato> *aux = inicio, *nodo;
	unsigned int i=0;
	nodo=aux;
	while(aux!=nullptr && i<=indice){
		nodo=aux;
		aux=aux->siguiente;
		i++;
	} 	
	return nodo;
}

template <class Dato>
Dato Lista<Dato>::operator[](const unsigned int indice){
	return (buscar_nodo(indice))->dato;
}

template <class Dato>
void Lista<Dato>::operator=(const Lista<Dato> lista){
	this->inicio 	= lista.inicio;
	this->fin 		= lista.fin;
	this->tamano	= lista.tamano;
}


#endif