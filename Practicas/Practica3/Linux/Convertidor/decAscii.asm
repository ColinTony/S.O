segment .data

segment .bss
  
  handleConsola          resd 1
  cadenaUsuario          resd 99
  numChars               resd 1
  numCharsR              resd 2
  cent                   resd 1
  deci                   resd 1
  uni                    resd 1

segment .text
  global _main
  extern _GetStdHandle@4
  extern _WriteConsoleA@20
  extern _ReadConsoleA@20
  extern _ExitProcess@4
  _main:
mov  ax,27d
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
push          dword -11
call          _GetStdHandle@4
mov           [handleConsola],eax

push          dword 0
push          dword numChars
push          dword 1d                       ; Arg3: TAMAÑO DE LA CADENA
push          dword cent                              ; Arg2: CADENA A IMPRIMIR
push          dword [handleConsola]             ; Arg1: HANDLE DE LA SALIDA ESTANDAR
call          _WriteConsoleA@20

push          dword 0
push          dword numChars
push          dword 1d                       ; Arg3: TAMAÑO DE LA CADENA
push          dword deci                              ; Arg2: CADENA A IMPRIMIR
push          dword [handleConsola]             ; Arg1: HANDLE DE LA SALIDA ESTANDAR
call          _WriteConsoleA@20

push          dword 0
push          dword numChars
push          dword 1d                       ; Arg3: TAMAÑO DE LA CADENA
push          dword uni                              ; Arg2: CADENA A IMPRIMIR
push          dword [handleConsola]             ; Arg1: HANDLE DE LA SALIDA ESTANDAR
call          _WriteConsoleA@20

push    dword 0         ; Arg1: push exit code
call    _ExitProcess@4
