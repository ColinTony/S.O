/*
	En este pequeño programa usando los archivos creados en el programa practica2_8
	utilizando llamadas al sistema desarrollar una programa en C qie liste todos los
	archivos creados , mostrando su tamalo , fecha y hora de accseso
	path de prueba : /root/Documentos/ESCOM/SO/Practicas/Practica2/Practica2_10
*/
#include <stdio.h>
#include "archivos.h"

int main(int argc, char const *argv[])
{
	char pathTemp;
	printf("Ingresa el Path de tu directorio a leer \n");
	scanf("%s",&pathTemp);
	leerDirectorio(&pathTemp);
	return 0;
}