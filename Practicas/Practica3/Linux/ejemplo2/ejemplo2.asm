; Este programa Pide una cadena al usuario y luego la muestra en la terminal.

segment .bss			;Segmento de datos 
cadena resb 50			; Espacio en memoria para la cadena a almacenar

segment .text			;Segmento de texto
global _start			;punto de entrada al programa (usando con el enlazador id)
_start: 
		mov edx,50d		;Longitud del buffer
		mov ecx,cadena	;Cadena a leer
		mov ebx,0		;Entrada estandar
		mov eax,3		;Numero de llamada al sistema "sys_read"
		int 0x80		;Interrupcion de llamadas al sistema del kernel de linux
		mov edx,50d		;Longitud de cadena
		mov ecx,cadena 	;Cadena a escribir
		mov ebx,1		;salida estandar
		mov eax,4		;Numero de llamada al sistema "sys_write"
		int 0x80		;Interrupcion de llamdas al sistema del kernel de linux
		mov eax,1		;Numero de llamada al sistema "sys_exit"
		int 0x80		;Interrupcion de llamadas al sistema del kernel de linux