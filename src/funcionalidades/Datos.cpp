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

Datos::Datos(const string nombre_archivo)
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
	delete tablero;
}

void Datos::cargar_tablero(){

	for(size_t i=0	;	i<objetos.obtener_tamano()	;	i++)
	
		this->tablero->cargar_objeto(objetos[i]);
}

void Datos::crear_tablero(string dimensiones){
	
	Lista<string> datos = dividir_texto(dimensiones,' ');
	
	this->tablero =new Tablero(	convertir_entero(datos[0])	,	convertir_entero(datos[1])	);
}

Objeto* Datos::crear_objeto(const int tipo,const char nombre,Coordenada posicion, int cantidad){
	
	Objeto *objeto=nullptr;

	switch(tipo)
	{
		case AGUA: 			objeto= new Agua(posicion,nombre,cantidad); break;

		case BALA: 			objeto= new Bala(posicion,nombre,cantidad); break;

		case CRUZ: 			objeto= new Cruz(posicion,nombre,cantidad); break;

		case ESTACA: 		objeto= new Estaca(posicion,nombre,cantidad); break;

		case ESCOPETA: 		objeto= new Escopeta(posicion,nombre,cantidad); break;

		case HUMANO: 		objeto= new Humano(posicion,nombre); break;

		case HUMANO_CAZADOR:objeto= new Cazador(posicion,nombre); break;

		case VANESA: 		objeto= new Vanessa(posicion,nombre); break;

		case VAMPIRO: 		objeto= new Vampiro(posicion,nombre); break;

		case VAMPIRELLA: 	objeto= new Vampirella(posicion,nombre); break;

		case NOSFERATU: 	objeto= new Nosferatu(posicion,nombre); break;

		case ZOMBIE: 		objeto= new Zombie(posicion,nombre); break;	

		default: 			cout<<"No se ha encontrado el objeto de nombre: "<<nombre<<endl; break;
	}
	return objeto;
}

Coordenada Datos::convertir_posicion(Lista<string> &datos){
	
	int posicion_x = convertir_entero( datos[	datos.obtener_tamano()-2]	);
	
	int posicion_y = convertir_entero( datos[	datos.obtener_tamano()-1]	);
	
	Coordenada coordenada(	posicion_x	,	posicion_y	);
	
	return coordenada;
}

string Datos::convertir_nombre(Lista<string> &datos){
	
	string es_cazador = datos[1].find(CAZADOR)	==	string::npos ?	"" : " "+CAZADOR;
	
	string nombre = datos[0] + es_cazador;
	
	return nombre;
}

int Datos::convertir_cantidad(Lista<string> &datos){
	
	int cantidad=1;

	if(datos[1].find("(")	==	string::npos)
		
		cantidad = convertir_entero(datos[1]);

	return cantidad == -1 ? -1 : cantidad;
}

void Datos::cargar_objetos(Lista<string> lineas){
	
	for(size_t i=1;	i<lineas.obtener_tamano();	i++){

		Lista<string> 	division_datos 	= dividir_texto(lineas[i],' ');

		Coordenada 		posicion_objeto = convertir_posicion(division_datos);

		string 			nombre_objeto	= convertir_nombre(division_datos);

		int 			cantidad_objeto = convertir_cantidad(division_datos);

		int tipo = 	buscar_dato(ELEMENTOS,MAX_OBJETOS,nombre_objeto);
		
		Objeto *objeto = crear_objeto(tipo	,	NOMBRES[tipo],	posicion_objeto,	cantidad_objeto);

		this->objetos.agregar(objeto);
	}
}

bool Datos::es_elemento(Objeto *objeto){

	return 	typeid(*objeto)	==	typeid(Agua)||
			typeid(*objeto)	==	typeid(Bala)||
			typeid(*objeto)	==	typeid(Estaca)||
			typeid(*objeto)	==	typeid(Escopeta)||
			typeid(*objeto)	==	typeid(Cruz);
}

