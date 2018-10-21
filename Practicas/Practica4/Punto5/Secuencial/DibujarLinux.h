
/*
	Libreria ? : Dibujar en linux
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0
	DESCRIPCIÓN: Se declaran las funcinones para dibujar con caracteres y modificar
    el color de los mismos. Tambien se crea la funcion para mover el cursor dentro de la terminal
*/
	/*
	Colores de letra (foreground)
	------------------------------

	Combinación	Color
	========================
	0;30			 Negro
	0;31			 Rojo
	0;32			 Verde
	0;33			 Marrón
	0;34			 Azul
	0;35			 Púrpura
	0;36			 Cian
	0;37			 Gris claro
	1;30			 Gris oscuro
	1;31			 Rojo claro
	1;32			 Verde claro
	1;33			 Amarillo
	1;34			 Azul claro
	1;35			 Púrpura claro
	1;36			 Cian claro
	1;37			 Blanco

	Colores de fondo (background)
	------------------------------

	Combinación	Color
	========================
	40			   Negro
	41			   Rojo
	42			   Verde
	43			   Marrón
	44			   Azul
	45			   Púrpura
	46			   Turquesa
	47			   Gris

	Efectos de carácter
	-------------------------------

	Combinación	Estilo
	========================
	0;4			  Subrayado
	0;5			  Titilante (blink)(puede que no funcione)
	0;1			  Negrita
	0;8			  Transparente (?)

	Para colorear sólo hay que poner printf (o cout) con la siguiente cadena (reemplazando XX por una de las combinaciones de las tablas de abajo):
	\e[XXm EJemplo \e[00m

*/

#define	NEGRO	"\e[0;30m"
#define	ROJO 	"\e[0;31m"
#define	VERDE 	"\e[0;32m"
#define	MARRON 	"\e[0;33m"
#define	AZUL 	"\e[0;34m"
#define	PURPURA "\e[0;35m"
#define	CIAN 	"\e[0:36m"
#define	GRIS_CLARO	"\e[0;37m"
#define	GRIS_OSCURO	"\e[1;30m"
#define	ROJO_CLARO 	"\e[1;31m"
#define	VERDE_CLARO	"\e[1;32m"
#define	AMARILLO 	"\e[1;33m"
#define	AZUL_CLARO 	"\e[1;34m"
#define	PURPURA_CLARO "\e[1;35m"
#define	CIAN_CLARO 	"\e[1;36m"
#define	BLANCO 		"\e[1;37m"

/*
	Efectos de carácter
-------------------------------
	Combinación	Estilo
	========================
*/
#define	SUBRAYADO 	"\e[0;4m"
#define	NEGRITA  	"\e[0;1m"
#define	PARPADEA	"\e[0;5m"

// Cerrar el formato
#define END "\e[00m"

// COMBINACION DE COLOR Y PARPADEANDO No todos los colores son compatibles
#define ROJO_PAR 			"\e[0;5m\e[1;31m"
#define NEGRO_PAR 			"\e[0;5m\e[0;30m"
#define	VERDE_PAR 			"\e[0;5m\e[0;32m"
#define	MARRON_PAR 			"\e[0;5m\e[0;33m"
#define	AZUL_PAR 			"\e[0;5m\e[0;34m"
#define	PURPURA_PAR 		"\e[0;5m\e[0;35m"
#define	CIAN_PAR 			"\e[0;5m\e[0:36m"
#define	GRIS_CLARO_PAR		"\e[0;5m\e[0;37m"
#define	GRIS_OSCURO_PAR		"\e[0;5m\e[1;30m"
#define	ROJO_CLARO_PAR 		"\e[0;5m\e[1;31m"
#define	VERDE_CLARO_PAR		"\e[0;5m\e[1;32m"
#define	AMARILLO_PAR 		"\e[0;5m\e[1;33m"
#define	AZUL_CLARO_PAR 		"\e[0;5m\e[1;34m"
#define	PURPURA_CLARO_PAR 	"\e[0;5m\e[1;35m"
#define	CIAN_CLARO_PAR	 	"\e[0;5m\e[1;36m"
#define	BLANCO_PAR 			"\e[0;5m\e[1;37m"

// COMBINACION DE COLOR Y SUBRAYADO
#define ROJO_SUB 			"\e[0;4m\e[1;31m"
#define NEGRO_SUB 			"\e[0;4m\e[0;30m"
#define	VERDE_SUB 			"\e[0;4m\e[0;32m"
#define	MARRON_SUB 			"\e[0;4m\e[0;33m"
#define	AZUL_SUB 			"\e[0;4m\e[0;34m"
#define	PURPURA_SUB 		"\e[0;4m\e[0;35m"
#define	CIAN_SUB 			"\e[0;4m\e[0:36m"
#define	GRIS_CLARO_SUB		"\e[0;4m\e[0;37m"
#define	GRIS_OSCURO_SUB		"\e[0;4m\e[1;30m"
#define	ROJO_CLARO_SUB 		"\e[0;4m\e[1;31m"
#define	VERDE_CLARO_SUB		"\e[0;4m\e[1;32m"
#define	AMARILLO_SUB 		"\e[0;4m\e[1;33m"
#define	AZUL_CLARO_SUB 		"\e[0;4m\e[1;34m"
#define	PURPURA_CLARO_SUB 	"\e[0;4m\e[1;35m"
#define	CIAN_CLARO_SUB	 	"\e[0;4m\e[1;36m"
#define	BLANCO_SUB 			"\e[0;4m\e[1;37m"

// COMBINACION DE COLOR Y NEGRITA
#define ROJO_NEG 			"\e[0;1m\e[1;31m"
#define NEGRO_NEG 			"\e[0;1m\e[0;30m"
#define	VERDE_NEG 			"\e[0;1m\e[0;32m"
#define	MARRON_NEG 			"\e[0;1m\e[0;33m"
#define	AZUL_NEG 			"\e[0;1m\e[0;34m"
#define	PURPURA_NEG 		"\e[0;1m\e[0;35m"
#define	CIAN_NEG 			"\e[0;1m\e[0:36m"
#define	GRIS_CLARO_NEG		"\e[0;1m\e[0;37m"
#define	GRIS_OSCURO_NEG		"\e[0;1m\e[1;30m"
#define	ROJO_CLARO_NEG 		"\e[0;1m\e[1;31m"
#define	VERDE_CLARO_NEG		"\e[0;1m\e[1;32m"
#define	AMARILLO_NEG 		"\e[0;1m\e[1;33m"
#define	AZUL_CLARO_NEG 		"\e[0;1m\e[1;34m"
#define	PURPURA_CLARO_NEG 	"\e[0;1m\e[1;35m"
#define	CIAN_CLARO_NEG	 	"\e[0;1m\e[1;36m"
#define	BLANCO_NEG 			"\e[0;1m\e[1;37m"


void imprime(char formato[] , char cadena[]);        					// funcion para cambiar de color el texto que vayamos a imprimir en pantalla y la cadena
void imprimeXY(char formato [] , char cadena[],int x , int y);        	// imprime una cadena con un formato deseado en una posicionn deseada.
void borrarPantalla();																// borra la pantalla
void gotoxy(int x , int y);															// Funcion para mover el cursor en la pantalla

