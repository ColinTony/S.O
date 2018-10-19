#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h> // para concatenear las cadenas
#include <time.h> // para el formato de fecha y hora
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
	entrarCrearDirectorio(pathTemp);

	// Tiene prermisos de lectura y escritura
	id = open(archivo->path,  O_CREAT, S_IROTH|S_IWOTH); // int creat( const char *pathname, mode_t mode ) tambiens se puede utiizar creat.
	// pero open ya hace la funcion de crear el archivo si no exite
	write(id,archivo->contenido,strlen(archivo->contenido));
	close(id); // ceerramos el archivo creado

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
		mkdir(pathTemp,0777);
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
int leerDirectorio(char *pathTemp)
{
	// /root/Documentos/ESCOM/SO/Practicas/Practica2/Practica2_8/archivos
	printf("\n---------------------------------> LISTA DE ARCHIVOS <-------------------------------------\n");
	int estado; // para ir verificando los estados del archivo
	DIR *dir;
	char *pathAux;
	char date[50]; // para guardar la fecha
	dir = opendir(pathTemp);
	/* en *ent habrá información sobre el archivo que se está "sacando" a cada momento */
  	struct dirent *ent;
  	/*Tendra toda la informacion del archivo stat*/
  	struct stat statFile;
	int bandera = 1;	
	while (bandera != 0)
    {
    	ent = readdir(dir);
    	if(ent == NULL){
    		bandera = 0; // se quite el while
    		printf("\n---------------------------------> FIN DE LISTA DE ARCHIVOS <-------------------------------------\n");
    		closedir(dir);
    		return 1;
    	}else{		
	    	/* Nos devolverá el directorio actual (.) y el anterior (..), como hace ls */
	     	if ( (strcmp(ent->d_name, ".") != 0) && (strcmp(ent->d_name, "..") != 0) )
	    	{

	    		pathAux = obtenerRuta(pathTemp,ent->d_name);
	    		estado = stat(pathAux,&statFile);
	     		// verificamos que el archivo exista
	     		if(estado < 0) {
	     			bandera = 0;
					printf("\nError al intentar acceder a los atributos de ");
					printf(ent->d_name);
					perror("\nError en lstat");
					exit(-1);
				}
				if(ent != NULL)
					printf("\n Nombre: %s. \t Tamaño :%d bytes. \t Ultimo acceso : %s",ent->d_name,statFile.st_size,ctime(&statFile.st_atime));
	    	}    		
    	}
    }
  	return 1;
}
/*
* Esta es la manera la cual no debemos llamar al sistema
*/
void listarArchivos(char *pathTemp)
{
	char llamada[] = "ls -la ";
	strcat(llamada,pathTemp);	
	system(llamada);
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
/*
*	void leerArchivo(archivo *archivo)
*	Descripcion : obtiene la ruta del archivo y la lee , desplegando en pantalla el contenido
*	Recibe : Un archivo el cual debe contener un path no vavcio
*	Devuelve : -1 si no pudo leerlo , 1 si lo leyo correctamente
*/
int leerArchivo(archivo *archivo)
{
	int fd;
	ssize_t nr_bytes; // para almacenar los caracteres
	fd = open(archivo->path,O_RDONLY);
	char c;
	if(fd <0)
	{
		printf("\n Error al leer el archivo\n");
		return -1;
	}
	nr_bytes = read(fd,&archivo->contenido,110);

	if(nr_bytes == 0)
		printf("Archivo esta vacio \n");
	else
		printf("\n %s \n", archivo->contenido);
	close(fd);
}
/*
*	int copiarArchivos(char *pathTemp , char * pathCpy)
*	Descripcion: Pasamos las dos rutas una de ubicacion del archivo y otra donde se creara el archivo
*	con el contenido del otro para que se copie.
*	Recibe : Dos path , el primero es la ubicacion del archivo a copiar , el segundo la ubicacion en donde 
*	se va copiar el archivo
*	Devuelve : -1 si hubo un error 1 si todo fue corrrecto.
*/
int copiarArchivo(char *pathTemp , char *nombre ,char *pathCpy)
{
	int estado=1;
	char c; // guardaremos el contenido
	archivo archivo;
	int fd; // aarchivo a copiar
	//abrimos el archivo a copiar
	fd = open(pathTemp,O_RDONLY); // lo abrimos en solo lectorua
	// comprobamos que si se habra

	if(fd == -1)
	{
		printf("\n Ocurrio un error al abrir tu archivo \n");
		estado = -1;
		return estado;
	}

	strcpy(archivo.nombre , "copia"); // nombre del archivo copiado
	strcat(archivo.nombre,nombre); // nombre pegado al copia
	strcpy(archivo.path, pathTemp); // pasamos el directorio donde se copiara
	
	//LEER EL ARCHIVO
	//El archivo se lee caracter por caracter y lo agregamos a su archivo
	while(read(fd,archivo.contenido,sizeof(110)!=0))
		write(fd,&archivo.contenido,sizeof(110));

	// creamos e archivo en donde sera copiado
	estado = crearArchivo2(&archivo,pathCpy);
	if(estado < 0)
	{
		// courrio un error;
		printf("Ocurrio un error al crear la copia el archivo \n");
		estado = -1;
		return estado;
	}

	return estado;
}
int crearArchivo2(archivo *archivo , char *pathTemp)
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
// paths de prueba ubicacion de mi archivo /root/Documentos/ESCOM/SO/Practicas/Practica2/Practica2_8/archivos
// path donde se va copiar el archivo /root/Documentos/ESCOM/SO/Practicas/Practica2/Practica2_11
// /root/Documentos/ESCOM/SO/Practicas/Practica2/Practica2_11/hola
