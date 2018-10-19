/*
* @autor : Equipo SistemasOperativos
* @version: 1.0

* Realice un programa que evalue cualquier expresion areitmetica delimitada completamente con parentesis balanceados
  (por ejemplo, entrada (((5-2)+4)*10). Compile y ejecute su programa

  Compilacion : Ejecutar el .bat si estas en windows, si no, linea de comandos gcc ExpresionArbol.c TADarbolBin.c  
*/

#include <stdio.h>
#include "TADPilaDin.h"
#include "TADArbolBin.h"
#include "Evaluador.h"

int main(int argc, char const *argv[])
{
	// Creamos el arbol
	arbol_bin A;
	// LLenamos el arbol , esta funcion se inicializa el arbol.
  	llenarArbol(&A);

  return 0;
}