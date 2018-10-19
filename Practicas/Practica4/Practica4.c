/*
* @autor : Equipo SistemasOperativos
* @version: 1.0
*
* Programe una aplicacion sin la creacion de procesos , es decir de forma secuencial que realice.
* suma de dos matrices 10 x 10 elementos tipo entero, resta sobre esas mismas matrices
* transpuesta de la matriz matrices inversas.
* cada uno escribira un archivo de resuktados de la operacion que realizo.
* El ultimo proceso leera los resultados y los mostrara en pantalla cada uno de ellos.

*  Compilacion : Ejecutar el .bat si estas en windows , ejecutar el comando en la terminal

*/

#include <stdio.h>
#include <stdlib.h>
#include "DibujarLinux.h"
#include "Operaciones.h"


int main(int argc, char const *argv[])
{
	borrarPantalla();
	imprimeXY(AMARILLO_NEG,"------------ ADMINISTRADOR DE PROCESOS EN LINUX (ejercicio 5 secuencial)----------",50,0);
	
	// matrices que se van a operar.
	matrices matrixs;

	// Llenamos la matriz 1 y 2.
	llenarMatriz(&matrixs);
	// imprime la primer matriz
	imprimeXY(CIAN_CLARO_SUB,"----------------------- MATRIZ 1 --------------------------",3,3);
	imprimeMatriz(matrixs.matriz, 5,5);

	// imprime la segunda matriz
	imprimeXY(CIAN_CLARO_SUB,"----------------------- MATRIZ 2 --------------------------",75,3);
	imprimeMatriz(matrixs.matriz2, 77,5);
	
	imprimeXY(AMARILLO_SUB,"----------------------- OPERACIONES --------------------------",50,16);
	
	// -------------------------------------------------SUMA ------------------------------------
	// imprime la primer matriz
	imprimeXY(CIAN_CLARO_SUB,"----------------------- MATRIZ 1 --------------------------",3,18);
	imprimeMatriz(matrixs.matriz, 5,20);
	// operandor
	imprimeXY(BLANCO_PAR," SUMA (+) ",63,24);
	// imprime la segunda matriz
	imprimeXY(CIAN_CLARO_SUB,"----------------------- MATRIZ 2 --------------------------",75,18);
	imprimeMatriz(matrixs.matriz2, 77,20);
	// igual
	imprimeXY(BLANCO_PAR," IGUAL (=) ",135,24);
	
	// sumamos matrices
	suma(&matrixs);
	// matriz resutladro la imprimimos
	imprimeXY(ROJO_SUB,"----------------- MATRIZ RESULTANTE ------------------------",150,18);
	imprimeMatriz(matrixs.matrizR, 150,20);

	// ----------------------------------------------RESTA--------------------------------------
	
	// imprime la primer matriz
	imprimeXY(CIAN_CLARO_SUB,"----------------------- MATRIZ 1 --------------------------",3,33);
	imprimeMatriz(matrixs.matriz, 5,35);
	// operandor
	imprimeXY(BLANCO_PAR," RESTA (-) ",63,39);
	// imprime la segunda matriz
	imprimeXY(CIAN_CLARO_SUB,"----------------------- MATRIZ 2 --------------------------",75,33);
	imprimeMatriz(matrixs.matriz2, 77,35);
	// igual
	imprimeXY(BLANCO_PAR," IGUAL (=) ",135,24);
	
	// sumamos matrices
	resta(&matrixs);
	// matriz resutladro la imprimimos
	imprimeXY(ROJO_SUB,"----------------- MATRIZ RESULTANTE ------------------------",150,33);
	imprimeMatriz(matrixs.matrizR, 150,35);


	printf("\n");
	return 0;
}