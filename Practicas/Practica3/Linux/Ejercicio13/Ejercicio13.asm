; Programe una calculadora dando opciones al usuario , los valores deben tomar un rango de 0 a 255 
; NOTA : Los valores no los ingresa el usuario como tal, si no que esta dentro del codigo.
; si se quire modificar la operacion se debe modificar el valor dentro del cofigo de las variables
; num1 y num2

section .data  
    ; Definiendo las constantes.
    %define SYS_EXIT    1   ; Salida
    %define SYS_READ    3   ; llamada al sistema "sys_read"
    %define SYS_WRITE   4   ; llamada al sistema para escribir
    %define STDIN       0   ; llamada para entrada standart
    %define STDOUT      1   ; llamada de salida estandar.
    %define EOL         0xA ; Salto de linea
    %define STOP        0x80 ; Interrupcion apra llamadas al sistema en windows.

    ; Mensajes    
    msg1    db     EOL,EOL,'----------Calculadora------',EOL  
    lmsg1   equ $ - msg1  
  
    msg2    db  EOL,'-------------VALORES DE LOS NUMEROS HARDCODEADO  num1: 50 y num2: 10-------'
    lmsg2   equ $ - msg2  
  
    msgSuma    db  EOL,'1. Sumar',EOL
    lmsgSuma   equ $ - msgSuma  
  
    msgResta   db '2. Restar',EOL
    lmsgResta  equ $ - msgResta  
  
    msgMult     db  '3. Multiplicar',EOL
    lmsgMult    equ $ - msgMult  
  
    msgDiv      db  '4. Dividir',EOL
    lmsgDiv     equ     $ - msgDiv
  
    msgOpc      db   'Operacion: '
    lmsgOpc     equ  $ - msgOpc  
  
    msgResut    db   EOL,'Resultado: ',EOL
    lmsgResut   equ  $ - msgResut  
  
    msgErro     db EOL,'Opcion Invalida',EOL
    lmsgErro    equ $ - msgErro

    ADIOS db 0xA,"ADIOS",0xA
    lon equ $- ADIOS
  

section .bss  

    opcion     resw    2  
    num1       resw    2  
    num2       resw    2 
    resultado  resw    2
    cent      resd 1
    deci      resd 1
    uni       resd 1 
  
section .text  
    global _start  
  
_start:

    ; CODIGO HARDCODEADO
    ; -----------------------------------------------------------------------------------
                                    mov byte [num1],50d
                                    mov byte [num2],10d
    ;------------------------------------------------------------------------------------

    ; Imprimimos en pantalla el mensaje 
    mov eax, SYS_WRITE  
    mov ebx, STDOUT
    mov ecx, msg2
    mov edx, lmsg2  
    int STOP

    ; Imprimimos en pantalla el mensaje 
    mov eax, SYS_WRITE  
    mov ebx, STDOUT
    mov ecx, msg1  
    mov edx, lmsg1  
    int STOP

    call menu
    ; Obtenemos la opcion seleccionada por el usuario  
    mov ebx, 0  
    mov ecx, opcion  
    mov edx, 2  
    mov eax, 3  
    int STOP 

    mov ah, [opcion]    ; Movemos la opcion seleccionada a el registro AH  
    sub ah, '0'     ; Convertimos el valor ingresado de ascii a decimal  
  
    ; Comparamos el valor ingresado por el usuario para saber que operacion realizar.  
    ; JE = Jump if equal = Saltamos si el valor comparado es igual  
    
    cmp ah, 1  
    je sumar  
  
    cmp ah, 2  
    je restar  
  
    cmp ah, 3  
    je multiplicar  
  
    cmp ah, 4  
    je dividir  
    
    ; Si el valor ingresado no cumple con ninguna de las condiciones anteriores entonces mostramos un mensaje de error y finalizamos  
    ; la ejecucion del programa  
    mov eax, SYS_WRITE  
    mov ebx, STDOUT  
    mov ecx, msgErro  
    mov edx, lmsgErro  
    int STOP 
  
menu:
    ; Imprimimos en pantalla el mensaje 
    mov eax, SYS_WRITE  
    mov ebx, STDOUT  
    mov ecx, msgSuma  
    mov edx, lmsgSuma  
    int STOP 
  
    ; Imprimimos en pantalla el mensaje 
    mov eax, SYS_WRITE  
    mov ebx, STDOUT  
    mov ecx, msgResta  
    mov edx, lmsgResta  
    int STOP  
  
    ; Imprimimos en pantalla el mensaje 
    mov eax, SYS_WRITE  
    mov ebx, STDOUT  
    mov ecx, msgMult  
    mov edx, lmsgMult  
    int STOP  
  
    ; Imprimimos en pantalla el mensaje 
    mov eax, SYS_WRITE  
    mov ebx, STDOUT  
    mov ecx, msgDiv  
    mov edx, lmsgDiv  
    int STOP  
  
    ; imprmir ociones 
    mov eax, SYS_WRITE  
    mov ebx, STDOUT  
    mov ecx, msgOpc  
    mov edx, lmsgOpc  
    int STOP  
    
    ret

