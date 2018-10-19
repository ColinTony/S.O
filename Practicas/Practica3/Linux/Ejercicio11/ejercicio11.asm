; Programe una aplicacion en ensamblador que muestre en pantalla la longitud de una cadena 
; que haya sido ingresada por el usuario (teclado) , Considere el caso de que tenga 10 caracteres
; o más.

;Autor : ColinTony
;Version: 1

segment .data
	; Definiendo las constantes.
	%define SYS_EXIT 	1 	; Salida
	%define SYS_READ	3	; llamada al sistema "sys_read"
	%define SYS_WRITE	4	; llamada al sistema para escribir
	%define STDIN		0	; llamada para entrada standart
	%define STDOUT		1	; llamada de salida estandar.
	%define EOL			0xA ; Salto de linea
	%define STOP		0x80 ; Interrupcion apra llamadas al sistema en windows.

	SMENSAJE db	"MEDIR LA LONGITUD DE LA PALABRA.",0xA,0xA 	; Mensaje de bienvenida.
	LEN_BIENVENIDA equ $- SMENSAJE
	MSG1 db	"Escribe la cadena a medir: "
	LEN_CADENA equ $- MSG1 ; longitud de pedir las cadenas.
	texto db 'Longitud: '
    lon2 equ $-texto
    ADIOS db 0xA,"ADIOS",0xA
    lon equ $- ADIOS

segment .bss
	
	cadena    resb 100	; reserva 100 bytes
	contador1 resb 8 ; reservamos 8 bytes 
	cent 	  resd 1
	deci	  resd 1
	uni		  resd 1

segment .text
	global _start

_start: 
	;setteamos a cero los contadores a cero
	mov byte [contador1],-1d

	;Mensaje de bienvenida al programa
	mov	edx,LEN_BIENVENIDA ; Longitud de string para pedir las cadenas.
	mov	ecx,SMENSAJE	; Mensaje de bienvenida
	mov ebx,STDOUT		; salida estandar.
	mov eax,SYS_WRITE 	; LLamada al sistema sys_write
	int STOP	

	mov edx,LEN_CADENA ; longitud de la cadena a impmirmir
	mov ecx,MSG1 		; mensaje a impmirmir MSG1
	mov ebx,STDOUT		; Salida video.
	mov eax,SYS_WRITE   ; llamada al sistema
	int STOP			; llamada de interrupcion

	; guardamos la cadena 
	mov eax,SYS_READ 	; llamada al ssitema sys_read
	mov ebx,STDIN		; entrada estandar
	mov ecx,cadena 		; se va guardar en cadena
	mov edx,100d			;50bytes posuvles
	int STOP			; interrupcion 
	
	; movemos al registro manipulador para manipular cadenas
	mov esi,cadena
	mov edi,cadena
	
		
	jmp medir

medir:
	;Este registro (AL) indica que se copie el valor de la porción de la memoria que esté en la ubicacióna 1000 (En hexadecimal) a la parte baja del registro AX (AL).
	mov al,[esi] 		; movemos el registro esi al AL  
    inc esi  			; aumentamos ESI en uno
    mov [edi],al  		; copiamos al en edi , para guardar el estado anterior
    inc edi 			; aumentamos el regitro edi en uno.

    cmp al,0			; si al es igual a cero significa que ya no hay 
    je  terminar; si son iguales terminamos imprimiendo
    jne	contar ;si no son iguales

contar:
	add byte [contador1],1d ; aumentamos el contadon
	jmp medir

terminar:
	mov  ax,[contador1]
	cmp  ax,100
	jl   menorCienConverter
	jge  mayorCienConverter

;INICA CONVERTIDOR DE NÚMEROS MENORES A 100
menorCienConverter:
	mov  bl,10d
	mov  dx,ax
	idiv bl
	push ax
	mul bl
	sub dx,ax
	mov ax,dx
	push ax
	pop ax
	add ax,'0'
	mov [uni],ax
	pop ax
	add ax,'0'
	mov [deci],ax
	mov ax,0
	mov [cent],ax
	jmp print
	;FIN DEL CONVERTIDOR

;INICIA CONVERTIDOR DE NÚMEROS MAYORES A 100
mayorCienConverter:
	mov   bl,100d
	mov   dx,ax
	idiv  bl
	push  ax
	mul   bl
	sub   dx,ax
	mov   ax,dx
	xor   bl,bl
	mov   bl, 10d
	idiv bl
	push ax
	mul bl
	sub dx,ax
	mov ax,dx
	push ax
	pop ax
	add ax,'0'
	mov [uni],ax
	pop ax
	add ax,'0'
	mov [deci],ax
	pop ax
	add ax,'0'
	mov [cent],ax
	jmp print
;FIN DEL CONVERTIDOR

print:
	mov edx,lon2 ; longitud de la cadena a impmirmir
	mov ecx,texto 		; mensaje a impmirmir MSG1
	mov ebx,STDOUT		; Salida video.
	mov eax,SYS_WRITE   ; llamada al sistema
	int STOP			; llamada de interrupcion

	;Mensaje de bienvenida al programa
	mov	edx,1d 		; Longitud de string para pedir las cadenas.
	mov	ecx,cent		; Mensaje de bienvenida
	mov ebx,STDOUT		; salida estandar.
	mov eax,SYS_WRITE 	; LLamada al sistema sys_write
	int STOP

	mov	edx,1d 		; Longitud de string para pedir las cadenas.
	mov	ecx,deci		; Mensaje de bienvenida
	mov ebx,STDOUT		; salida estandar.
	mov eax,SYS_WRITE 	; LLamada al sistema sys_write
	int STOP
	
	mov	edx,1d 		; Longitud de string para pedir las cadenas.
	mov	ecx,uni		; Mensaje de bienvenida
	mov ebx,STDOUT		; salida estandar.
	mov eax,SYS_WRITE 	; LLamada al sistema sys_write
	int STOP	

	jmp fin

fin:
	mov	edx,lon 		; Longitud de string para pedir las cadenas.
	mov	ecx,ADIOS		; Mensaje de bienvenida
	mov ebx,STDOUT		; salida estandar.
	mov eax,SYS_WRITE 	; LLamada al sistema sys_write
	int STOP

	mov eax,SYS_EXIT	;salida del programa
	int STOP		; interrupcion al sistema
