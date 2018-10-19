
; En ensamblador tiene registros de alta velocidad y son la cumbre de la jerarquia de la memoria.
; Se miden por el numero de bits 
; Existen tipos de registros
; <---------------------------------------------------------------------------------------------------------------->
; General Register
;	Registro de datos (Data register)
;	Registros de apuntador (Pointer Register)
; 	Registros de indices (Index Register).
; <---------------------------------------------------------------------------------------------------------------->
; Registro de datos
;	Son usados para operaciones de matematicas y logicas 
; 	Hay 4 registros de datos de 32 bits los cuales son
; EAX , EBX , ECX y EDX

; Estos mismos 4 registros , pueden ser referenciados como de 16 bits , llamandolos de la forma:
; AX , BX , CX , y DX (Sin la E)

; Los 4 anteriores registros de 16 bits , pueden ser llamados en su parte baja y alta , de la siguiente forma
; AH , AL, BH , BL, CH ,CL,DH,DL (Donde H es de High la cual e sla parte alta y L de lower la cual e sla parte baja).

; Prpositos de cada uno de los registros.
; AX . Es el registro acumulador , es utilizado para entrada y salida de datos, y para la mayoria de las operaciones aritmeticas.
; BX . Es un registro base . Es utilizado para direccionamiento de datos.
; CX. Es un registro contador . Utilizado en operaciones iterativas o de repeticion para llevar el controlde las veces que se repita un proceso.
;	como el for , aqui nosotros colocamos un valor determinado y lanzamos una instruccion esa instruccion se va ejecutar hasya CX llege a cero.
; DX. Es el registro de datos. Es tambien usado operaciones de entrada y salida . junto con el AX  , es utilizado para diviciones y multiplicaciones  

; <---------------------------------------------------------------------------------------------------------------->
; REGISTROS APUNTADOR
; Hay 3 registros  de 32 bits y que son : EIP , ESP y EBP. y se puede hacer referencia a su parte de 16 bits con IP,SP , BP

; PROPOSITOS DE REGISTROS APUNTADOR
; IP. Intruction Pointer
;	Este registro 	lleva a cabo el control de desplazamiento de la siguiente instruccion ejecutada.
;	En conjunto con el registro CS. (CS:IP) , se puede obtener la direccion completa actual instruccion en el segmento de DAtos.
; SP. Stack Pointer
; Provee el desplazamiento de la pila del programa . SP en conjunto con SS (SS:SP), refiere a la actual posicion del dato o direccion
; Dentro de la pila del programa.
; BP. Base pointer
;	Es utilizado principalmente para referenciar a las variables utilizadas como parametros a subrutinas .
; 	En conjuto con SS (SS:BP) se puede utilizar para obtener la direccion completa  de un parametro  a una subrutina.
; 	Tambien se puede  utilziar con DI y SI , como registro base para especiales direccionamientos.
; <---------------------------------------------------------------------------------------------------------------->
; REGISTROS INDICE.
; Hay dos tipos de registros indice de 32 bits y son ESI y EDI.
; Al igual que con los anteriores registros podemos acceder a su parte de 16 bits quitando la E.
; Estos registros son usados para el direccionamiento indexado y en algunas ocacione spara la suma y resta.


; SI. Source Index . Es utilizado para operaciones	de cadena , como el origen de la operacion.
; DI.  Destination Index. Es utilizado para operaciones de cadena , como parte destino de la operacion.
; (hay instrucciones en ensamblador que nos permiten manipular cadenas donde tendremos parte orgien que sera SI complementado y el resultado sera el 
; Destino que sera DI , la cual sera la direccion destino.)

; <---------------------------------------------------------------------------------------------------------------->
;RESGISTROS BANDERA

; Este registro es utiliado para diversos tipos de resultados que se realizzan entre las opciones .
; Es un registro  de  16 bits.
; Estructura de una bandera.

; Flag ->	             0F DF IF TF SF ZF    AF   PF     CF
; Bit No. -> 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00 

; Donde las banderas son las siguientes
; Overflow Flag (OF). Indica sobreflujo  del mas alto bit (izquierdo) despues de haber realizado una operacion aritmetica con signo.

; Direction Flag (DF). Indica si las operaciones de comparar o mover datos de una cadena , se realizaron hacia la izquierda o derecha.
; Cuando el valor es de 0 , la operacion se realiza de izquierda a derecha y  si es 1 es de derecha a izquierda

