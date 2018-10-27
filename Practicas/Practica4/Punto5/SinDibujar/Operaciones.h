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
	int matrizTrans[MAX_MATRIZ][MAX_MATRIZ]; // matriz transpuesta
	int matrizTrans2[MAX_MATRIZ][MAX_MATRIZ]; // matriz transpuesta de la matriz 2

	// matrices inversas	
	float matrizInv[MAX_MATRIZ][MAX_MATRIZ];
	float matrizInv2[MAX_MATRIZ][MAX_MATRIZ];
	float tempDet[MAX_MATRIZ][MAX_MATRIZ];



}matrices;
//DEFINICIONES DE TIPOS DE DATO

typedef unsigned char boolean; //Definir un boolean (Se modela con un "char")

void llenarMatriz(matrices *matrix);																						// llenar una matriz con valores aleatorios del 1 al MAX_MATRIZ
void imprimeMatriz(int matriz[MAX_MATRIZ][MAX_MATRIZ] );																	// funcion para imprimir la mtriz
// Operaciones basicas
void suma(matrices *matrix);																								// funcino para la suma de matrices nxn , el resultado se guarada en matrizR
void resta(matrices *matrix);																								// funcion para la resta de matrices, la matriz resultante se pasa en la matriz R
void mulp(matrices *matrix);																								// funcion para la mulp de matrices, la matriz resultante se pasa en la matriz R
void transpuesta(matrices *matrix);																							// funcion para la transpuesta de las matrices 1 y matriz 2

// otras funciones necesarias
int getRand();																												// regresa un valor entero generado aleatoriamente
void resetResult(matrices *matrix);

// funciones para obtener la matriz inversa.
void matrizInv(matrices *matrix);																							// Funcion para obtener la matrix					
float det(matrices *matrix);																								// funcion para obtener el determinante
void cof(matrices *matrix);