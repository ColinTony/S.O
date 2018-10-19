/*TAD Arbol binario
ESTRUCTURAS DE DATOS 1CM7
ABRIL 2017
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TADArbolBin.h"


/*recibe<-árbol(A);
InitializeArbol (A)
Efecto: Recibe un árbol binario A y lo inicializa para su trabajo normal.
*/
void InitializeArbol(arbol_bin *A){
	*A = NULL;
	return;
}

/*recibe<-árbol(A);
DestroyArbol (A)
Efecto: Recibe un árbol binario A y lo libera completamente.
*/
void DestroyArbol(arbol_bin *A){
	if(*A == NULL)
		return;
	else
	{
		if((*A)->izq != NULL)
			DestroyArbol(&((*A)->izq));
		if((*A)->der != NULL)
			DestroyArbol(&((*A)->der));
		free(*A);
		return;
	}
}

/*recibe<-árbol(A); retorna -> posición
Root (A)
Efecto: Recibe un árbol binario A y retorna la posición de la raíz de A, si el árbol es vacío devuelve una posición nula.
*/
posicion Root(arbol_bin *A){
	return *A;
}


/*recibe<-árbol(A), posición(P); retorna -> posición
Parent(A,P)
Efecto: Recibe un árbol binario  A y una posición P, devuelve la posición de padre de p.
Requerimientos: El árbol binario A es no vacío y la posición P es una posición valida. Si P es la raíz se devuelve una posición nula.
*/
posicion Parent(arbol_bin *A, posicion p){
	posicion r = NULL;
	if(*A == NULL || *A == p)
		return NULL;
	else if ((*A)->izq == p || (*A)->der == p)
		return *A;
	else
	{
		r = Parent(&((*A)->izq), p);
		if(r == NULL)
			r = Parent(&((*A)->der), p);
		return r;
	}
}

/*recibe<-árbol(A), posición(P); retorna -> posición
RightSon(A,P)
Efecto: Recibe un árbol binario A y una posición P, devuelve la posición del hijo derecho de p.
Requerimientos: El árbol binario A es no vacío y la posición P es una posición valida. Si P no tiene hijo derecho devuelve una posición nula.
*/
posicion RightSon(arbol_bin *A, posicion P)
{
	posicion r = NULL;
	if(!NullNode(A, P))
		r = P -> der;

	return r;
}
/*recibe<-árbol(A), posición(P); retorna -> posición
LeftSon(A,P)
Efecto: Recibe un árbol binario A y una posición P, devuelve la posición del hijo izquierdo de p.
Requerimientos: El árbol A es no vacío y la posición P es una posición valida. Si P no tiene hijo izquierdo devuelve una posición nula.
*/
posicion LeftSon(arbol_bin *A, posicion P)
{
	posicion r = NULL;
	if(!NullNode(A, P))
		r = P -> izq;

	return r;
}


/*recibe<-árbol(A), elem (E); retorna -> posición
Search(A,E)
Efecto: Recibe un árbol binario A y un elem E, devuelve la posición del elem E en el árbol  A.
Requerimientos: El árbol binario A es no vacío y la posición P es una posición valida. Si E no es encontrado devuelve una posición nula.
*/
posicion Search(arbol_bin *A, elem e)
{

	posicion r = NULL;
	if(*A == NULL)
		return NULL;
	else if (memcmp(&((*A)->e),&e,sizeof(elem))==0)
		return *A;
	else
	{
		r = Search(&((*A)->izq), e);
		if(r == NULL)
			r = Search(&((*A)->der), e);
		return r;
	}

}

/*recibe<-árbol(A); retorna -> booleano
EmptyArbol(A)
Efecto: Recibe un árbol binario A y devuelve verdadero en caso de que el árbol A este vacío, devuelve falso en caso contrario.
*/
boolean EmptyArbol(arbol_bin *A)
{
	boolean r;
	if(*A == NULL)
		r = TRUE;
	else
		r = FALSE;

	return r;
}

/*recibe<-árbol(A), posición (P); retorna -> booleano
NullNode(A,P)
Efecto: Recibe un árbol binario A y una posición P, devuelve verdadero si la posición P del árbol A es nula o incorrecta y devuelve falso en caso contrario.
*/
boolean NullNode(arbol_bin *A, posicion p)
{
	boolean r;
	if(*A == NULL)
		return TRUE;
	else if (*A == p)
		return FALSE;

	else
	{
		r = NullNode(&((*A)->izq), p);
		if(r == TRUE)
			r = NullNode(&((*A)->der), p);
		return r;
	}
}

/*recibe<-árbol(A), posición (P); retorna -> elem
ReadNode(A,P)
Efecto: Recibe un árbol binario A y una posición P, devuelve el elem en la posición P del árbol A.
Requerimientos: El árbol A es no vacío y la posición P es una posición valida..
*/
elem ReadNode(arbol_bin *A, posicion p)
{
	elem r;

	if(!NullNode(A, p)){
		r = p->e;
	}
	else
	{
		printf("Error: ReadNode");
		exit(1);
	}

	return r;
}

