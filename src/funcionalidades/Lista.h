#ifndef LISTA_H
#define LISTA_H


#include "Nodo.h"



template <class Dato>
class Lista
{
	protected:
		Nodo<Dato> *inicio;
		Nodo<Dato> *fin;
		unsigned long tamano;
	public:
		Lista();
		/*
		PRE:
		POST: Libera la memoria reservada
		*/
		~Lista();
		/*
		PRE: Un dato a cargar en la lista
		POST: Almacena en la ultima posicion el dato
		*/
		void agregar(Dato dato);
		/*
		PRE: Un indice del objeto a eliminar de la lista
		POST: Busca el dato del indice, caso afirmativo lo elimina de la lista y devuelve verdadero
		caso contrario devuelve falso
		*/
		bool eliminar(const int indice);
		/*
		PRE: 
		POST: Obtiene el tamaño de la lista
		*/
		unsigned long obtener_tamano();
		/*
		PRE: Un indice a buscar
		POST: Retorna verdadero si es un indice perteneciente a la lista, falso caso contrario
		*/
		bool es_valido(const int indice);
		/*
		PRE: Un indice a buscar
		POST: Retorna el nodo encontrado en dicho indice
		*/
		Nodo<Dato>* buscar_nodo(const int indice);
		/*
		PRE: Un indice a buscar el nodo
		POST: Retorna el dato encontrado en dicho indice
		*/
		Dato operator[](const int indice);
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
bool Lista<Dato>::eliminar(const int indice){

	Nodo<Dato> *nodo_eliminar = buscar_nodo(indice);

	if(nodo_eliminar == nullptr) //Si no se encuentra en la lista no se elimina
		return false;
	
	Nodo<Dato> *anterior = buscar_nodo(indice-1);

	if(anterior==nullptr) // Si no tiene antecesor entonces se encuentra en el inicio
	
		inicio = nodo_eliminar->siguiente; //Se referencia al que sigue
	
	else if(nodo_eliminar->siguiente == nullptr)// Si en el que sigue no hay nada, se encuentra al final
		
		fin = anterior;

	else //Se deja de referenciar 
	
		anterior->siguiente = nodo_eliminar->siguiente;

	delete nodo_eliminar;

	tamano--;
	
	return true;
}
template <class Dato>
unsigned long Lista<Dato>::obtener_tamano(){

	return tamano;

}

template <class Dato>
bool Lista<Dato>::es_valido(const int indice){

	return indice >= 0 && indice <= tamano;

}

template <class Dato>
Nodo<Dato>* Lista<Dato>::buscar_nodo(const int indice){

	if(!es_valido(indice))

		return nullptr;

	Nodo<Dato> *aux = inicio;
	
	Nodo<Dato> *nodo;

	unsigned long i=0;

	nodo=aux;

	while(aux!=nullptr && i<=indice){

		nodo=aux;

		aux=aux->siguiente;

		i++;

	} 	

	return nodo;
}

template <class Dato>
Dato Lista<Dato>::operator[](const int indice){
	
	Nodo<Dato> *nodo = buscar_nodo(indice);

	if(nodo != nullptr)
		return *(nodo->dato);
	else
		nullptr;
}

template <class Dato>
void Lista<Dato>::operator=(const Lista<Dato> lista){
	
	this->inicio 	= lista.inicio;

	this->fin 		= lista.fin;

	this->tamano	= lista.tamano;

}

#endif