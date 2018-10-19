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
	texto db 'Longitud: ',0xA  
    lon2 equ $-texto

segment .bss
	
  	numChars               resd 1
  	cent                   resd 1
  	deci                   resd 1
  	uni                    resd 1
  	handleConsola          resd 1

segment .text
	global _start

_start:
	;usos de la funcion apra CONVERTIDOR.
	mov  ax,520d
	cmp  ax,100
	jl   menorCienConverter
	cmp  ax,100
	jge  mayorCienConverter

;INICA CONVERTIDOR DE NÚME


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
	jmp print2
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
	jmp print2
;FIN DEL CONVERTIDOR

print2:
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
	mov eax,SYS_EXIT	;salida del programa
	int STOP		; interrupcion al sistema