/*recibe<-árbol(A), posición (P), elem E;
NewRightSon(A,P,E)
Efecto: Recibe un árbol binario A, una posición P y un elem E, se añade un nodoArbol que contenga E como hijo derecho del nodoArbol con posición P.
Requerimientos: El árbol binario A es no vacío y la posición P es una posición valida. Si el árbol A es vacío se agrega a un nodoArbol raíz con E. si P ya tiene un hijo derecho, se cancela la operación.
*/
void NewRightSon(arbol_bin *A, posicion p, elem e)
{
	if(EmptyArbol(A))
	{
		*A = malloc(sizeof(nodoArbol));
		(*A)->e = e;
		(*A)->izq = NULL;
		(*A)->der = NULL;
	}
	else if(!NullNode(A, p))
	{
		if(p->der != NULL){
			printf("Error: NewRightSon: ya existe");
			exit(1);
		}
		else
		{
			p->der = malloc(sizeof(nodoArbol));
			p->der->e = e;
			p->der->izq = NULL;
			p->der->der = NULL;
		}
	}else{
		printf("Error: NewRightSon");
		exit(1);
	}
	return;
}

/*
	recibe<-árbol(A), posición (P), elem E;
	NewLeftSon(A,P,E)
	Efecto: Recibe un árbol binario A, una posición P y un elem E, se añade un nodoArbol que contenga E como hijo izquierdo del nodoArbol con posición P.
	Requerimientos: El árbol binario A es no vacío y la posición P es una posición valida. Si el árbol A es vacío se agrega a un nodoArbol raíz con E; si P ya tiene un hijo Izquierdo, se cancela la operación.
*/
void NewLeftSon(arbol_bin *A, posicion p, elem e)
{
	if(EmptyArbol(A))
	{
		*A = malloc(sizeof(nodoArbol));
		(*A)->e = e;
		(*A)->izq = NULL;
		(*A)->der = NULL;
	}
	else if(!NullNode(A, p))
	{
		if(p->izq != NULL){
			printf("Error: NewLeftSon: ya existe");
			exit(1);
		}
		else
		{
			p->izq = malloc(sizeof(nodoArbol));
			p->izq->e = e;
			p->izq->izq = NULL;
			p->izq->der = NULL;
		}
	}else{
		printf("Error: NewLeftSon");
		exit(1);
	}
	return;
}

/*recibe<-árbol(A), posición (P);
DeleteRightSon(A,P)
Efecto: Recibe un árbol binario A y una posición se elimina al hijo derecho y todos sus descendientes del nodoArbol con posición P.
Requerimientos: El árbol A es no vacío y la posición P es una posición valida y tiene un hijo derecho.
*/
void DeleteRightSon(arbol_bin *A, posicion p)
{
	if(!NullNode(A, p))
	{
		DestroyArbol(&(p->der));
	}
	else
	{
		printf("Error: DeleteRightSon");
		exit(1);
	}
	return;
}

/*recibe<-árbol(A), posición (P);
DeleteLeftSon(A,P)
Efecto: Recibe un árbol binario A y una posición se elimina al hijo izquierdo y todos sus descendientes del nodoArbol con posición P.
Requerimientos: El árbol A es no vacío y la posición P es una posición valida y tiene un hijo izquierdo.
*/
void DeleteLeftSon(arbol_bin *A, posicion p)
{
	if(!NullNode(A, p))
	{
	DestroyArbol(&(p->izq));
	}
	else
	{
		printf("Error: DeleteLeftSon");
		exit(1);
	}
	return;
}


/*recibe<-árbol(A), posición (P);
DeleteNode(A,P)
Efecto: Recibe un árbol binario A y una posición P, se elimina al nodoArbol con posición  P  y todos sus descendientes.
Requerimientos: El árbol A es no vacío y la posición P es una posición valida.
*/
void DeleteNode(arbol_bin *A, posicion p)
{
	if(!NullNode(A, p))
	{
		DestroyArbol(&p);
	}
	else
	{
		printf("Error: Delete");
		exit(1);
	}
	return;
}

/*recibe<-árbol(A), posición (P), elem (E);
ReplaceNode(A,P)
Efecto: Recibe un árbol binario A, una posición P y un elem E, se remplaza a E del nodoArbol con posición P en A.
Requerimientos: El árbol binario A es no vacío y la posición P es una posición valida.
*/
void ReplaceNode(arbol_bin *A, posicion p, elem e)
{
	if(!NullNode(A, p))
	{
		p->e = e;
	}
	else
	{
		printf("Error: ReplaceNode");
		exit(1);
	}
	return;
}
