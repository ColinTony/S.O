/*
	AUTOR : Colin Heredia Luis Antonio
	VERSIÓN: 1.0

	DESCRIPCIÓN: Evaluando toda la expresion con arbol binario.
*/

#include <stdio.h>
#include <stdlib.h>
#include "TADArbolBin.h"
#include "ValidaExp.h"
#include "Evaluador.h"

/*
	void llenarArbol(arbol_bin *A , expresion *exp);
	Descripción: Recibe un arbol lo inicializa , revisa la expresion y llena el arbol
	 para su posterior evaluacion.
	Recibe:  expresion *exp apuntador hacia la variable de su cadena y un arbol_binario ..
	Observaciones : El arbol que se ingrese no tendra que estar inicializado ya que lo hace
	esta funcion , expresion no debe estar vacia.
*/
/*

/*
	Descripcion del algotimo
	->Si el símbolo actual es un '(', agregar un nodo nuevo como hijo izquierdo del nodo actual y descender al hijo izquierdo.
	->Si el símbolo actual está en la lista ['+', '-', '/', '*'], asignar al valor raíz del nodo actual el operador representado por el símbolo actual.
	 	Agregar un nuevo nodo como hijo derecho del nodo actual y descender al hijo derecho.
	->Si el símbolo actual es un número, asignar dicho número al valor raíz del nodo actual y regresar al padre.
	->Si el símbolo actual es un ')', ir al padre del nodo actual.
*/

// Llenaremos el arbol binario
void llenarArbol(arbol_bin *A)
{
	// Revisando la expresion
	expresion exp; // nuestra expresion 
  	createExp(&exp); // creamos expresion

  	// algotirm para llenar el arbol binario
  	int i; // contador
	int j=0;// contador aux
	int valor=0; // aqui se guarda el valor obtenido de la cadena
	int k=0; // constador aux para los operandos
	int buscador; // buscador
	operando operandos[tamCadena(&exp)]; // arreglo de operandos
	
	// inicializamos el arbol binario
	InitializeArbol(A);
	posicion p; // posicion para consultar sera la raiz
	

	// Arbol raiz 
	elem e1;
	NewLeftSon(A,p,e1);
	p = Root(A);

	if(exp.cadena != NULL)
	{
		// no debe estar vacia la expresion
		//Recorrer cada caracter de la cadena 
		for(i=0;i<tamCadena(&exp);i++)
		{
			if (!(exp.cadena[i]>=48)&&(exp.cadena[i]<=57))
			{
				switch(exp.cadena[i])
				{
					case '(' :
						NewLeftSon(A,p,e1); // crear nuevo hijo izquierdo
						// nos movemos a la posicion del hijo izquierdo
						p = LeftSon(A,p);
					break;

					case ')' : 
						// ir al padre del valor actual
						p = Parent(A,p);
					break;

					case '+' :

						p->e.operador='+';
						// creamos un hijo derecho y nos movemos al hijo creado
						NewRightSon(A,p,e1);
						p = RightSon(A , p);

					break;

					case '-':
						p->e.operador='-';
						// creamos un hijo derecho y nos movemos al hijo creado
						NewRightSon(A,p,e1);
						p = RightSon(A , p);
					break;

					case '*':
						// sacamos la raiz del nodo actual
						p->e.operador='*';
						// creamos un hijo derecho y nos movemos al hijo creado
						NewRightSon(A,p,e1);
						p = RightSon(A , p);
					break;

					case '/':
						// sacamos la raiz del nodo actual
						p->e.operador='/';
						// creamos un hijo derecho y nos movemos al hijo creado
						NewRightSon(A,p,e1);
						p = RightSon(A , p);

					break;

					default:
					break;
					}// switch fin.
			}// fin if
			else
			{
				// en dado caso de encontrar un numero revisaremos que numero es y con atoi de la 
				// libreria stdlib convertiremos la cadena a entero.
				buscador = i; // la posicion del numero
				elem e1; // elemento al modificar
				while((exp.cadena[buscador]>=48)&&(exp.cadena[buscador]<=57))
				{
					operandos[j].opera[k] = exp.cadena[buscador]; // vamos agregando los numeros
					buscador++; // el buscador se aumenta si el siguiente caracrer es un numero entonces es
								// es parte del numero anteriormente agregado se le añade al operando.
					k++;
					operandos[j].opera[k+1] = '\0';
				}
				
				printf("%i y caracter anterior %c \n",i , exp.cadena[i]);
				j++;
				k=0;
				i = buscador;
				// Aqui el caso del algotimo  como el numero actual es un numero

				//e1.operando = atoi(opearandos[j]);
				valor = atoi(operandos[j].opera);
				p->e.operando = valor;
				p = Parent(A,p);
				
			}
			
			printf("%i y caracter anterior %c \n",i , exp.cadena[i]);
		} // fin for
		// verificando si los guardo bien printf("\n %s ", operandos[3].opera);
	}else
		printf("\n %s", "La cadena esta vacia");
}

// Funcion para evaluar el arbol con el recorrido ¿postOrden?
int evaluarArbol(arbol_bin *A)
{
	
} 