;Interrupt Flag (IF). Determina cuando una externa interrupcion , como por ejemplo una entrada por el teclado , son ignoradas o procesadas.
; Cuando el valor es 0 , se encuentrasn deshabilitadas : y cuando el valor es de 1 se encuentra habilitada.

; Trap Flag (TF). Permite  que la operacion del procesador sea un modo  "single-step" . cuando usamos un programa DEBUG, activamos esta bandera ,
; Para poder realizar la ejecucion del prgrama , por una instruccion.

;Sign Flag (SF). Indica el signo de un resultado en una operacion aritmetica.Un resultado positivo , coloca el valor de SF en 0; si no en 1.

;Zero Flag(ZF). Indica si el resultado de una operacion aritmetica o de comparacion fue 0 , un numero diferente de cero ,colocara el valor en 0 y
; Un resultado igual a cero , le pondra un 1

;Auxiliary Carry Flag (AF). Contiene el acarreo de una operacion arimetica , del 3 bit al bit 4 . AF es puesto en 1 cuando hay un acarreo del bit 3 al 4.

;Parity Flag (PF). Indica si el total de 1's en un resultado de una operacion aritmetica es par o impar . Si el numero 	de 1's es par 
; Pondra la bandera en 0 , si es impar en 1

;Carry Flag (CF) Contiene el acarreo de 0 a 1 , al realizar una operacion aritmetica que desborde el ultimo bit significativo;
; Es decir , el de la isquierda. Tambien tiene el utimo bit de una operacion shift o rotate.

; <---------------------------------------------------------------------------------------------------------------->
;REGISTRO DE SEGMENTOS.

;Register Code Segment. Es un registro de 16 bits donde se deposita la direccion inicial del segmento de codigo. (Donde empezo el segmento de codigo)
;Register Data Sgment . Es un registro de 16 bits en el cual se encuentra depositada la direccion inicial del segmento de datos.
; Register Stack Segment. Es un registro de  16 bits en donde se depositan la direccion inicial del segmento de pila.

; Aparte de estos  3 registros de segmento, existen otros 3 que se llaman ES , FS  y GS.  Los cuales son utilizados para almacenar datos.
; Todos los registros de segmentos , contienen la direccion inicial correspondiente . Para poder acceder a cualquer dato dentro del mosmo.
; , se debe utilizar esta direccion inicial ,mas un desplazamiento u offset. 



; 123456789+2 (Direccion de memorua y luego) (+2 es el desplazamiento) 
;				020
;				130
;			->>	240 (Entramos a este dato)
;				950
;				012
;				923


;<----------------------------------------------------------------------------------------------------------------->
; DIRECCIONAMIENTO.
;	Exiten 3 modos de direccionamieitno 
;	-Direccionamiento por Registro (Register Addresing)
;	-Direccionamiento Inmediato (Inmediate Addresing)
;	-Direccionamiento a Memoria (Memory Addresing)
;		*Direccionamiento Directo (Direct Memory Addresing)
;		*Direccionamiento Directo-Desplazamiento (Direct Offset Addresing)
;		*Direccionamiento Indirecto (Indirect Memory Addresing).

;--------------------------------------------------------------------------------------------------------------------
; DIRECCIONAMIENTO POR REGISTRO.
; En este modo de direccionamiento, un registro es quien contiene el operando a utilizar.
; Dependiendo de la instruccion , el registro puede ser el primer operando , el segundo o ambos.
; Ejemplos.
; MOV DX, TAX_RATE ; Registro en el primer operando.
; MOV COUNT . CX   ; Registro en el segundo operando.
; MOV EAX , EBX    ; Ambos operandos son registros.

;<.--------------------------------------------------------------------------------------------------------------->
; DIRECCIONAMIENTO INMEDIATO.
; Es cuando un operando , tiene un valor constante  o una expresion . Cuando una instruccion con dos oeprandos utiliza direccionamiento inmediato ,
; el primer operando puede ser una ubicacion de registro o de memoria , y de segundo operando es una constante. 

; Definimos 2 atos 

; BYTE_VALUE DB 150 ; un byte
; WORD_VALUE DW 300 ; Un word.

; Direccionamiento inmediato
; ADD BYTE_VALUE , 65 ; sumamos la constante 65
; MOV AX , 45H 		  ; colocamos el valor constante 45H a AX

;<----------------------------------------------------------------------------------------------------------------___>
; cuando el operando es una direccion de memoria dentro del segmento de datos . Para localizar la ubicacion exacta de los datos en la memoria 
; necesitamos la direccion de inicio del segmento , que se encuentran tipicamente en los registros DS y un valor de desplazamiento. Este valor
; de desplazamiento. Este valor de desplazamiento es tambien llamado direcicon efectiva.

