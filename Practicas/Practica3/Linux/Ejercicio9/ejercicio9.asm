; Programe una aplicacion en ensamblador que genere un contador de 0 a 9 , mostrando en pantalla el 
; conteo generado. Consejo: revise las instrucciones de ensamblador CMP , JMP , JNE ,JE e INC.
; Author ColinTony
; Version 1

segment .data 
	; Definiendo las constantes.
	%define SYS_EXIT 	1 	; Salida
	%define SYS_WRITE	4	; llamada al sistema para escribit
	%define STDIN		0	; llamada para entrada standart
	%define STDOUT		1	; llamada de salida estandar.
	%define EOL			0xA ; Salto de linea
	%define SMENSAJE	"Bienvenido al contador." 	; Mensaje de bienvenida.
	%define STOP		0x80 ; Interrupcion apra llamadas al sistema en windows.

	; Definimos por completo la constante SMENSAJE.
	sMensaje db SMENSAJE,EOL,EOL
	LEN_MENSAJE equ $- sMensaje

segment .bss
	;pondremos nuestro contador.
	; Para imprimir este numero hare uso de la tabla ASCII
	contador: resw 1; Rerserva 2 bytes
	cadena_numeros: resw 1; Reserva 2bytes

segment .text ; segmento de codigo.
	global _start	; punto de entrada.

_start:
	; preparamos el despliegue de la bienvenida al contador
	mov edx,LEN_MENSAJE	; mandamos la longitud de nuestro mensaje.
	mov ecx,sMensaje 	; Mansams el mensaje que queremos desplegar.
	mov ebx,STDOUT 		; Mandamos a la salida de pantalla.
	mov eax,SYS_WRITE	; llamada al sismte sys_write.
	int STOP			; interrupcion

	;Añadimos el valor pondremos el valor de cero en ASCII ya que se me hace mas facil
	mov [contador],byte 48 ; Ponemos el valor de 0 en el contador
	mov [contador+1],byte EOL	; movemos el fin de cadena.
	; Iniciamos el bucle.
	jmp imprime_numero	; saltamos a imprimir el numero.

imprime_numero:
	; se encargara de imprimir el valor del contador.
	; Guardamos el digito con un salto de linea en la cadena_numeros

	;Impmimimos
	mov edx , 2	; Longitud de bytes.
	mov ecx, contador ; imprimieremos el contador
	mov ebx , STDOUT	; salida de video.
	mov eax, SYS_WRITE 	; llamda al sistema sys_write.
	int STOP 			; interrupcion para llamadas al sistema.
	cmp [contador], byte 57 ; si el contador es igual al 9 (57 en ASCII)
	je fin				; terminamos la ejecucion del programa.
	jl aumenta 			; saltamos a umentar

fin:
	mov eax,SYS_EXIT	; LLamada de salirda del programa
	int STOP			; interrupcion para linnux,

aumenta:
	; se encargara de aumentar en uno para el siguiente numero.
	inc byte [contador]	;incrementamos en 1 al contador.
	jmp imprime_numero	; volvemos a llamar a imprmir el numero

