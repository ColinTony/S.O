#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h> // para concatenear las cadenas
#include "archivos.h"

/*
*	int crearArchivo(archivo *archivo)
*	Descripcion : Esta funcion crea un arvhido en una ruta especificada
*	Recibe : una estrucura archivo y un path para verificar la carpeta
*	Devuelve : int. 1 si se creo correctamente el archivo y -1 si no fue asi.
*/

int crearArchivo(archivo *archivo , char *pathTemp)
{
	int id; // es el fd 
	// creamos una archivo
	// con lectura y escritura
	
	// verificacion de la  Carpeta exitente antes de crear y escribir en el archivo
	DIR *dir;
	dir = opendir(pathTemp);
	if(dir == NULL)
	{
		// no existe el direcorio
		printf("\n No existe el direcorio debemos crearlo : %s",pathTemp);
		mkdir(pathTemp,0777);
	}

	// Tiene prermisos de lectura y escritura
	id = open(archivo->path,  O_CREAT|O_WRONLY, S_IROTH|S_IWOTH); // int creat( const char *pathname, mode_t mode ) tambiens se puede utiizar creat.
	// pero open ya hace la funcion de crear el archivo si no exite
	write(id,archivo->contenido,strlen(archivo->contenido));
	close(id); // ceerramos el archivo creado
	closedir(dir);

	return id;
}