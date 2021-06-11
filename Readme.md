# TP2 (Algoritmos y Programacion II)

**Contenidos**

Linea de compilacion

Previamente de haber instalado `build-essential` y `make` se puede compilar el proyecto, ejecutando el comando  `$ make`.
El proyecto se compilara con flags de `gdb` para su depuracion y cada `.o` del proyecto generado sera guardado en la carpeta `$ ./obj/...` con el mismo orden, en caso de desear eliminarlos, se debera ejecutar el comando `$ make clean`.
Tambien se puede revisar la memoria luego de compilacion con `valgrind` ejecutando 
	`$ make valgrind`

Imagenes

![](https://i.ibb.co/k9Mbb7X/compilacion.jpg)

> Proyecto correctamente compilado y linkado con su ejecutable de nombre `TP2`.

![](https://i.ibb.co/ckhvFTV/menu-principal.jpg)

> Proyecto en ejecucion ubicado en el Menu Principal .

![](https://i.ibb.co/MGwy25L/valgrind.jpg)

> Proyecto ya ejecutado con `valgrind` y haciendo chequeo de memoria.

Lista de Clases

+ SRC
	+ FUNCIONALIDADES
		+ DATOS         `Manipula la informacion del fichero de entrada`
		+ FUNCIONES `Funciones elementales de ejecucion del programa`
		+ LISTA            `Clase usada para el uso de un vector dinamico`
		+ NODO           `Clase usada por lista`
	+ INTERFAZ
		+ MENU `Clase usada para la interaccion en consola con la informacion`
	+ OBJETOS
		+ SERES
			+ HUMANOS
				+ HUMANO
				+ CAZADOR
			+ MONSTRUOS
				+ VAMPIROS
				+ ZOMBIES
		+ ELEMENTOS
			+  ELEMENTO
		+ OBJETO