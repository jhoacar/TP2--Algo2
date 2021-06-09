#ifndef NODO_H
#define NODO_H


template <class Dato>
class Nodo{
    Dato dato;
    Nodo<Dato> *siguiente;
    public:
        //Usado para poder acceder a estos miembros desde la clase lista
        template <class> friend class Lista;
        Nodo(){
            siguiente=nullptr;
        }
        ~Nodo(){

        }
};

#endif