;En el modo de direccionamiento directo , el valor de desplazamiento se especifica directamente como parte de la instruccion , habitualmente 	por el 
; nombre de la variable . El ensamblador calcula el valor de desplazamiento y mantiene una tabla de símbolos , que almacena los valore sd e desplazamiento
; de tosas las variables utilizadas en el prgrama.

; Al abordar directo a la memoria , uno de los oprandos se refiere a una ubicacion de memoria y el otro operando se hace referencia a un registro . Pro ejemplo

; ADD  BYTE _VALUE , DL ; Agrega valor del registro  a la direccion de memoria 
; MOV  BX , WORD:VALUE ; El valor indicado en la direccion de memoria , es colocado en BX.

;<--------------------------------------------------------------------------------------------------------------------->
; DIRECCIONAMIENTO DIRECTO-DESPLAZAMIENTO.
; Este modod de direccionamiento utiliza los operandos aritmeticos para modificar una direccion. Ejemplo:

; Declaramos arreglos o tablas.
; BYTE_TABLE BD  14, 15 , 22, 45. ; tabla o vector de datos.
; WORD_TABLE DW  134 , 345, 564, 123. ; Tabla o Vector de datos.

; Ejemplo con direccionamiento Directo-Desplazamiento.
; MOV CL,BYTE_TABLE[2] ; Accsede al tercer elemento del arreglo.
; MOV CL, BYTE_TABLE +2 ; Accede al tercer elemento del arreglo.
; MOV CX, WORD_TABLE [3]: Accesde al 4to elemento del arreglo.
; MOV CX , WORD_TABLE +3; Accesde al 4to elemento del arreglo.

;<----------------------------------------------------------------------------------------------------------------------------------------->
; DIRECCIONAMIENTO INDIRECTO.
; Este modo de direccionamiento utiliza la capacidad del direccionamiento basado en segmento :Desplazzamiento.
; Gerealmente los registros base : EBX ,EBP(o BX ,BP) y los registros de indice (DI , SI), codificados entre corchetes ,son 
; utilziados para hacer referencia a memoria.

;El direccionamiento indirecto se utiliza generalemte para las variables que contienen varios elementos,como son las matrices.
; La direccion inicial de la matriz , se almacena en , por ejemplo ,el registro EBX. Ejemplos:

;	MY_TABLE TIMES 10 DW 0; Reserva un vector o tabla de 10 WORDS , cada uno inicializado con 0.

; MOV , [MY_TABLE] ; Coloca la direccion de MY_TABLE en el registro EBX.
; MOV [EBX] , 110 ; Direccionamiento inidirecto. Mueve el valor de 110 a la direccion que tiene EBX;  MY_TABLE[0] = 110
; ADD EBX , 2 ; Incrementa el valor de EBX en 2 , para que apunte al 2do elemento del vector 
; MOV [EBX] , 123 ; direccionamiento indirecto. Mueve el valor de 123 ala direcicon que tiene EBx : MY_TABLE[1] = 123.

;<-----------------------------------------LINUXAPI-------------------------------------------------------------------------->
; LAs API de linux son las funciones de que nos permiten aceder a los recursos y servicios del linux kernel.
; En el ejemplo , se ha hehoc uso de 2 de estas funciones : sys_write y sys_exit.
; La funcoin sys_write , se ha utilizado para desplegar un mensaje n la pantalla.
; La funcion sys_exit se utiliza para salir del programa.

; Cada una de estas funciones , es posble identificarla por un numero único.
; La funiocn sys_write , es identificada con el numero 4 el cual debe ser depositado en el registro EAX.
; La funcion sys_exit , es identificada con el numero 1 de igual forma . debe ser depositado en el registro EAX.

; <--------------------------------------------------------------------------------------------------------------------------_>
; COMO LLAMAR A LAS FUCNIONES.
; para poder hacer uso de las funciones API linux , deberemos de seguir los siguientes pasos.

; - Colocar el numero correspondiente a la funcion , en el registro EAX.
; - Depositar los argumentos , si es que los necesita la funcion ; en los registros correspondientes.
; - Ejecutar la interripcion 80h.
; - El resultado retornado es depositado usualmente en el registro EAX.

; Hay 6 tipos de registros que se utilizan para depositar los agumentos si es que una funcion los necesita.
;Estos son EBX , ECX , EDX , ESI , EDI y EBP.

