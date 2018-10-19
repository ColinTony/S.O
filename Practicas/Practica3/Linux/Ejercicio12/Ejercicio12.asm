; Programe una aplicacion en ensamblador que concanete 10 cadenas mostrando en pantalla 
; el resultado de las cadenas concatenadas en sentido inverso y ka kibgitud de ka cadena


segment .data  
; Definiendo las constantes.
    %define SYS_EXIT    1   ; Salida
    %define SYS_READ    3   ; llamada al sistema "sys_read"
    %define SYS_WRITE   4   ; llamada al sistema para escribir
    %define STDIN       0   ; llamada para entrada standart
    %define STDOUT      1   ; llamada de salida estandar.
    %define EOL         0xA ; Salto de linea
    %define STOP        0x80 ; Interrupcion apra llamadas al sistema en windows.

    ; pmensajes para pedir las cadenas.
    mensaje1 db 'Primer cadena:',EOL    ; primer cadena
    lon1 equ $-mensaje1  
    mensaje2 db 'Segunda cadena:',EOL  
    lon2 equ $-mensaje2  
    mensaje3 db 'Tercer cadena:',EOL  
    lon3 equ $-mensaje3  
    mensaje4 db 'Cuarta cadena:',EOL  
    lon4 equ $-mensaje4  
    mensaje5 db 'Quinta cadena:',EOL  
    lon5 equ $-mensaje5  
    mensaje6 db 'Sexta cadena:',EOL  
    lon6 equ $-mensaje6  
    mensaje7 db 'Septima cadena:',EOL  
    lon7 equ $-mensaje7  
    mensaje8 db 'Octava cadena:',EOL  
    lon8 equ $-mensaje8  
    mensaje9 db 'Novena cadena:',EOL  
    lon9 equ $-mensaje9  
    mensaje10 db 'Decima cadena:',EOL  
    lon10 equ $-mensaje10     
  
    mensaje11 db 'Concatenada:',EOL  
    lon11 equ $-mensaje11  
  
    mensaje12 db 'Sentido inverso:',EOL  
    lon12 equ $-mensaje12  
    mensaje14 db 'Longitud cadena:',EOL  
    lon14 equ $-mensaje14  

segment .bss  

    cadena1 resb 20  
    cadena2 resb 20  
    cadena3 resb 20  
    cadena4 resb 20  
    cadena5 resb 20  
    cadena6 resb 20  
    cadena7 resb 20  
    cadena8 resb 20  
    cadena9 resb 20  
    cadena10 resb 20     
  
    cadenotota resb 100  
    tatonodeca resb 100  
    atotonedac resb 100  
    lona resb 8  
    lonb resb 8  
    cont1 resb 8  
    cont2 resb 8  
    
