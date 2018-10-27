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
#include "Operaciones.h"


int main(int argc, char const *argv[])
{
	
	// matrices que se van a operar.
	matrices matrixs;

	// Llenamos la matriz 1 y 2.
	llenarMatriz(&matrixs);
	// imprime la primer matriz

	printf("\n\t\t\t\t------------------------------ MATRIZ 1 ---------------------------\n");
	imprimeMatriz(matrixs.matriz);
	printf("\n\t\t\t\t------------------------------ MATRIZ 2 ---------------------------\n");
	imprimeMatriz(matrixs.matriz2);

	printf("\n\n\n\t\t\t\t \e[0;40m-----------------------------SUMA ---------------------------\e[00m \n\n");
	suma(&matrixs);
	imprimeMatriz(matrixs.matrizR);


	printf("\n\n\n \t\t\t\t \e[0;40m-----------------------------RESTA ---------------------------\e[00m \n\n");
	resta(&matrixs);
	imprimeMatriz(matrixs.matrizR);

	printf("\n\n\n \t\t\t\t \e[0;40m-----------------------------MULTIPLICACION---------------------------\e[00m \n\n");
	mulp(&matrixs);
	imprimeMatriz(matrixs.matrizR);

	transpuesta(&matrixs);
	printf("\n\n\n \t\t\t\t \e[0;40m-----------------------------TRANSPUESTA MATRIZ 1---------------------------\e[00m \n\n");
	imprimeMatriz(matrixs.matrizTrans);
	printf("\n\n\n\n\n");
	
	printf("\n\n\n \t\t\t\t \e[0;40m-----------------------------TRANSPUESTA MATRIZ 2---------------------------\e[00m \n\n");
	imprimeMatriz(matrixs.matrizTrans2);
	printf("\n\n\n\n\n");
	
	return 0;
}