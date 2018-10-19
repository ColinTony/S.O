/*
	AUTOR : Colin Heredia Luis Antonio
	VERSIÓN: 1.0

	DESCRIPCIÓN: Evaluando toda la expresion con arbol binario.
*/

// Esta estructura nos ayudara a encontrar los numeros completos dentro de una cadena
typedef struct operando
{
	char opera[100000]; // no es dinamico tiene un valor maximo.

}operando;

void llenarArbol(arbol_bin *A); // Llenaremos el arbol binario
int evaluarArbol(arbol_bin *A); // Funcion para evaluar el arbol con el recorrido ¿postOrden?