sumar:

    ; Movemos los numeros ingresados a los registro 
    mov eax, [num1]
    mov ebx, [num2]
    
    ; Sumamos el registros
    add eax, ebx
 
    ; Movemos el resultado a un espacio reservado en la memoria
    mov [resultado], eax
    jmp terminar
     
    ; Imprimimos en pantalla el mensaje 
    mov eax, SYS_WRITE  
    mov ebx, STDOUT  
    mov ecx, msgResut  
    mov edx, lmsgResut  
    int STOP 
  
    ; Imprimimos en pantalla el resultado  
    mov eax, SYS_WRITE  
    mov ebx, STDOUT  
    mov ecx, resultado  
    mov edx, STDOUT
    int STOP 
 

restar:  
    ; Movemos los numeros ingresados a los registro
    mov eax, [num1]
    mov ebx, [num2]
    
    ; Sumamos el registros
    sub eax, ebx
 
    ; Movemos el resultado a un espacio reservado en la memoria
    mov [resultado], eax
    jmp terminar

    ; Imprimimos en pantalla el mensaje 
    mov eax, SYS_WRITE  
    mov ebx, STDOUT  
    mov ecx, msgResut  
    mov edx, lmsgResut  
    int STOP 
  
    ; Imprimimos en pantalla el resultado  
    mov eax, SYS_WRITE  
    mov ebx, STDOUT  
    mov ecx, resultado  
    mov edx, STDOUT  
    int STOP 

multiplicar: 

    ; Movemos los numeros ingresados a los registro AL y BL  
    mov al, [num1]  
    mov bl, [num2]  
  
    ; Multiplicamos. AX = AL X BL  
    mul bl  
    ; Movemos el resultado a un espacio reservado en la memoria  
    mov [resultado], ax  
    jmp terminar

    ; Imprimimos en pantalla el mensaje 
    mov eax, SYS_WRITE  
    mov ebx, STDOUT  
    mov ecx, msgResut  
    mov edx, lmsgResut  
    int STOP 
  
    ; Imprimimos en pantalla el resultado  
    mov eax, SYS_WRITE  
    mov ebx, STDOUT  
    mov ecx, resultado  
    mov edx, STDOUT  
    int STOP 

  
dividir:  
    ; Movemos los numeros ingresados a los registro AL y BL
    mov al, [num1]
    mov bl, [num2]
 
    ; Igualamos a cero los registros DX y AH
    mov dx, 0
    mov ah, 0
 
    ; Division. AL = AX / BL. AX = AH:AL
    div bl
 
    ; Movemos el resultado a un espacio reservado en la memoria
    mov [resultado], ax
    jmp terminar
    ; Imprimimos en pantalla el mensaje 
    mov eax, SYS_WRITE  
    mov ebx, STDOUT  
    mov ecx, msgResut  
    mov edx, lmsgResut  
    int STOP 
  
    ; Imprimimos en pantalla el resultado  
    mov eax, SYS_WRITE  
    mov ebx, STDOUT  
    mov ecx, resultado  
    mov edx, STDOUT  
    int STOP 


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

    ;Mensaje de bienvenida al programa
    mov edx,1d      ; Longitud de string para pedir las cadenas.
    mov ecx,cent        ; Mensaje de bienvenida
    mov ebx,STDOUT      ; salida estandar.
    mov eax,SYS_WRITE   ; LLamada al sistema sys_write
    int STOP

    mov edx,1d      ; Longitud de string para pedir las cadenas.
    mov ecx,deci        ; Mensaje de bienvenida
    mov ebx,STDOUT      ; salida estandar.
    mov eax,SYS_WRITE   ; LLamada al sistema sys_write
    int STOP
    
    mov edx,1d      ; Longitud de string para pedir las cadenas.
    mov ecx,uni     ; Mensaje de bienvenida
    mov ebx,STDOUT      ; salida estandar.
    mov eax,SYS_WRITE   ; LLamada al sistema sys_write
    int STOP    

    jmp fin
terminar:
    mov  ax,[resultado]
    cmp  ax,100
    jl   menorCienConverter
    jge  mayorCienConverter


fin:
    mov edx,lon         ; Longitud de string para pedir las cadenas.
    mov ecx,ADIOS       ; Mensaje de bienvenida
    mov ebx,STDOUT      ; salida estandar.
    mov eax,SYS_WRITE   ; LLamada al sistema sys_write
    int STOP

    mov eax,SYS_EXIT    ;salida del programa
    int STOP        ; interrupcion al sistema
