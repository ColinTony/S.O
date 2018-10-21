/*
	Libreria ? : Operaciones de matrices
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DibujarLinux.h"
#include "Operaciones.h"

/*
*	void getRand()
*	Descripcion : Genera un valor random entre los numeros 0 al 20
*	Recibe : void
*	Devuelve : un valor entero int
*/
int getRand()
{
	int numero;
	numero = rand() % LIMITRAND; 	// genera un numero del 1 al 50
	// asignamos el valor a la matriz
	
	return numero;
}

/*
*	void llenarMatriz (matrices *matrix)
*	Descripcion : LLena la matriz con valores enteros entre 1 y 10
*	Recibe : una matriz bidemensional nxn
*/

void llenarMatriz(matrices *matrix)
{
	int i,j; // contadores
	int numero;
	srand(time(NULL));
	for(i = 0; i<MAX_MATRIZ; i++)
	{
		for(j = 0; j<MAX_MATRIZ; j++)
		{
			// asignamos el valor a la matriz
			matrix->matriz[i][j] = getRand();
			matrix->matriz2[i][j] = getRand();
		}
	}
}


/*
* void imprimeMatriz(int matriz[][] , int x , int y)
* Descripcion : Imprime una matriz  nxn
* Recibe : un entero para saber el valor de n tam de la matriz
* una matrz bidemensional de nxn , un punto en el cual se va empezar a imprimir
* la matriz
*/

void imprimeMatriz(int matriz[MAX_MATRIZ][MAX_MATRIZ] ,int x , int y)
{
	int i;  // contador
	int j;	// contador 2
	for(i = 0; i<MAX_MATRIZ; i++)
	{
		// movemos el cursor en cada linea
		gotoxy(x,y);
		if(i >= 1)
		{
			y++;
			gotoxy(x,y);
		}

		for(j = 0; j<MAX_MATRIZ; j++)
		{
			// checamos si es negativo
			if(matriz[i][j] < 0)
			{
				// sabemos que el menos se toma como un caracter mas
				if(matriz[i][j] > -10)
					printf("%d    ",matriz[i][j]); // el numero contiene dos caracteres espaciado de 2 y posiciones de 4else
				else{
					if(matriz[i][j] > -99 ) // tiene dos digitos y un caracter de negativo
						printf("%d   ",matriz[i][j]);
					else
						printf("%d   ",matriz[i][j]);
				}
			}else
			{
				// positivo
				if(matriz[i][j] < 10)
					printf(" %d    ",matriz[i][j]); // solo es in digito
				else
					if(matriz[i][j] < 99)
						printf(" %d   ", matriz[i][j]); // son dos digitos
					else
						printf("%d   ", matriz[i][j]); // son 3 digitos
			}
		}
	}
}

/*
* void imprimeMatrizT(int matriz[][] , int x , int y)
* Descripcion : Imprime la matriz transpuesta de una una matriz  nxn
* Recibe : un entero para saber el valor de n tam de la matriz
* una matrz bidemensional de nxn , un punto en el cual se va empezar a imprimir
* la matriz
*/


void imprimeMatrizT(int matriz[MAX_MATRIZ][MAX_MATRIZ] ,int x , int y)
{
	int i;  // contador
	int j;	// contador 2
	for(i = 0; i<MAX_MATRIZ; i++)
	{
		// movemos el cursor en cada linea
		gotoxy(x,y);
		if(i >= 1)
		{
			y++;
			gotoxy(x,y);
		}

		for(j = 0; j<MAX_MATRIZ; j++)
		{
			// checamos si es negativo
			if(matriz[j][i] < 0)
			{
				// sabemos que el menos se toma como un caracter mas
				if(matriz[j][i] > -10)
					printf("%d    ",matriz[j][i]); // el numero contiene dos caracteres espaciado de 2 y posiciones de 4else
				else{
					if(matriz[j][i] > -99 ) // tiene dos digitos y un caracter de negativo
						printf("%d   ",matriz[j][i]);
					else
						printf("%d   ",matriz[j][i]);
				}
			}else
			{
				// positivo
				if(matriz[j][i] < 10)
					printf(" %d    ",matriz[j][i]); // solo es in digito
				else
					if(matriz[j][i] < 99)
						printf(" %d   ", matriz[j][i]); // son dos digitos
					else
						printf("%d   ", matriz[j][i]); // son 3 digitos
			}
		}
	}
}

/*
* void suma(matrices *matrix)
* Descripcion : Suma de las matrices 1 y 2 , el resultado lo pone en matrizR
* Recibe : matrices que contiene las matrices que se sumaran y la matrizR
*/
void suma(matrices *matrix)
{
	int i,j;
	for(i = 0; i<MAX_MATRIZ; i++)
	{
		for(j=0; j<MAX_MATRIZ; j++)
			matrix->matrizR[i][j] = matrix->matriz[i][j] + matrix->matriz2[i][j]; 
	}
}


/*
* void resta(matrices *matrix)
* Descripcion : Resta de las matrices 1 y 2 , el resultado lo pone en matrizR
* Recibe : matrices que contiene las matrices que se restaran y la matrizR
* nota se realiza matriz1 - matriz 2
*/
void resta(matrices *matrix)
{
	int i,j;
	for(i = 0; i<MAX_MATRIZ; i++)
	{
		for(j=0; j<MAX_MATRIZ; j++)
			matrix->matrizR[i][j] = matrix->matriz[i][j] - matrix->matriz2[i][j]; 
	}
}

/*
* void mulp(matrices *matrix)
* Descripcion : Multiplicacion de matrices
* Recibe : matrices que contiene las matrices que se multiplicaran y la matrizR
*/
void mulp(matrices *matrix)
{
	int i,j,k;

	for ( k = 0; k < MAX_MATRIZ; k++)
	{ // abre primer ciclo for
		for ( j = 0; j < MAX_MATRIZ; j++)
		{ // abre el segundo ciclo for

			for ( i = 0; i < MAX_MATRIZ; i++ )
				matrix->matrizR[k][j] += matrix->matriz[k][i]*matrix->matriz2[i][j];

		} // Cierra el segundo ciclo for
	} // cierra primer ciclo for
}

/*
* void resetResult(matrices *matrix)
* Descripcion :	pone los valores de la matriz resultante en cero
* Recibe : matriz nxn
*/
void resetResult(matrices *matrix)
{
	int i,j;
	for(i = 0; i<MAX_MATRIZ; i++)
	{
		for (j=0; j<MAX_MATRIZ; j++)
		{
			matrix->matrizR [i][j] = 0;
		}
	}

	// FIN DEL ALGORITMO PRINCIPAL
}
