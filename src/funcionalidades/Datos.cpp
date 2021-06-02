#include "Datos.h"
#include "Funciones.h"
#include "../objetos/elementos/Agua.h"
#include "../objetos/elementos/Bala.h"
#include "../objetos/elementos/Cruz.h"
#include "../objetos/elementos/Elemento.h"
#include "../objetos/elementos/Escopeta.h"
#include "../objetos/elementos/Estaca.h"
#include "../objetos/seres/Ser.h"
#include "../objetos/seres/humanos/Humano.h"
#include "../objetos/seres/humanos/cazador/Cazador.h"
#include "../objetos/seres/humanos/cazador/Vanessa.h"
#include "../objetos/seres/monstruos/Monstruo.h"
#include "../objetos/seres/monstruos/vampiros/Vampiro.h"
#include "../objetos/seres/monstruos/vampiros/Vampirella.h"
#include "../objetos/seres/monstruos/vampiros/Nosferatu.h"
#include "../objetos/seres/monstruos/zombies/Zombie.h"

#include <iostream>
using std::cout;
using std::string;
using std::endl;

const size_t MAX_OBJETOS = 12;
const string CAZADOR = "CV";
const string ELEMENTOS[MAX_OBJETOS]=	{"agua","bala","cruz","estaca","escopeta","humano","humano CV","Vanesa","Vampiro","Vampirella","Nosferatu","zombi"};
const string NOMBRES[MAX_OBJETOS]=	{"a",	"b",	"c",	"e",	"E",		"h",		"H",	"W",		"v",		"V",		"N",	"z"};
enum {AGUA=0,BALA,CRUZ,ESTACA,ESCOPETA,HUMANO,HUMANO_CAZADOR,VANESA,VAMPIRO,VAMPIRELLA,NOSFERATU,ZOMBIE};


Datos::Datos(){

}
Datos::Datos(string nombre_archivo)
{
	string texto = obtener_texto(nombre_archivo);
	if(texto.length()==0)
		std::cout<<"No se pudieron extraer los datos del archivo "<<nombre_archivo<<endl;
	else{
		Lista<string> datos = dividir_texto(texto,'\n');
		crear_tablero(datos[0]);
		cargar_objetos(datos);
		cargar_tablero();
	}
}

Datos::~Datos()
{

}

void Datos::cargar_tablero(){
	for(size_t i=0;i<objetos.obtener_tamano();i++)
		tablero.cargar(objetos[i]);
}
void Datos::crear_tablero(string dimensiones){
	Lista<string> datos = dividir_texto(dimensiones,' ');
	tablero = Tablero(convertir_entero(datos[0]),convertir_entero(datos[1]));
}

void Datos::cargar_objetos(Lista<string> datos){
	for(size_t i=1;i<datos.obtener_tamano();i++){
		
		Lista<string> linea = dividir_texto(datos[i],' ');
		
		int posicion_x = convertir_entero( linea[linea.obtener_tamano()-2]);
		int posicion_y = convertir_entero( linea[linea.obtener_tamano()-1]);
		Coordenada coordenada(posicion_x,posicion_y);

		string cazador = linea[1].find(CAZADOR)==string::npos ? CAZADOR : "";
		string nombre = linea[0]+cazador;
		
		int indice = buscar_dato(ELEMENTOS,MAX_OBJETOS,nombre);
		switch(indice)
		{
			case AGUA: 			objetos.agregar(new Agua(coordenada,NOMBRES[indice],convertir_entero(linea[1]))); break;

			case BALA: 			objetos.agregar(new Bala(coordenada,NOMBRES[indice],convertir_entero(linea[1]))); break;

			case CRUZ: 			objetos.agregar(new Cruz(coordenada,NOMBRES[indice],1)); break;

			case ESTACA: 		objetos.agregar(new Estaca(coordenada,NOMBRES[indice],1)); break;

			case ESCOPETA: 		objetos.agregar(new Escopeta(coordenada,NOMBRES[indice],1)); break;

			case HUMANO: 		objetos.agregar(new Humano(coordenada,NOMBRES[indice])); break;

			case HUMANO_CAZADOR:objetos.agregar(new Cazador(coordenada,NOMBRES[indice])); break;

			case VANESA: 		objetos.agregar(new Vanessa(coordenada,NOMBRES[indice])); break;

			case VAMPIRO: 		objetos.agregar(new Vampiro(coordenada,NOMBRES[indice])); break;

			case VAMPIRELLA: 	objetos.agregar(new Vampirella(coordenada,NOMBRES[indice])); break;

			case NOSFERATU: 	objetos.agregar(new Nosferatu(coordenada,NOMBRES[indice])); break;

			case ZOMBIE: 		objetos.agregar(new Zombie(coordenada,NOMBRES[indice])); break;	
		}
	}
}


int Datos::obtener_cantidad(type_info objeto){
	int cont=0;
	for(size_t i=0;i<objetos.obtener_tamano();i++){
		if(typeid(this->objetos[i])==objeto)
			cont++;
	}
	return cont;
}