segment .text  
    global _start  

    _start:  
        mov byte [cont1],0x30  
        mov byte [cont2],0x30  
        mov byte [lona],0x30  
        mov byte [lonb],0x30  
          
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,mensaje1  
        mov edx,lon1  
        int STOP  
        mov eax,SYS_READ  
        mov ebx,STDIN  
        mov ecx,cadena1  
        mov edx,20d  
        int STOP  
  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,mensaje2  
        mov edx,lon2  
        int STOP  
        mov eax,SYS_READ  
        mov ebx,STDIN  
        mov ecx,cadena2  
        mov edx,20d  
        int STOP  
  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,mensaje3  
        mov edx,lon3  
        int STOP  
        mov eax,SYS_READ  
        mov ebx,STDIN  
        mov ecx,cadena3  
        mov edx,50d  
        int STOP  
  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,mensaje4  
        mov edx,lon4  
        int STOP  
        mov eax,SYS_READ  
        mov ebx,STDIN  
        mov ecx,cadena4  
        mov edx,50d  
        int STOP  
  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,mensaje5  
        mov edx,lon5  
        int STOP  
        mov eax,SYS_READ  
        mov ebx,STDIN  
        mov ecx,cadena5  
        mov edx,20d  
        int STOP  
  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,mensaje6  
        mov edx,lon6  
        int STOP  
        mov eax,SYS_READ  
        mov ebx,STDIN  
        mov ecx,cadena6  
        mov edx,50d  
        int STOP  
  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,mensaje7  
        mov edx,lon7  
        int STOP  
        mov eax,SYS_READ  
        mov ebx,STDIN  
        mov ecx,cadena7  
        mov edx,50d  
        int STOP  
  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,mensaje8  
        mov edx,lon8  
        int STOP  
        mov eax,SYS_READ  
        mov ebx,STDIN  
        mov ecx,cadena8  
        mov edx,50d  
        int STOP  
  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,mensaje9  
        mov edx,lon9  
        int STOP  
        mov eax,SYS_READ  
        mov ebx,STDIN  
        mov ecx,cadena9  
        mov edx,50d  
        int STOP  
  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,mensaje10  
        mov edx,lon10  
        int STOP  
        mov eax,SYS_READ  
        mov ebx,STDIN  
        mov ecx,cadena10  
        mov edx,50d  
        int STOP  
  
        mov esi,cadena1  
        mov edi,cadenotota  
  
    contar:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne contar  
        mov esi,cadena2  
        sub edi,2  
  
    concatena1:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena1  
        mov esi,cadena3  
        sub edi,2  
      
    concatena2:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena2  
        mov esi,cadena4  
        sub edi,2  
  
    concatena3:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena3  
        mov esi,cadena5  
        sub edi,2  
  
    concatena4:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena4  
        mov esi,cadena6  
        sub edi,2  
  
    concatena5:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena5  
        mov esi,cadena7  
        sub edi,2  
  
    concatena6:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena6  
        mov esi,cadena8  
        sub edi,2  
  
    concatena7:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena7  
        mov esi,cadena9  
        sub edi,2  
  
    concatena8:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena8  
        mov esi,cadena10  
        sub edi,2  
  
  
    concatena9:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena9  
  
        int STOP  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,mensaje11  
        mov edx,lon11  
        int STOP  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,cadenotota  
        mov edx,100d  
        int STOP  
  
        mov esi,cadena10  
        mov edi,tatonodeca  
  
    contara:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne contara  
        mov esi,cadena9  
        sub edi,2  
  
    concatena1a:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena1a  
        mov esi,cadena8  
        sub edi,2  
      
    concatena2a:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena2a  
        mov esi,cadena7  
        sub edi,2  
  
    concatena3a:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena3a  
        mov esi,cadena6  
        sub edi,2  
  
    concatena4a:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena4a  
        mov esi,cadena5  
        sub edi,2  
  
    concatena5a:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena5a  
        mov esi,cadena4  
        sub edi,2  
  
    concatena6a:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena6a  
        mov esi,cadena3  
        sub edi,2  
  
    concatena7a:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena7a  
        mov esi,cadena3  
        sub edi,2  
  
    concatena8a:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena8a  
        mov esi,cadena2  
        sub edi,2  
  
    concatena9a:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena9a  
        mov esi,cadena1  
        sub edi,2  
  
  
    concatena10a:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp al,0  
        jne concatena10a      
  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,mensaje12  
        mov edx,lon12  
        int STOP  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,tatonodeca  
        mov edx,100d  
        int STOP  
  
        mov edi,cadenotota  
        mov esi,atotonedac  
  
    llenamos:  
        cmp byte [edi],0x00  
        je invierte  
        inc edi  
        inc byte [cont1]  
        inc byte [cont2]  
        jmp llenamos  
    invierte:  
        cmp byte [cont2],0x30  
        je acomoda  
        mov al,[edi-2]  
        mov [esi],al  
        dec byte [cont2]  
        dec edi  
        inc esi  
        jmp invierte  
    acomoda:  
          
        mov esi,cadenotota  
        mov edi,cadenotota  
  
    contarb:  
        mov al,[esi]  
        inc esi  
        mov [edi],al  
        inc edi  
        cmp byte [lona],0x39  
        jne sumarA  
        mov byte [lona],0x30  
        cmp byte [lonb],0x39  
        jne sumarB  
        mov byte [lonb],0x30  
        jmp fuera  
    sumarB:  
        add byte [lonb],1d  
        jmp fuera  
    sumarA:  
        add byte [lona],1d  
      
    fuera:  
        cmp al,0  
        jne contarb  
        int STOP  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,mensaje14  
        mov edx,lon14  
        int STOP  
        sub byte[lona],2d  
        cmp byte[lona],'.'  
        jne noHacer  
        mov byte[lona],'8'  
        sub byte[lonb],1d  
    noHacer:  
        cmp byte[lona],'/'  
        jne noHacerNada  
        mov byte[lona],'9'  
        sub byte[lonb],1d   
      
    noHacerNada:  
        cmp byte[lonb],0x30  
        je imprimoA  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,lonb  
        mov edx,8d  
        int STOP  
    imprimoA:  
        mov eax,SYS_WRITE  
        mov ebx,STDOUT  
        mov ecx,lona  
        mov edx,8d  
        mov byte[ecx+1],EOL  
        int STOP  
        mov eax,1  
        int STOP