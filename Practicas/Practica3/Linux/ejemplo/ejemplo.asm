; Muestra en la terminal la cadena Programando en ensamblador para linux
segment .data												; Segmento de datos
cadena db 'Programando en ensamblador para linux ',0xA		; Cadena a imprimir

segment .text												; Segmento de codigo
global  _start	 											; Punto de entrada al programa(usando el enlazador ld)

_start: 													; Inicio del prgrama 
		mov		edx,38d										; longitud de cadena
		mov 	ecx,cadena 									; Cadena a escribir
		mov 	ebx,1										; Salida estandar
		mov 	eax,4										; Numero de llamada al sistema "sys_write"
		int 	0x80										; interrupcion de llamadas al sistema del kernel de linux
		mov 	eax,1										; Numero de llamada al ssitema "sys_exit"
		int 	0x80										; Interrupcion de llamadas al sistema del kernel de lunux