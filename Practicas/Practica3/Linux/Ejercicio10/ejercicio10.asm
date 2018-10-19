; Programe una aplicacion en ensamblador que copie tres cadenas dadas (cadena1 , cadena 2 , cadena 3)
; a una nueva cadena (cadena4). La copia de las cadenas debe ser intercadlando los caracteres de cada
; cadena. LAs cadenas debesn ser ingresadas por el usuario cadena 1,2,3. Muestre el contendio
; de la cadena 4. consejo Revise el uso de los registros SI y DI.

;Autor : ColinTony
;Version: 1

segment .data
  ; Definiendo las constantes.
  %define SYS_EXIT  1   ; Salida
  %define SYS_READ  3 ; llamada al sistema "sys_read"
  %define SYS_WRITE 4 ; llamada al sistema para escribir
  %define STDIN   0 ; llamada para entrada standart
  %define STDOUT    1 ; llamada de salida estandar.
  %define EOL     0xA ; Salto de linea
  %define STOP    0x80 ; Interrupcion apra llamadas al sistema en windows.

  SMENSAJE db "CONCATENAR 3 CADENAS EN OTRA ALTERNANDO SUS CARACTERES.",0xA,0xA   ; Mensaje de bienvenida.
  LEN_BIENVENIDA equ $- SMENSAJE
  
  MSG1 db "Escribe la cadena numero 1: "
  LEN_CADENA1 equ $- MSG1 ; longitud de pedir las cadenas.
  MSG2 db "Teclea la cadena numero  2: "
  LEN_CADENA2 equ $- MSG2 ; longitud
  MSG3 db "Escribe la cadena numero 3: "
  LEN_CADENA3 equ $- MSG3 ; longitud
  
  SMENSAJE2 db 'CADENAS INGRESADAS :',0xA
  LEN_CADENAS equ $- SMENSAJE2

segment .bss      ;Segmento de datos
  cad1 resb 20      ;Espacio en memoria para la cadena 1
  cad2 resb 20      ;Espacio en memoria para la cadena 2
  cad3 resb 20      ;Espacio en memoria para la cadena 3
  cad4 resb 60      ;Espacio en memoria para la cadena 4
  num resb 1

segment .text     ;Segmento de codigo
  global _start      ;punto de entrada al programa
_start:
  ;Mensaje de bienvenida al programa
  mov edx,LEN_BIENVENIDA ; Longitud de string para pedir las cadenas.
  mov ecx,SMENSAJE  ; Mensaje de bienvenida
  mov ebx,STDOUT    ; salida estandar.
  mov eax,SYS_WRITE   ; LLamada al sistema sys_write
  int STOP      ; interrupcion del programa.

  ;pedimos la cadena 1
  mov edx,LEN_CADENA1 ; Longitud de string para pedir las cadenas.
  mov ecx,MSG1    ;cambiamos el registro.
  call pedir_palabra  ; oedunis la palabra
  
  ; guardamos la cadena 1
  mov ecx,cad1 ; guardar en cadena1
  mov edx,20d ; leeremos 50 bytes posibles de la cadena.
  call guardar_palabra ; guardamos en la cadena


  ;pedimos la cadena 2
  mov edx,LEN_CADENA2 ; Longitud de string para pedir las cadenas.
  mov ecx,MSG2    ;cambiamos el registro.
  call pedir_palabra  ; pedimos la palabra
  
  ; guardamos la cadena 2
  mov ecx,cad2 ; guardar en cadena2
  mov edx,20d ; leeremos 50 bytes posibles de la cadena.
  call guardar_palabra ; guardamos en la cadena


  ;pedimos la cadena 3
  mov edx,LEN_CADENA3 ; Longitud de string para pedir las cadenas.
  mov ecx,MSG3    ;cambiamos el registro.
  call pedir_palabra  ; oedunis la palabra
  
  ; guardamos la cadena 3
  mov ecx,cad3 ; guardar en cadena3
  mov edx,20d ; leeremos 50 bytes posibles de la cadena.
  call guardar_palabra ; guardamos en la cadena

  mov esi,cad1
  mov edi,cad4
  mov ecx, cad2
  mov eax ,cad3
  jmp cadena1

cadena1:
  mov dl, byte[esi]
  cmp dl,0xA
  je cadena2
  mov byte[edi], dl
  inc esi
  inc edi
cadena2:
  mov dl, byte[ecx]
  cmp dl,0xA
  je cadena3
  mov byte[edi], dl
  inc ecx
  inc edi
cadena3:
  mov dl, byte[eax]
  cmp dl,0xA
  je mostrar
 
  mov byte[edi], dl
  inc eax
  inc edi
  jmp cadena1
mostrar:  
  inc edi
  mov dl, EOL
  mov byte[edi], dl
  mov edx, 60d
  mov ecx, cad4
  mov ebx,STDIN
  mov eax, SYS_WRITE
  int STOP
  ;Fin de programa
  jmp fin

pedir_palabra:
  mov ebx, STDOUT ; salida video.
  mov eax, SYS_WRITE ; LLamada para escribir
  int STOP ;  interrupcion
  ret 
guardar_palabra:
  mov eax,SYS_READ ; lectura
  mov ebx,STDIN ; entrada estandar.
  int STOP ; interrupcion
  ret ; regresamos

fin: 
  mov eax,SYS_EXIT  ;salida del programa
  int STOP    ; interrupcion al sistema