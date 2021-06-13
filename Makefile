# Project: TP2
# Makefile creado por Jhoan Carrero

#########################################################
### MACRO DE COMPILACION
# $(1) : Compilador
# $(2) : Archivo .o a generar
# $(3) : Archivo .cpp a compilar
# $(4) : Dependencias
# $(5) : Flags del compilador
define COMPILACION
$(2) : $(3) $(4)
	$(1) -c -o $(2) $(3) $(5)
endef
#########################################################
#########################################################
### MACRO DE TRANSFORMACION ./src(...).cpp -> ./obj(...).o
# $(1) : Archivo .cpp a transformar
define TO_OBJ
$(subst .cpp,.o,$(subst $(SRC),$(OBJ),$(1)))
endef
#########################################################


##########################################################
### CONFIGURACION 
APP 		:= TP2
CPP     	:= g++
VALGRIND	:= valgrind
FLAGS 		:= -ggdb -std=c++11 -Wconversion -O0 -limits -Wall -Werror -pedantic
SRC 		:= src
OBJ 		:= obj
HEADERS		:= ./src/funcionalidades/Funciones.h ./src/funcionalidades/Lista.h ./src/funcionalidades/Nodo.h ./src/objetos/Objeto.h
###########################################################

ifeq ($(OS),Windows_NT) #WINDOWS ...
##########################################################
### SHELL SCRIPT WINDOWS 
SEARCH_FILES := dir /s/b
SEARCH_DIRS  := dir $(SRC) /ad /b /s
DELETE_FILES := rmdir /Q /S 
MKDIR 		:= mkdir
##########################################################
else #LINUX ...
##########################################################
### SHELL SCRIPT LINUX 
SEARCH_FILES := find $(SRC)/ -type f -iname
SEARCH_DIRS  := find $(SRC)/ -type d
DELETE_FILES := rm -f -r ./
MKDIR 		:= mkdir -p
##########################################################
endif

#########################################################
### EXTRACCION FICHEROS DEL PROYECTO 
ALLCPPS 	:= $(shell $(SEARCH_FILES) *.cpp)
ALLOBJECTS 	:= $(subst .cpp,.o,$(subst $(SRC),$(OBJ),$(ALLCPPS)))#sustituimos la carpeta SRC por OBJ y la extencion .cpp por .o

SUBDIRS 	:= $(shell $(SEARCH_DIRS)) 
OBJSUBDIRS	:= $(subst $(SRC),$(OBJ),$(SUBDIRS))#sustituimos la carpeta SRC por OBJ
#########################################################


########################################################
### PROCESO DE LINKAR 
#Al ejecutar make, arrancara a realizar esta operacion
$(APP): $(OBJSUBDIRS) $(ALLOBJECTS)
	$(CPP) -o $(APP) $(ALLOBJECTS)
#La cual se ejecutara cuando tengo resuelto todos los OBJETOS que son todos los *.o y cree todas las carpetas
########################################################

########################################################
### GENERADOR DE REGLAS PARA CADA .o
$(foreach FICHERO,$(ALLCPPS),$(eval $(call COMPILACION,$(CPP),$(call TO_OBJ,$(FICHERO)),$(FICHERO),$(HEADERS),$(FLAGS))))
########################################################


########################################################
### CREANDO LOS SUBDIRECTORIOS ./obj
$(OBJSUBDIRS):
	$(MKDIR) $(OBJSUBDIRS)
########################################################

########################################################
### ELIMINANDO TODA LA CARPETA ./obj
clean:
	$(DELETE_FILES)$(OBJ)
########################################################

########################################################
### USO DE LA API VALGRIND PARA EJECUTAR PROYECTO
valgrind:
	$(VALGRIND) ./$(APP)
########################################################


#PHONY es Util para que no sea dependiente y ejecute solo con instruccion. Ejemplo: make info
.PHONY: info
info:
	$(info $(ALLOBJECTS))