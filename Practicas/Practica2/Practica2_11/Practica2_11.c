/*
* 	Utilizando los archivos creados en Practica_8
*	realizar un programa para mostrar el contenido de un archivo seleccionado por el usuario
*	y que copie uno o m'as arvhivos creados a un directorio previamente establecido.
*/

// paths de prueba ubicacion de mi archivo /root/Documentos/ESCOM/SO/Practicas/Practica2/Practica2_8/archivos
// path donde se va copiar el archivo /root/Documentos/ESCOM/SO/Practicas/Practica2/Practica2_11
// /root/Documentos/ESCOM/SO/Practicas/textos

#include <stdio.h>
#include <string.h>
#include "archivos.h"

int main(int argc, char const *argv[])
{
	int n,i;
	char  auxiliar[100];
	char *pathTemp;
	char *pathCopia; // el direcorio donde se va copiar los archivos
	archivo arch;
	archivo archivos[16]; // los defini asi porque ya no quedaba :c

	printf("Ingresa el Path de tu directorio a leer \n");
	scanf("%s",&arch.path);
	pathTemp = arch.path;
	leerDirectorio(pathTemp);
	strcat(arch.path,"/"); // añadimos la barra

	// lo limite porque es el numero total de archivos que creamos en el punto 8 , pero se puede hacer
	// pidiendo la memoria necesaria para poner todos los paths que desees.
	printf("¿ Cuantos archivos deseas copiar ? (Maximo = 15) \n");
	scanf("%d",&n);
	// que ingrese los nombres presionando enter enc ada uno de ellos
	if(n > 16 || n < 0)
	{
		// verficando si entra en rango
		printf(" Porfavor eliga un numero dentro del rango \n");
		return 0; // matamos el programa	
	}else
	{
		for(i = 0; i<n; i++)
		{
			strcpy(archivos[i].path,arch.path);
			printf("\n Ingresa el nombre del archivo %i que deseas leer y copiar  (ej. archivo14.txt )\n" , (i+1));
			scanf("%s",&archivos[i].nombre); // guardamos los nombres
			strcat(archivos[i].path,archivos[i].nombre);
		}

		for(i = 0; i<n; i++)
		{
			printf(" \n CONTENIDO DEL ARCHIVO %i %s: \n",(i+1),archivos[i].nombre);
			 // para que guarde temporalmente la ubicacion con 
			//añadimos el nombre y lo leemos
			//strcpy(auxiliar,nombres[i]);
			//strcat(archivo.path,auxiliar);
			if(leerArchivo(&archivos[i])<0)
				return 0;
		}
		printf("Escribe el path en donde quieres copiar tus archivos \n");
		scanf("%s",arch.path);
		pathTemp = arch.path;
		for(i = 0; i<n; i++){
			printf("%s\n", archivos[i].path);	
			copiarArchivo(archivos[i].path,archivos[i].nombre,pathTemp);
		}
	}
	

	/*
	if(numero > 16 || numero < 0)
	{
		// verficando si entra en rango
		printf(" Porfavor eliga un numero dentro del rango \n");
		return 0; // matamos el programa	
	}else
	{
		// aqui  comenzamos la creacion de los arvhivos
		// verificamos si la carpeta existe.
		for(i = 0; i<numero; i++)
		{
			fd = crearArchivo(&archivos[i],pathTemp);
			if(fd == -1){
				printf("Error al crear archivos \n");
			}
		}
	}

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
	int estado;
	char nombre;
	char pathTemp; // ingrese el path 
	char pathCpy;	// direccion en donde se va copiar

	printf("\n Ingresa el Path en donde estan tus archivos \n");
	scanf("%s",&pathTemp);
	leerDirectorio(&pathTemp);

	printf("\n Ingresa el nombre del archivo a ver y copiar (ej: archivo14.txt ): \n");
	fflush(stdin);
	scanf("%s",&nombre);

	// pegamos el nombre y la barra
	strcat(&pathTemp,"/");
	strcat(&pathTemp,&nombre);

	printf("Ingresa la direccion en donde se va copiar tu archivo \n");
	fflush(stdin);
	scanf("%s",&pathCpy);
	estado = copiarArchivo(&pathTemp,&pathCpy); // path de donde se ubica el archivo y luego la direccion del directorio donde sera copiado
	if(estado < 0)
	{ 
		printf("Error al copiar el archivo \n");
		return 0;
	}*/
	return 0;
}