; Ejemplos.
; El siguiente ejemlpo tomando del programa ejemplo
; Muestra el uso dela funcion sys_exit , la cual permite finalizar un programa y retornar un codigo de salida oexit code.

; Ejemplo de sys_exit
; mov eax , 1 ; La funcion de sys_exit , corresponde al valor de 1.
; mov ebx , 0 ; Es el valor que retornara la funcion al salir ; el exit code.
; int 0x80 ; Se ejecuta la interrupcion.

; la funcion sys_exit no necesita parametros para ejecutar , sin embargo el valor que tenga el registro ebx,sera el que retorne la
;aplicacion al finalizar.

; el siguiente ejemplo tambien es el tomado del programa ejemplo
; Mueestra el uso de la funcion sys_write. Esta funcion permite mandar un mensaje a la pantalla.
; Ejemplo de sys_write
; mov edx , len 	; longitud 
; mov ecx , msg 	;mensaje a desplegar 
; mov ebx , 1 		;el archivo descriptor (stdout) salida estandar del sistema operativo. puede ir a otros lugares.
; mov eax ,4		; el numero de la funcion correspondiente a sys_write
; int 0x80 			; llama a la interrupcion 0x80.

; Para que la funcion sys_write funcione correctamente:
; 	-Debe indicarse la longitud de la cadena o mensaje a desplegar en el registro edx.
;	-Debe indicarse la direccion donde se encuentra el mensaje a desplegar en el regisro ecx.
;	-Debe indicarse el archivo a donde se realizara el enviado de la cadena ; y en donde 1 es igual a stdout
;	-Debe indicarse el numero 4, que es el correspondiente a la funcion ; en el registro eax.
; 	-ejecutar la interrupcion 0x80.

;<-------------------------------------------------------------------------------------------------------------------__>
; LISTA DE FUNCIONES.
;	Todas las fuciones 	api disponibles se encuentran en un archivo , junto con sus numeros correspondientes.
;  	es decir el valor que debe indicarse en el registro EAX antes antes de llamar a la interrupcion 80h
;  /urs/include/asm/unistd.h dentro de este archivo se encuentran unas referencias a otros archivos que contienen la LISTA
; de las funciones con su respectivo numero para llamarlas.


; <----------------------------------------------------------------------------------------------------------------_>
; INSTRUCCION MOVE.

; Es una instruccion por exelenecia en el enguaje ensamblador , tal como lo suguiere su nombre , la isntruccion 
; MOV mueve informacion de un lugar a otro.

; La sintaxis de la instruccion mov es la siguiente  , se puede utilizar de 5 formaas:

; mov registro . registro.
; mov registro , inmediato.
; mov memoria , inmediato.
; mov registro ,memoria.
; mov memoria,registro.

; Como vemos es 
; MOV destino , origen.

; hay 2 cosas importantes a conciderar en la instruccion mov.

; 1) Los 2 operandos deben ser del mismo tamaño. Ejemplo:
; 	mov AX , BX: Es correcto ambos operandos tienen el mismo tamaño.
;	mov AX , BH	;Es incorrecto ; ya que AX es mayor que BH

; 2) El valor del operando origen , queda intacto despues de ejecutar la instruccion.

;A continuacion se muestra una tabla que indican los tamaños posibles en los operandos:

;---------------------------;
;TAMAÑO  			Byte's  |
;---------------------------;
; BYTE 				1		|
; WORD 				2		|
; DWORD				4		|
; QWORD				8		|
; TBYTE				10		|
;----------------------------

;Numeros en bases distinatas.
; Ejemplos de como usar constantes numericas en diferentes bases.
;	mov ax,100	; Decimal
;	mov ax,0a2h	; HexaDecimal.
;	mov ax,$0a2 ; hexadecimal de nuevo : el 0 es necesraio.
; 	mov ax,0xa2	; hexadecimal otra vez.
;	mov ax,777q	; Octal.
;	mov ax,10010011b 	; Binario.


;<------------------------------------------------------------------------------------_>
; CONSTANTES EQU
; Para definir constantes en ensambladro poder hacerlo de 3 formaas
; %equ
; %assing
; %define
; La directiva EQU nos permite definir constantes numericas o de caracter.
; su sintaxis es.
; NOMBRE_CONSTANTE equ valor.

;Ejemplos:
; MAX_VALOR equ 99
; Notas
; En la seccion data , se declaran constantes y variables que tienen un valor INICIALIZADO.
; En las seccion .bss , se declaran variables que NO SE INICIALIZAN.

