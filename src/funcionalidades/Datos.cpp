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

	for(size_t i=0	; i < objetos.obtener_tamano()	;	i++)
	
		this->tablero->cargar_objeto(objetos[i]);
}

void Datos::crear_tablero(const string &dimensiones){
	
	Lista<string> datos = dividir_texto(dimensiones,' ');

	int numero_filas 	= convertir_entero(datos[0]);
	int numero_columnas = convertir_entero(datos[1]);
	
	if(numero_filas<0	||	numero_columnas<0)
		numero_filas = numero_columnas = 0;
	

	this->tablero = new Tablero(	numero_filas ,	numero_columnas	);
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

Coordenada Datos::convertir_posicion(const string &linea){
	
	Lista<string> datos = dividir_texto(linea,'(');
	Lista<string> posicion = dividir_texto(datos[1],',');
	
	int posicion_x = convertir_entero( posicion[0] );
	
	int posicion_y = convertir_entero( posicion[1] );
	
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

void Datos::cargar_objetos(Lista<string> &lineas){
	
	for(size_t i=1;	i<lineas.obtener_tamano();	i++){

		Lista<string> 	division_datos = dividir_texto(lineas[i],' ');

		Coordenada 		posicion_objeto = convertir_posicion(lineas[i]);

		string 			nombre_objeto	= convertir_nombre(division_datos);

		int 			cantidad_objeto = convertir_cantidad(division_datos);

		int tipo = 	buscar_dato(OBJETOS,MAX_OBJETOS,nombre_objeto);
		
		Objeto *objeto = crear_objeto(tipo	,	NOMBRES[tipo],	posicion_objeto,	cantidad_objeto);

		this->objetos.agregar(objeto);
	}
}

bool Datos::tiene_cantidad(Objeto *objeto){

	return 	objeto->obtener_nombre() ==	NOMBRES[AGUA] || objeto->obtener_nombre() == NOMBRES[BALA];
}

int Datos::obtener_cantidad(int tipo_objeto){
	int cantidad=0;

	for(size_t i=0;	i<objetos.obtener_tamano();	i++){

		if(	this->objetos[i]->obtener_nombre()	==	NOMBRES[tipo_objeto]){

			if(	tiene_cantidad(objetos[i])	){

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
	
	int cantidad_agua 		= obtener_cantidad(AGUA);
	int cantidad_balas 		= obtener_cantidad(BALA);
	int cantidad_cruces 	= obtener_cantidad(CRUZ);
	int cantidad_escopetas 	= obtener_cantidad(ESCOPETA); 
	int cantidad_estacas 	= obtener_cantidad(ESTACA);
	
	int cantidad_humano 	= obtener_cantidad(HUMANO);
	int cantidad_cazadores 	= obtener_cantidad(HUMANO_CAZADOR);
	int cantidad_vanessa 	= obtener_cantidad(VANESA);
	int cantidad_humanos 	= cantidad_humano+cantidad_cazadores+cantidad_vanessa;

	int cantidad_nosferatu 	= obtener_cantidad(NOSFERATU);
	int cantidad_vampirella = obtener_cantidad(VAMPIRELLA);
	int cantidad_vampiro 	= obtener_cantidad(VAMPIRO);
	int cantidad_zombies 	= obtener_cantidad(ZOMBIE);
	int cantidad_vampiros 	= cantidad_nosferatu+cantidad_vampirella+cantidad_vampiro;

	int cantidad_seres= cantidad_humanos + cantidad_vampiros + cantidad_zombies;

	int cantidad_elementos=	cantidad_agua + cantidad_cruces + cantidad_estacas;
	
    cout<<"ELEMENTO\tCANTIDAD\t\tPORCENTAJE"<<endl;
    cout<<"HUMANOS\t\t"<<cantidad_humanos<<"\t\t\t"	<<(cantidad_seres		!=0?100*(float)cantidad_humanos/(float)cantidad_seres:	  0)<<endl;
    cout<<"ZOMBIS\t\t"<<cantidad_zombies<<"\t\t\t"	<<(cantidad_seres		!=0?100*(float)cantidad_zombies/(float)cantidad_seres:	  0)<<endl;
    cout<<"VAMPIROS\t"<<cantidad_vampiros<<"\t\t\t"	<<(cantidad_seres		!=0?100*(float)cantidad_vampiros/(float)cantidad_seres:	  0)<<endl;
    cout<<"AGUA BENDITA\t"<<cantidad_agua<<"\t\t\t"	<<(cantidad_elementos	!=0?100*(float)cantidad_agua/(float)cantidad_elementos:	  0)<<endl;
    cout<<"CRUCES\t\t"<<cantidad_cruces<<"\t\t\t"	<<(cantidad_elementos	!=0?100*(float)cantidad_cruces/(float)cantidad_elementos: 0)<<endl;
    cout<<"ESTACAS\t\t"<<cantidad_estacas<<"\t\t\t"	<<(cantidad_elementos	!=0?100*(float)cantidad_estacas/(float)cantidad_elementos:0)<<endl;
    cout<<"ESCOPETAS\t"<<cantidad_escopetas<<"\t\t\t"<<(cantidad_balas		!=0?100*(float)cantidad_escopetas/(float)cantidad_balas:  0)<<endl;
    cout<<"BALAS\t\t"<<cantidad_balas<<"\t\t\t"		<<(cantidad_escopetas	!=0?100*(float)cantidad_balas/(float)cantidad_escopetas:  0)<<endl;

	pausa();

	int respuesta = pedir_dato("\n\tDesea visualizar los datos completos de los objetos?\n(1) SI\n(0 o ENTER) NO ","\n\tIngrese 1 (SI) o 0 o ENTER (NO)\n",1,2,0);
	if(respuesta ==1)
		mostrar_datos();
}

void Datos::mostrar_datos(){

	for( int i=0; i<objetos.obtener_tamano(); i++){

		cout<<endl<<"Objeto: "<<OBJETOS[buscar_dato(NOMBRES,MAX_OBJETOS,objetos[i]->obtener_nombre())]<<endl;
		cout<<"Posicion: x = "<<objetos[i]->obtener_posicion().obtener_x()<<" y = "<<objetos[i]->obtener_posicion().obtener_y()<<endl;
		cout<<"Cuadrante: "<<objetos[i]->obtener_cuadrante()<<endl;
	}
}

Tablero* Datos::obtener_tablero(){

	return this->tablero;

}

Objeto* Datos::buscar_objeto(string cuadrante, char nombre){
    
	size_t indice=0;
	
	bool encontrado=false;

	while(!encontrado && indice < objetos.obtener_tamano()){

		if(objetos[indice]->obtener_cuadrante() == cuadrante && objetos[indice]->obtener_nombre() == nombre)
			encontrado = true;
		else
			indice++;
	}

	return encontrado ? objetos[indice] : nullptr;
}

Objeto* Datos::buscar_objeto(Coordenada posicion){

	size_t indice=0;
	
	bool encontrado=false;

	while(!encontrado && indice < objetos.obtener_tamano()){

		if(objetos[indice]->obtener_posicion() == posicion)
			encontrado = true;
		else
			indice++;
	}

	return encontrado ? objetos[indice] : nullptr;

}
