/*
	Libreria ? : DibujarLinux
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0
	DESCRIPCIÓN: Se declaran las funcinones para dibujar con caracteres y modificar
    el color de los mismos.
*/

#include <stdio.h>
#include <stdlib.h>
#include "DibujarLinux.h"

/*
*	Recibe : valores enteros donde este la posicion a imprimir x y y
*	Descripcion: mueve el cursor para despues imprimir en pantalla lo deseado.
*/
void gotoxy(int x , int y)
{
	printf("%c[%d;%df",0x1B,y,x);
    fflush(stdout);	
}

/*
*	Recibe in valor del color y la cadena a imprimir.
*	Descripcion : Imprime una cadena con el formado deseado.
*	Devuelve : Void
*/
void imprime(char formato[] , char cadena[])
{
	printf("%s %s %s \n",formato,cadena,END);
}

/*
* Recibe : Un valor para el formato de la impresion , la cadena a imprimir y posicion x y
* imprime una cadena con un formato deseado en una posicionn deseada.
* Descripcion imprime una cadena con un formato deseado en una posicion deseada
*/

void imprimeXY(char formato [] , char cadena[],int x , int y)
{
	gotoxy(x,y);
	imprime(formato,cadena);
}


/*
* void borrarPantalla()
* Recibe : NAda
* Descripcion borra la pantalla del sistema
*/
void borrarPantalla()
{
	system("clear");
}