; La manera en la que utilizaremos el equ sera. :
; en la seccion de .data. Definiremos las constantes 
; SYS_EXIT EQU 1
; SYS_WRITE EQU 4
; STDIN		EQU 0
; STDOUT 	EQU 1
; CHR_EXCL  EQU '!'
; EOL       EQU 0xA

; La directiva %assing
; Permite definir constatnes igual que equ , pero permite la redefinicion.
; assing  NOMBRE_CONSTANTE VALOR
; Ejemplo 
; %assing MAX_VALUE 99

; Redefinicion.
; %assing SYS_EXIT 0
; %assing SYS_EXIT 1 
; Se puede usar para poner otro segmento .data y volver a definir las constantes. Pero
; No es aconsejable.

; La directiva define , permite definir constantes numericas , de caracter o cadenas.
 ; %define nombre valor.
 ; %define MENSAJE "ERROR SISTEMA"


 ; ------------------------------------------------------------------------------------------------->
 ; Variables in inicializar.
 ; Hay 5 directivas 
 

 ; directivaa
 ; 	RESB		Reserve a byte. 1 byte
 ; 	RESW		reserva word 2byte's
 ;	RESD 		REserva Double word 4  byte's
 ; 	RESQ 		Reserve Quadword 8 byte's
 ;	REST 		Reserve a TEN Bytes 	10 byte's.

 ; nombre directiva  numero_espacio_reservar

 ;----------------------------------------------------------------------------------------------------__>
 ; TIMES.
 ; Este prefijo causa que la isntruccion a ser ensamblada , se multiplique las veces indicadas .
 ; En este caso , veremos como utilizar este prefijo , al momneto de declarar una variable
 ; strMesnaje times 10 db '.' Repite 10 veces el punto.
; --------------------------------------------------------------------------------------------------------<:

; INSTRUCCIONES INC Y DEC.
; INC : Incrementa en 1 el operando indicado.
; DEC decrementa en 1 el operando indicado.

; La sintaxis de estas instrucciones es la siguiente.
; INC operando.
; DEC operando.
; para cada caso el operando sera incrementado o decrementado en 1


;--------------------------------------------------------------------------------------------------------------_>
; FUNCION SYS READ, ADD ,SUB.

; Sys_read es una funcion que nos permite leer desde el teclado.
; add y sub , son isntrucciones para realzar sumas y restas aritmeticas entre operandos.
; La operacion debe realizarse entre operandos byte ,word ,DWORD ; es decir que es posible realiar operaciones 
; con operandos de 8 bits , 16 bits y 32 bits

; la sintaxis es la siguiente.

; ADD/SUB destino , origen.

;Para cualquier de las dos funciones se realizara la operacion entre los dos operandos .
; El resultado de la operacion queda registrado en el destino.

; Esta instruccion puede usarse con los sigientes direccionamientos.
; Registro a registro.
; Memoria a registro.
; Registro a registro.
; Registro a memoria 
;Registro a constante 
;Memoria a constante

;------------------------------------------------------------------------------------------------------------->
;INVESTIGANDO LAS FUCIONES CMP , JMP, JE , JNE.

;CMP destino, fuente
;Esta instrucción resta el operando fuente al operando destino pero sin que éste almacene el resultado de la operación, solo se afecta el estado de las banderas.
;Instrucción CMPS (CMPSB) (CMPSW)
;	Propósito: Comparar cadenas de un byte o palabra.
;Sintaxis:
;	CMP destino, fuente

;Con esta instrucción la cadena de caracteres fuente se resta de la cadena destino.
;Se utilizan DI como indice para el segmento extra de la cadena fuente y SI como indice de la cadena destino.
;Solo se afecta el contenido de las banderas y tanto DI como SI se incrementan.

;CMP --> No reliza ninguna toma de decisiones , solo realiza la comparacion.
; Ejemplo queremos saber si un numero es mayor a 2. es todo lo que hace.
; Para ello usamos los saltos. 
; JMP es un salto incondicional salta sin que exista una comparacion o condicion previa.
; JG necesita una comparacion previa para poder saltar, dependiendo de la comparaicon.
; La etiqueta debera declarase como.
; Nombre : 
;	aqui el codigo.

; EXISTEN diferentes tipos de saltos. EN el ejemplo para saber si un numero es mayor a 2.
; Estos saltos se pueden hacer despues de la comparacion CMP.

; JG : salta si es mayor
; JGE : Salta si es mayor o igual.
; JZ : Salta si es cero.
; JE : Salta si es igual. 
; JL : Salta si es menor.
; JLE : salta si es menor o igual.

; si solo quermos hacer un salto incondicional JMP.




