/*
*	Programa que copie un archivo
*/

#include <stdio.h>
#include <string.h>
#include "archivos.h"
int main(int argc, char const *argv[])
{
	// veamos
	int n; // numero de archivos
	int i;
	char *paths[16];
	char pathTemp;
	archivo arch;
	
	// lo limite porque es el numero total de archivos que creamos en el punto 8 , pero se puede hacer
	// pidiendo la memoria necesaria para poner todos los paths que desees.
	printf("Cuantos archivos deseas copiar ? (Maximo = 15) \n");
	scanf("%d",&n);
	printf("%d \n", n);

	for(i = 0; i<n; i++)
	{
		printf("\n Ingresa el path %i del archivo a copiar y leer \n" , (i+1));
		scanf("%s",pathTemp);

		printf("%s\n",pathTemp);
		
		//strcpy(paths[i],&pathTemp);
	}

	for(i = 0; i<n; i++)
	{
		printf(" \n CONTENIDO DEL ARCHIVO : \n");
		
		if(leerArchivoW(&arch)<0)
			return 0;
		printf("Ingresa path en donde se va copiar el archivo %i del path : %s",(i+1),paths[i]);

	}

	// C:\Users\colin\Documents\Colin\Escuela\3er_Semestre\S.O\Practicas\Practica2\Practica2_12_8\hola ->> path del archivo
	// C:\Users\colin\Documents\Colin\Escuela\3er_Semestre\S.O\Practicas\Practica2\Practica_12_11 ->> path en donde se va copiar
	return 0;
}