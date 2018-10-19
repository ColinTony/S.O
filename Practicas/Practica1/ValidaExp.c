/*
	LIBRERIA: Validador de la expresion algebraica
	AUTOR : Colin Heredia Luis Antonio
	VERSIÓN: 1.0

	DESCRIPCIÓN: libreria para validar la expresion algebraica 	de manera correcta.
*/

	//LIBRERAS
#include <stdio.h>
#include <string.h> //Para usar strlen()
#include <stdlib.h> // para exit
#include "ValidaExp.h"
#include "TADPilaDin.h"

	/*
		void  createExp(expresion *exp);
		Descripción: Inicia la expresion dada por el usuario.
		Recibe:  expresion *exp apuntador hacia la variable de su cadena..
		Observaciones : Si el usiario intrpduce letras minusculas , se transforman a mayusculas
		Devuelve: Void. 
	*/

	void createExp(expresion *exp) // Crea la expresion a evaluar
	{
		printf("\n EAVALUACION DE EXPRESIONES ARITMETICAS CON ARBOL BINARIO \n INTRODUZCA LA EXPRESION A EVALUAR: ");
		scanf("%s", exp->cadena); // la cadena puesta por el usuario la añadimos a la cadena de nuestra expresion
		// strupr(exp->cadena); // pasamos todo a Mayusculas no puede funcionanr el Linux
		isCorrect(exp); // comprobamos si esta correcta
		printf("\n");
		
	}

	/*
		boolean isCorrect (expresion *exp);
		Descripción: Evalua la expresion para saber si es correcta, debe cumplir 
		con los criterios algebraicos de las expresiones.
		Recibe:  expresion *exp la direccion de la cadena de la expresion.
		Devuelve: TRUE si es corecta , FALSE si no lo es. 
	*/

	boolean isCorrect(expresion *exp)
	{
		boolean isCorrect=FALSE;

		if(verificaParentesis(exp)) // si ambas son correctas entonces la expresion es correcta
		{
			isCorrect = TRUE; // es correcta la expresion
			//printf("Expresion correcta \n");
		}else
		{
			//printf("Error en los parentesis \n");
			isCorrect = FALSE; // es incorrecta la expresion
		}
		
		return  isCorrect;
	} 	// Fin; Devolvera si la expresion esta correctamente escrita

	/*
		boolean verificaExpresion(expresion *exp);
		Descripción: Evalua la expresion para saber si es correcta, debe cumplir
		con los criterios algebraicos de las expresiones.
		Recibe:  *expresion la direccion de la cadena de la expresion.
		Devuelve: TRUE si es corecta , FALSE si no lo es.
		Nota : El programa necesita de operadores para cada operacion , si pongo (X+Y)*C(B-A) 
		El programa dara error en la expresion , como su huebira y dos constantes juntas en 
		el caso del ejemplo tomaria un CB , sin embargo si ponemos la expresio como
		(X+Y)*C*(B-A) La expresion queda correctamente 
	*/	 
	boolean verificaExpresion(expresion *exp)
	{
		int i; // contador
		exp->tamVariables =0; // contando la posiscion de las variables
		boolean isCorrect = TRUE;
		pila pilaValidaPare; // se crea una pila para validar los parentesis
		pila pilaValidaConst; // se crea una pila para validar constantes
		pila pilaValidaOpera; // se crea una pila para validar los operadores
		elemento e1; // se declara elemento e1

		// inicializamos las pilas
		Initialize(&pilaValidaPare);
		Initialize(&pilaValidaConst);
		Initialize(&pilaValidaOpera);

		// la pila Operacion necesita un elemento inicial.
		// si no ocurriria un error de subdesbbordamiento
		e1.c = '#';
		Push(&pilaValidaOpera,e1);
		// Debe tener algo la cadena a validar
		if(exp->cadena != NULL)
		{
			// no debe estar vacia la expresion
			//Recorrer cada caracter de la cadena 
			for(i=0;i<tamCadena(exp);i++)
			{
				if ((exp->cadena[i]>=48)&&(exp->cadena[i]<=57))
				{
					// Si son numeros no los deja entrar
					isCorrect = FALSE;
					printf("\n ERROR: Aun no debes ingresar valores numericos , usa una variable");
					exit(0);
				}
				switch(exp->cadena[i]){
					
					case ' ':
					break;
					// cuando es un parentesis se añade a la pila para validar el parentesis
					case '(' : 
							e1.c = '('; // elemento de la pila es '('
							Push(&pilaValidaPare,e1);
							break;

							case ')' : 
							//Si se intenta extraer un elemento y la pila es vacia Error: P.g. (a+b)*c)
							if(Empty(&pilaValidaPare))
							{
								isCorrect = FALSE;
								printf("\n ERROR: Existen mas parentesis que abren de los que cierran");
								
								exit(0);
								break;
							}
							else
								e1=Pop(&pilaValidaPare);
					break;

					case '+': // suma se trata de un operador  , se debe quitar una constante
						if(Empty(&pilaValidaConst))
						{
							isCorrect = FALSE;
							printf("\n ERROR: Existe algun operador mal escrito");
							exit(0);
							break;
						}else{
								// si no , quitamos una constante y guardamos el operador en pila de operadores
								Pop(&pilaValidaConst); // quitamos una constante
								e1.c = '+'; // Se añade el operador
								Push(&pilaValidaOpera,e1); // le añadimos el operador 
							}
							break;
						case '-': // resta
						if(Empty(&pilaValidaConst))
						{
								isCorrect = FALSE; // esta mal escrito
								printf("\n ERROR: Existe algun operador mal escrito");
					
								
								exit(0);
								break;

							}else{
								// si no , quitamos una constante y guardamos el operador en pila de operadores
								Pop(&pilaValidaConst); // quitamos una constante
								e1.c = '-'; // Se añade el operador
								Push(&pilaValidaOpera,e1); // le añadimos el operador 
							}
					break;

					case '*': // operador para multiplicar se debe quitar una constante
						if(Empty(&pilaValidaConst))
						{
							isCorrect = FALSE;
							printf("\n ERROR: Existe algun operador mal escrito"); // un ** 
							
							exit(0);
							break;
						}else{
							// si no , quitamos una constante y guardamos el operador en pila de operadores
							Pop(&pilaValidaConst); // quitamos una constante
							e1.c = '*'; // Se añade el operador
							Push(&pilaValidaOpera,e1); // le añadimos el operador 
						}
					break;

					case '/': // operador para dividir se debe quitar una constante
					
						if(Empty(&pilaValidaConst))
						{
							isCorrect = FALSE;
							printf("\n ERROR: Existe algun operador mal escrito");
							exit(0);
							break;
						}else{
							// si no , quitamos una constante y guardamos el operador en pila de operadores
							Pop(&pilaValidaConst); // quitamos una constante
							e1.c = '/'; // Se añade el operador
							Push(&pilaValidaOpera,e1); // le añadimos el operador 
						}
					break;

					case '^': // operador exponente se debe quitar una constante
						if(Empty(&pilaValidaConst))
						{
							isCorrect = FALSE;
							printf("\n ERROR: Existe algun operador mal escrito");
							exit(0);
							break;
						}else{
								// si no , quitamos una constante y guardamos el operador en pila de operadores
								Pop(&pilaValidaConst); // quitamos una constante
								e1.c = '^'; // Se añade el operador
								Push(&pilaValidaOpera,e1); // le añadimos el operador 
							}
					break;

					default: // en caso de que sea una letra o numero... quitar un operador
						// no importa el caso es una variable , se mete al arreglo de variables
						e1.c = exp->cadena[i];
						exp->variables[exp->tamVariables].var= e1.c;
						exp->tamVariables++; // sumamos a una posicion siguiente 
						if(Empty(&pilaValidaOpera))
						{
							isCorrect = FALSE;
							printf("\n ERROR: Existe alguna constante mal escrita");
							exit(0);
							break;
						}else{
								e1 = Pop(&pilaValidaOpera); // nota: no es necesario guardar el elemento  
								e1.c = exp->cadena[i]; // guardamos la constante
								// la metemos a la pila constantes
								Push(&pilaValidaConst,e1);
						}
					break;
					}
				}
		}else
			printf("%s\n", "La cadena esta vacia");


	/*
		Supongo que al validar la expresion en for y el Switch no es necesario estos ifs
		ya que si alguna expresion esta mal escrita se muere el programa con exit(0)
		Pero si en dado caso pasara el filtro , debera cumplir estas condiciones para
		saber si esta correcta la expresion.
	*/
		//Si al terminar de revisar la expresion hay elementos en la pilas Error: P.g. (a+b)*c(a-c
		if(!Empty(&pilaValidaPare)) // Revisar las pilas
		{
			printf("\n ERROR: Existen mas parentesis que abren de los que cierran");
			isCorrect = FALSE; // cambiamos a falso
		}
		if(Empty(&pilaValidaConst))
		{
			printf("\n ERROR: Existe alguna constante mal escrita");
			isCorrect = FALSE; // cambiamos a falso
		}
		if(!Empty(&pilaValidaOpera))
		{
			printf("\n ERROR: Estan mal escritos tus operadores ");
			isCorrect = FALSE; // cambiamos a falso
		}
		
		// destruimos la pilas
		Destroy(&pilaValidaPare); // destruimos la pila
		Destroy(&pilaValidaOpera); // destryue pila Opera
		Destroy(&pilaValidaConst); // destruye pila constantes

		if(isCorrect){	
			printf( "\n %s", "--------------EXPRESION CORRECTA------------\n");
		}

		// Todo array tiene que tener un caracter nulo que diga el final de la caena
		// le decimos el final de la cadena
		exp->variables[exp->tamVariables].var ='\0';
		
		return isCorrect;
	}

	/*
		int tamCadena (expresion *exp);
		Descripción: Se obtentra el tamño de la cadena para darsela al usuario
		Recibe:  expresion *exp apuntador hacia la variable de su cadena..
		Devuelve: int con el valor del tamaño de la cadena. 
	*/

	int tamCadena(expresion *exp)
	{
		int tam;
		exp->tamCadena = strlen(exp->cadena); // usdando la libreria string
		tam = exp->tamCadena;
		return tam;
	}

	/*
		boolean verificaParentesis (expresion *exp);
		Descripción: Evalua la expresion para saber si los parentesis estan correctos
		Recibe:  *expresion la direccion de la cadena de la expresion.
		Devuelve: TRUE si es corecta , FALSE si no lo es.
		Nota : El programa necesita de operadores para cada operacion , si pongo (X+Y)*C(B-A) 
		El programa dara error en la expresion , como su huebira dos constantes juntas en 
		el caso del ejemplo tomaria un CB , sin embargo si ponemos la expresio como
		(X+Y)*C*(B-A) La expresion queda correctamente 
	*/

	boolean verificaParentesis(expresion *exp)
	{
		int i;
		boolean isCorrect = TRUE; // banderita
		pila pilaParentesis; // se crea una pila para validar los parentesis
		elemento e1;

		// inicializamos las pilas

		Initialize(&pilaParentesis);

		if(exp->cadena != NULL)
		{
			// no debe estar vacia la expresion
			//Recorrer cada caracter de la cadena 
			for(i=0;i<tamCadena(exp);i++)
			{
				if (!(exp->cadena[i]>=48)&&(exp->cadena[i]<=57))
				{
					switch(exp->cadena[i])
					{
						case ' ':
							break;
							// cuando es un parentesis se añade a la pila para validar el parentesis
						case '(' : 
								e1.c = '('; // elemento de la pila es '('
								Push(&pilaParentesis,e1);
								break;
						case ')' : 
								//Si se intenta extraer un elemento y la pila es vacia Error: P.g. (a+b)*c)
								if(Empty(&pilaParentesis))
								{
									isCorrect = FALSE;
									printf("\n ERROR: Existen mas parentesis que abren de los que cierran");
									
									exit(0);
									break;
								}
								else
									e1=Pop(&pilaParentesis);
							break;

						default:
							break;

					}// switch fin.
				}// fin if
				
			} // fin for
			// verificando si los guardo bien printf("\n %s ", operandos[3].opera);
		}else
			printf("\n %s", "La cadena esta vacia");
		return isCorrect;
	}// fin funcion