int Datos::obtener_cantidad(const char *tipo_objeto){
	int cantidad=0;

	for(size_t i=0;	i<objetos.obtener_tamano();	i++){

		if(	typeid(	*(this->objetos[i])).name()	==	tipo_objeto){

			if(	es_elemento(objetos[i])	){

				Elemento *elemento = (Elemento *)(objetos[i]);

				cantidad+=elemento->obtener_cantidad();

			}else{

				cantidad++;
			}
		}
	}
	return cantidad;
}

void Datos::mostrar_resumen(){
	
	int cantidad_agua 		= obtener_cantidad(typeid(Agua).name());
	int cantidad_balas 		= obtener_cantidad(typeid(Bala).name());
	int cantidad_cruces 	= obtener_cantidad(typeid(Cruz).name());
	int cantidad_escopetas 	= obtener_cantidad(typeid(Escopeta).name()); 
	int cantidad_estacas 	= obtener_cantidad(typeid(Estaca).name());
	
	int cantidad_humano 	= obtener_cantidad(typeid(Humano).name());
	int cantidad_cazadores 	= obtener_cantidad(typeid(Cazador).name());
	int cantidad_vanessa 	= obtener_cantidad(typeid(Vanessa).name());
	int cantidad_humanos 	= cantidad_humano+cantidad_cazadores+cantidad_vanessa;

	int cantidad_nosferatu 	= obtener_cantidad(typeid(Nosferatu).name());
	int cantidad_vampirella = obtener_cantidad(typeid(Vampirella).name());
	int cantidad_vampiro 	= obtener_cantidad(typeid(Vampiro).name());
	int cantidad_zombies 	= obtener_cantidad(typeid(Zombie).name());
	int cantidad_vampiros 	= cantidad_nosferatu+cantidad_vampirella+cantidad_vampiro;

	int cantidad_seres= cantidad_humanos + cantidad_vampiros + cantidad_zombies;

	int cantidad_elementos=	cantidad_agua + cantidad_cruces + cantidad_estacas;
	
    cout<<"ELEMENTO\tCANTIDAD\t\tPORCENTAJE"<<endl;
    cout<<"HUMANOS\t\t"<<cantidad_humanos<<"\t\t\t"	<<(cantidad_seres!=0?100*(float)cantidad_humanos/(float)cantidad_seres:0)<<endl;
    cout<<"ZOMBIS\t\t"<<cantidad_zombies<<"\t\t\t"	<<(cantidad_seres!=0?100*(float)cantidad_zombies/(float)cantidad_seres:0)<<endl;
    cout<<"VAMPIROS\t"<<cantidad_vampiros<<"\t\t\t"	<<(cantidad_seres!=0?100*(float)cantidad_vampiros/(float)cantidad_seres:0)<<endl;
    cout<<"AGUA BENDITA\t"<<cantidad_agua<<"\t\t\t"	<<(cantidad_seres!=0?100*(float)cantidad_agua/(float)cantidad_elementos:0)<<endl;
    cout<<"CRUCES\t\t"<<cantidad_cruces<<"\t\t\t"	<<(cantidad_elementos!=0?100*(float)cantidad_cruces/(float)cantidad_elementos:0)<<endl;
    cout<<"ESTACAS\t\t"<<cantidad_estacas<<"\t\t\t"	<<(cantidad_elementos!=0?100*(float)cantidad_estacas/(float)cantidad_elementos:0)<<endl;
    cout<<"ESCOPETAS\t"<<cantidad_escopetas<<"\t\t\t"<<(cantidad_balas!=0?100*(float)cantidad_escopetas/(float)cantidad_balas:0)<<endl;
    cout<<"BALAS\t\t"<<cantidad_balas<<"\t\t\t"		<<(cantidad_escopetas!=0?100*(float)cantidad_balas/(float)cantidad_escopetas:0)<<endl;

}

Tablero* Datos::obtener_tablero(){

	return this->tablero;

}
