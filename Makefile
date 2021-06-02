# Project: TP2
# Makefile creado por Jhoan Carrero

APP 		:= TP2
#Nombre del fichero de salida ya compilado y enlazado

CPP     	:= g++
#Compilador del proyecto

FLAGS 		:= -Wall -pedantic
#Banderas de compilacion que muestran en detalle cada error

MKDIR 		:= mkdir -p
#Instruccion para crear carpetas y subcarpetas con el uso de -p

SRC 		:= src
#Carpeta raiz del proyecto a compilar
OBJ 		:= obj
#Carpeta de almacenamiento de ficheros binarios para linkar

HEADERS 	:= $(wildcard ./*/Lista.h) $(wildcard ./*/Nodo.h) $(wildcard ./*/Objeto.h)
#En las carpetas funcionalidades (lista.h, nodo.h) y objetos (objeto.h) para enlazar

ALLCPPS 	:= $(shell find src/ -type f -iname *.cpp)
#Dado que se permite el uso de script shell realizamos la busqueda (find) en src 
#Que sea de tipo fichero (-f) con todos los nombres (-iname, mayuscula o no) de extension .cpp (*.cpp)

ALLOBJECTS 	:= $(patsubst $(SRC)%.cpp,$(OBJ)%.o,$(ALLCPPS)) 
#Sustituimos de cada archivo el prefijo .cpp por el prefijo .o y la carpeta ./src por ./obj

OBJECTS_DIR := $(patsubst $(SRC)%,$(OBJ)%,$(ALLOBJECTS))
#Sustituimos la carpeta raiz de src/ por la carpeta obj/

SUBDIRS 	:= $(shell find src/ -type d) 
#Encontramos todas las subcarpetas de los archivos con find pero usando -type d (tipo directorio)

OBJSUBDIRS	:= $(patsubst $(SRC)%,$(OBJ)%,$(SUBDIRS))
#Cambiamos a cada subdirectorio que existe la raiz de src por la raiz de obj

INCLUDE 	:= -I. $(subst ./,-I./,$(SUBDIRS))
#Incluimos todas las carpetas donde se encuentran la informacion de los ficheros con flag -I para la compilacion


#Al ejecutar make, arrancara a realizar esta operacion
$(APP): $(OBJSUBDIRS) $(ALLOBJECTS)
	$(CPP) -o $(APP) $(ALLOBJECTS)
#La cual se ejecutara cuando tengo resuelto todos los OBJETOS que son todos los *.o

#Algo que sea .o (%.o) depende de ese mismo nombre pero .cpp (%.cpp)
$(OBJ)/%.o:$(SRC)/%.cpp
	$(CPP) -o $@ -c $^    
#$(INCLUDE)  
#$(FLAGS)  
#Generamos el binario con -o
#El macro $@ es todo antes del : en este caso %.o
#Realizamos un patsubst para sustituir la carpeta de src/ por carpeta obj/ donde almacenara los ficheros .o
#El macro $^ son todas las dependencias luego del : en este caso %.cpp
#Compilamos unicamente mediante el flag -c añadiendo las dependencias %.o si se necesitan


$(OBJSUBDIRS):
	$(MKDIR) $(OBJSUBDIRS)
#Creo la carpeta donde se guardaran todos los ficheros binarios

clean:
	rm -i $(ALLOBJECTS)
#Elimino la carpeta de los ficheros binarios
#
#$(info $(DIRS))

.PHONY: info

info:
#$(info $(ALLOBJECTS))
	$(info $(OBJECTS_DIR))
#@echo -e \n FICHEROS: \n\n $(OBJECTS) \n\n DIRECTORIOS: \n\n ${SUBDIRS} \n\n INCLUDES: \n\n ${INCLUDE} \n\n LINEA DE COMPILACION: \n\n 
	