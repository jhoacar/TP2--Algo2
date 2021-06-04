# Project: TP2
# Makefile creado por Jhoan Carrero

APP 		:= TP2
#Nombre del fichero de salida ya compilado y enlazado
CPP     	:= g++
#Compilador del proyecto
VALGRIND	:= valgrind --leak -check=full --track -origins=yes --show -reachable=yes
#Depurador
FLAGS 		:= -ggdb -std=c++11
#Banderas adicionales: -Wall -Wconversion -limits -Werror -O0 (Produce [-Werror=delete-non-virtual-dtor] al querer realizar  delete objetos[i][j] que es una clase abstracta)
#Banderas de compilacion que muestran en detalle cada error
MKDIR 		:= mkdir -p
#Instruccion para crear carpetas y subcarpetas con el uso de -p
SRC 		:= src
#Carpeta raiz del proyecto a compilar
OBJ 		:= obj
#Carpeta de almacenamiento de ficheros binarios para linkar
HEADERS		:= ./src/funcionalidades/Funciones.h ./src/funcionalidades/Lista.h ./src/funcionalidades/Nodo.h ./src/objetos/Objeto.h

ALLCPPS 	:= $(shell find src/ -type f -iname *.cpp)
#Dado que se permite el uso de script shell realizamos la busqueda (find) en src 
#Que sea de tipo fichero (-f) con todos los nombres (-iname, mayuscula o no) de extension .cpp (*.cpp)
ALLOBJECTS 	:= $(patsubst $(SRC)%.cpp,$(OBJ)%.o,$(ALLCPPS)) 
#Sustituimos de cada archivo el prefijo .cpp por el prefijo .o y la carpeta ./src por ./obj

SUBDIRS 	:= $(shell find src/ -type d) 
#Encontramos todas las subcarpetas de los archivos con find pero usando -type d (tipo directorio)
OBJSUBDIRS	:= $(patsubst $(SRC)%,$(OBJ)%,$(SUBDIRS))
#Cambiamos a cada subdirectorio que existe la raiz de src por la raiz de obj


#Al ejecutar make, arrancara a realizar esta operacion
$(APP): $(OBJSUBDIRS) $(ALLOBJECTS) $(HEADERS)
	$(CPP) -o $(APP) $(ALLOBJECTS)
#La cual se ejecutara cuando tengo resuelto todos los OBJETOS que son todos los *.o

#Algo que sea obj/...(.o) (obj/%.o) depende de ese mismo nombre pero src/...(.cpp) (src/%.cpp)
$(OBJ)/%.o:$(SRC)/%.cpp
	$(CPP) -o $@ -c $^  $(FLAGS)  
#Generamos el binario con -o
#El macro $@ es todo antes del : en este caso /obj/%.o
#El macro $^ son todas las dependencias luego del : en este caso src/%.cpp
#Compilamos unicamente mediante el flag -c y agregamos otras flags que queramos


$(OBJSUBDIRS):
	$(MKDIR) $(OBJSUBDIRS)
#Creo las carpetas donde se guardaran todos los ficheros binarios

clean:
	rm -f -r ./obj
#Elimino cada archivo binario

depuracion:
	$(VALGRIND) ./$(APP)

#PHONY es Util para que no sea dependiente y ejecute solo con instruccion make info
.PHONY: info
info:
	$(shell echo -e" \n FICHEROS A COMPILAR: \n\n $(ALLCPPS) \n\n FICHEROS OBJETO: \n\n $(ALLOBJECTS) \n\n LINEA DE COMPILACION (LINKADO FINAL): \n\n $(CPP) -o $(APP) $(ALLOBJECTS)" )
	