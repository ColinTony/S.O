/*
	Libreria ? : Operaciones de matrices nxn
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0
	DESCRIPCIÓN: Se declaran las funcinones para dibujar con caracteres y modificar
    el color de los mismos.
*/


//DEFINICIONES DE CONSTANTES
#define TRUE	1
#define FALSE	0
#define MAX_MATRIZ  10

// estructura donde mantendre las matrices
typedef struct matrices
{
	int matriz [MAX_MATRIZ][MAX_MATRIZ];
	int matriz2 [MAX_MATRIZ][MAX_MATRIZ];
	int matrizR [MAX_MATRIZ][MAX_MATRIZ];

}matrices;
//DEFINICIONES DE TIPOS DE DATO

typedef unsigned char boolean; //Definir un boolean (Se modela con un "char")

void llenarMatriz(matrices *matrix);																						// llenar una matriz con valores aleatorios del 1 al MAX_MATRIZ
void imprimeMatriz(int matrices[MAX_MATRIZ][MAX_MATRIZ] ,int x , int y);													// funcion para imprimir la mtriz
void suma(matrices *matrix);																								// funcino para la suma de matrices nxn , el resultado se guarada en matrizR
void resta(matrices *matrix);																								// funcion para la resta de matrices, la matriz resultante se pasa en la matriz R
void mulp(matrices *matrix);																								// funcion para la resta de matrices, la matriz resultante se pasa en la matriz R

void transpuesta(int matriz[MAX_MATRIZ][MAX_MATRIZ] , int *matrizR[MAX_MATRIZ][MAX_MATRIZ]);								// funcion para la resta de matrices, la matriz resultante se pasa en la matriz R
void inversa (int matriz[MAX_MATRIZ][MAX_MATRIZ] , int *matrizR[MAX_MATRIZ][MAX_MATRIZ]);									// funcion para la resta de matrices, la matriz resultante se pasa en la matriz R
int getRand();																											// regresa un valor entero generado aleatoriamente