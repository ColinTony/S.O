typedef struct archivo
{
  
  char nombre[30];      // nombre del archivo
  char contenido[100];  // contenido del archivo
  char path[1000];       // direccion del directorio del archivo
  int id;               // identificar el arcvhivo

}archivo;

int crearArchivo(archivo *archivo,char *pathTemp);    // creamos un archivo en una ruta especificada

int crearArchivoW(archivo *archivo,char *pathTemp);    // creamos un archivo en una ruta especificada
void entrarCrearDirectorio(char *pathTemp);           // Sirve para crear o entrar dentro de un directorio
void leerDirectorio(char *pathTemp);                  // esta funcion nos permitira leer los arvhivos uno a uno.
char *obtenerRuta(char *path,char *nombre);          // Obtenemos la ruta del archivo
int leerArchivoW(archivo *archivo);
/*
  el argumento “mode” se encarga de definir los permisos dentro del Sistema de Ficheros (de la manera de la que lo hacíamos con el comando “chmod”). La lista completa de sus posibles valores es esta:
  Indicador   Valor   Descripción
  
  S_IROTH   0000  Activar el bit de lectura para todo los usuarios.
  S_IWOTH   0001  Activar el bit de escritura para todo los usuarios.
  S_IXOTH   0002  Activar el bit de ejecución para todo los usuarios.
  S_IRGRP   0010  Activar el bit de lectura para todo los usuarios pertenecientes al grupo.
  S_IRGRP   0020  Activar el bit de escritura para todo los usuarios pertenecientes al grupo.
  S_IRGRP   0040  Activar el bit de ejecución para todo los usuarios pertenecientes al grupo.
  S_IRUSR   0100  Activar el bit de lectura para el propietario.
  S_IWUSR   0200  Activar el bit de escritura para el propietario.
  S_IXUSR   0400  Activar el bit de ejecución para el propietario.
  S_ISVTX   1000  Activa el “sticky bit” en el fichero.
  S_ISGID   2000  Activa el bit de SUID en el fichero.
  S_ISUID   4000  Activa el bit de SGID en el fichero.
  S_IRWXU   S_IRUSR + S_IWUSR + S_IXUSR   Activar el bit de lectura, escritura y ejecución para el propietario.
  S_IRWXG   S_IRGRP + S_IWGRP + S_IXGRP   Activar el bit de lectura, escritura y ejecución para todo los usuarios pertenecientes al grupo.
  S_IRWXO   S_IROTH + S_IWOTH + S_IXOTH   Activar el bit de lectura, escritura y ejecución para tt odo los usuarios.

*/
/*
  l funcionamiento de open() es el siguiente: al ser llamada intenta abrir el fichero indicado en la cadena “pathname” con el acceso que indica el parámetro “flags”. Estos “flags” indican si queremos abrir el fichero para lectura, para escritura, etc. La siguiente tabla especifica los valores que puede tomar este parámetro:
  Indicador   Valor   Descripción
  O_RDONLY  0000  El fichero se abre sólo para lectura.
  O_WRONLY  0001  El fichero se abre sólo para escritura.
  O_RDWR  0002  El fichero se abre para lectura y escritura.
  O_RANDOM  0010  El fichero se abre para ser accedido de forma aleatoria (típico de discos).
  O_SEQUENTIAL  0020  El fichero se abre para ser accedido de forma secuencial (típico de cintas).
  O_TEMPORARY   0040  El fichero es de carácter temporal.
  O_CREAT   0100  El fichero deberá ser creado si no existía previamente.
  O_EXCL  0200  Provoca que la llamada a open falle si se especifica la opción O_CREAT y el fichero ya existía.
  O_NOCTTY  0400  Ei el fichero es un dispositivo de terminal (TTY), no se convertirá en la terminal de control de proceso (CTTY).
  O_TRUNC   1000  Fija el tamaño del fichero a cero bytes.
  O_APPEND  2000  El apuntador de escritura se situa al final del fichero, se escribirán al final los nuevos datos.
  O_NONBLOCK  4000  La apertura del fichero será no bloqueante. Es equivalente a O_NDELAY.
  O_SYNC  10000   Fuerza a que todas las escrituras en el fichero se terminen antes de que se retorne de la llamada al sistema. Es equivalente a O_FSYNC.
  O_ASYNC   20000   Las escrituras en el fichero pueden realizarse de manera asíncrona.
  O_DIRECT  40000   El acceso a disco se producirá de forma directa.
  O_LARGEFILE   100000  Utilizado sólo para ficheros extremadamente grandes.
  O_DIRECTORY   200000  El fichero debe ser un directorio.
  O_NOFOLLOW  400000  Fuerza a no seguir los enlaces simbólicos. Útil en entornos críticos en cuanto a seguridad.

  Tabla: Lista de los posibles valores del argumento “flags”.
*/