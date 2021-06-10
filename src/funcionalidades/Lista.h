#ifndef LISTA_H
#define LISTA_H


#include "Nodo.h"

template <class Dato>
class Lista
{
	protected:
		Nodo<Dato> *inicio;
		Nodo<Dato> *fin;
		size_t tamano;
	public:
		Lista();
		~Lista();
		/*
		PRE: Un dato a cargar en la lista
		POST: Almacena en la ultima posicion el dato
		*/
		void agregar(Dato dato);
		/*
		PRE: 
		POST: Obtiene el tamaño de la lista
		*/
		size_t obtener_tamano();
		/*
		PRE: Un indice a buscar
		POST: Retorna verdadero si es un indice perteneciente a la lista, falso caso contrario
		*/
		bool es_valido(const size_t indice);
		/*
		PRE: Un indice a buscar
		POST: Retorna el nodo encontrado en dicho indice
		*/
		Nodo<Dato>* buscar_nodo(const size_t indice);
		/*
		PRE: Un indice a buscar el nodo
		POST: Retorna el dato encontrado en dicho indice
		*/
		Dato operator[](const size_t indice);
		/*
		PRE: Una Lista a asignar
		POST: Carga toda la informacion de la lista del parametro
		*/
		void operator=(const Lista);
		
};

template <class Dato>
Lista<Dato>::Lista()
{
	this->inicio = new Nodo<Dato>();

	this->fin=this->inicio;
	
	this->tamano=0;

}


template <class Dato>
Lista<Dato>::~Lista()
{
	Nodo<Dato> *tmp;

	while( inicio!=nullptr )
	{
		
		tmp = inicio;
		
		inicio = inicio->siguiente;
		
		delete tmp;
		
		tmp=nullptr;
	}
}

template <class Dato>
void Lista<Dato>::agregar(Dato dato){

	*fin->dato=dato;

	fin->siguiente = new Nodo<Dato>();

	fin=fin->siguiente;

	tamano+=1;
}

template <class Dato>
size_t Lista<Dato>::obtener_tamano(){

	return tamano;

}

template <class Dato>
bool Lista<Dato>::es_valido(const size_t indice){

	return indice >= 0 && indice <= tamano;

}

template <class Dato>
Nodo<Dato>* Lista<Dato>::buscar_nodo(const size_t indice){

	if(!es_valido(indice))

		return nullptr;

	Nodo<Dato> *aux = inicio;
	
	Nodo<Dato> *nodo;

	size_t i=0;

	nodo=aux;

	while(aux!=nullptr && i<=indice){

		nodo=aux;

		aux=aux->siguiente;

		i++;

	} 	

	return nodo;
}

template <class Dato>
Dato Lista<Dato>::operator[](const size_t indice){
	
	Nodo<Dato> *nodo = buscar_nodo(indice);

	if(nodo!=nullptr)

		return *(nodo->dato);

	return	nullptr;
}

template <class Dato>
void Lista<Dato>::operator=(const Lista<Dato> lista){
	
	this->inicio 	= lista.inicio;

	this->fin 		= lista.fin;

	this->tamano	= lista.tamano;

}

#endif