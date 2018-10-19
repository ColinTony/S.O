#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h> // para concatenear las cadenas
#include <time.h> // para el formato de fecha y hora
#include <windows.h>
#include "archivos.h"


/*
*	int crearArchivo(archivo *archivo)
*	Descripcion : Esta funcion crea un arvhido en una ruta especificada
*	Recibe : una estrucura archivo y un path para verificar la carpeta
*	Devuelve : int. 1 si se creo correctamente el archivo y -1 si no fue asi.

int crearArchivo(archivo *archivo , char *pathTemp)
{
	int id; // es el fd 
	// creamos una archivo
	// con lectura y escritura
	
	// verificacion de la  Carpeta exitente antes de crear y escribir en el archivo
	entrarCrearDirectorio(pathTemp);

	// Tiene prermisos de lectura y escritura
	id = open(archivo->path,  O_CREAT, S_IROTH|S_IWOTH); // int creat( const char *pathname, mode_t mode ) tambiens se puede utiizar creat.
	// pero open ya hace la funcion de crear el archivo si no exite
	write(id,archivo->contenido,strlen(archivo->contenido));
	close(id); // ceerramos el archivo creado

	return id;
}/*

/*
*	La misma funcion apra crear un archivo pero para windwos
*	int crearArchivoW(archivo *archivo)
*	Descripcion : Esta funcion crea un arvhido en una ruta especificada
*	Recibe : una estrucura archivo y un path para verificar la carpeta
*	Devuelve : int. 1 si se creo correctamente el archivo y -1 si no fue asi.
*/

int crearArchivoW(archivo *archivo , char *pathTemp)
{
	int id=1;
	FILE *file;
	// creamos una archivo
	// con lectura y escritura
	
	// verificacion de la  Carpeta exitente antes de crear y escribir en el archivo
	entrarCrearDirectorio(pathTemp);

	// Tiene prermisos de lectura y escritura
	file = fopen(archivo->path,"w"); // int creat( const char *pathname, mode_t mode ) tambiens se puede utiizar creat.
	// pero open ya hace la funcion de crear el archivo si no exite
	fputs(archivo->contenido,file);
	fclose(file); // ceerramos el archivo creado

	return id;
}


/*
*	int entrarCrearDirectorio(char *pathTemp)
*	Descripcion : Esta funcion entra dentro de un direcotorio y si no existe lo crea
*	Recibe : Un path de en donde entrar o crear el directorio
*	Devuelve : void
*/
void entrarCrearDirectorio(char *pathTemp)
{
	DIR *dir;
	dir = opendir(pathTemp);
	if(dir == NULL)
	{
		// no existe el archivo
		printf("\n se creo un directorio: %s \n", pathTemp);
		CreateDirectory(pathTemp,NULL);
	}
	closedir(dir);
}

/*
*	void leerDirectorio(char *pathTemp)
*	Descripcion : Ingresas un path y recorremos los archivos mostrando sus datos
*	Recibe : Un path de en donde entrar o crear el directorio
*	Devuelve : void
*/
/*
	In the glibc implementation, the dirent structure is defined as follows:

           struct dirent {
               ino_t          d_ino;        Inode number 
               off_t          d_off;        Not an offset; see below 
               unsigned short d_reclen;     Length of this record 
               unsigned char  d_type;       Type of file; not supported
                                              by all filesystem types 
               char           d_name[256];  Null-terminated filename 
           };

     
     
	struct stat {
	    dev_t     st_dev;      ID of device containing file 
	    ino_t     st_ino;      inode number 
	    mode_t    st_mode;     protection 
	    nlink_t   st_nlink;    number of hard links 
	    uid_t     st_uid;      user ID of owner 
	    gid_t     st_gid;      group ID of owner 
	    dev_t     st_rdev;     device ID (if special file) 
	    off_t     st_size;     total size, in bytes 
	    blksize_t st_blksize;  blocksize for file system I/O 
	    blkcnt_t  st_blocks;   number of 512B blocks allocated 
	    time_t    st_atime;    time of last access 
	    time_t    st_mtime;    time of last modification 
	    time_t    st_ctime;    time of last status change 
	};

	S_ISREG // es un archivo regular

	/root/Documentos/ESCOM/SO/Practicas/Practica2/Practica2_10

	  S_ISREG(m)  is it a regular file?

       S_ISDIR(m)  directory?

       S_ISCHR(m)  character device?

       S_ISBLK(m)  block device?

       S_ISFIFO(m) FIFO (named pipe)?

       S_ISLNK(m)  symbolic link?  (Not in POSIX.1-1996.)

       S_ISSOCK(m) socket?  (Not in POSIX.1-1996.)
*/
// /root/Documentos/ESCOM/SO/Practicas/Practica2/Practica2_10

void leerDirectorio(char *pathTemp)
{
	printf("\n---------------------------------> LISTA DE ARCHIVOS <-------------------------------------\n");
	int estado; // para ir verificando los estados del archivo
	DIR *dir;
	char *pathAux;
	char date[50]; // para guardar la fecha
	dir = opendir(pathTemp);
	//* en *ent habrá información sobre el archivo que se está "sacando" a cada momento 
  	struct dirent *ent;
  	//Tendra toda la informacion del archivo stat
  	struct stat statFile;

	ent = readdir(dir);	
	while (ent != NULL)
    {
    	// Nos devolverá el directorio actual (.) y el anterior (..), como hace ls 
     	if ( (strcmp(ent->d_name, ".") != 0) && (strcmp(ent->d_name, "..") != 0) )
    	{
    		pathAux = obtenerRuta(pathTemp,ent->d_name);
    		estado = stat(pathAux,&statFile);
     		// verificamos que el archivo exista
     		if(estado < 0) {
				printf("\nError al intentar acceder a los atributos de ");
				printf(ent->d_name);
				perror("\nError en lstat");
				exit(-1);
			}
			printf("\n Nombre: %s. \t Tamaño :%d bytes. \t Ultimo acceso : %s",ent->d_name,statFile.st_size,ctime(&statFile.st_atime));

    	}
    	// Debo volver a preguntar antes de regresar al while ya que si no
    	// se va queuerer accesder a una direccion de memoria la cual no esta permitida.
    	// esto genera una violacion de segmento.
    	ent = readdir(dir);
    	if(ent == NULL)
    	{
    		printf("\n---------------------------------> FIN DE LISTA DE ARCHIVOS <-------------------------------------\n");
    		exit(0);
    	}
    }
  	closedir (dir);
}


/*
*	char * obtenerRuta(char *path , char *nombre)
*	Descripcion : obtiene la rata de un archivo
*	Recibe : Un path de en donde entrar , el nombre que va a pegar al path
*	Devuelve : la ruta del archivo
*/
char * obtenerRuta(char *path , char *nombre)
{
	// Obtenemos la ruta completa...
    char * temp = (char *) malloc(2 + strlen(path)+ strlen(nombre) ); // Tamaño + 1
  	//Copiamos path
    strcpy(temp, path);
    //Metemos la barra
    strcat(temp, "/");
    //Metemos el nombre
    strcat(temp, nombre);

return temp;
}