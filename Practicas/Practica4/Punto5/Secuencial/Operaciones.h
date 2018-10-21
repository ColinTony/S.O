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
#define LIMITRAND 10

// estructura donde mantendre las matrices
typedef struct matrices
{
	int matriz [MAX_MATRIZ][MAX_MATRIZ];	// matriz 1 
	int matriz2 [MAX_MATRIZ][MAX_MATRIZ]; 	// matriz 2 
	int matrizR [MAX_MATRIZ][MAX_MATRIZ];	// matriz Resultante para la suma , resta , multuplicacion
	int matrizInv [MAX_MATRIZ][MAX_MATRIZ]	 // matriz inversa
	int matrizInv2 [MAX_MATRIZ][MAX_MATRIZ]	// matriz inversa

	
}matrices;
//DEFINICIONES DE TIPOS DE DATO

typedef unsigned char boolean; //Definir un boolean (Se modela con un "char")

void llenarMatriz(matrices *matrix);																						// llenar una matriz con valores aleatorios del 1 al MAX_MATRIZ
void imprimeMatriz(int matriz[MAX_MATRIZ][MAX_MATRIZ] ,int x , int y);														// funcion para imprimir la mtriz
void imprimeMatrizT(int matriz[MAX_MATRIZ][MAX_MATRIZ],int x , int y);														// funcion apra imprimir la matriz transpuesta
void suma(matrices *matrix);																								// funcino para la suma de matrices nxn , el resultado se guarada en matrizR
void resta(matrices *matrix);																								// funcion para la resta de matrices, la matriz resultante se pasa en la matriz R
void mulp(matrices *matrix);																								// funcion para la mulp de matrices, la matriz resultante se pasa en la matriz R

void transpuesta(matrices *matrix);																							// funcion para la transpuesta de las matrices 1 y matriz 2
void inversa (int matriz[MAX_MATRIZ][MAX_MATRIZ] , int *matrizR[MAX_MATRIZ][MAX_MATRIZ]);									// funcion para obtener la matriz inversa , se va guardar la matriz transpuesta en matrizT y matrzT2
int getRand();																												// regresa un valor entero generado aleatoriamente
void resetResult(matrices *matrix);