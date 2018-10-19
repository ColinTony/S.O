#	!bin/bash

#Programa:
# generador.sh

#Descripcion: 
#		Compila y enlaza un programa en NASM, asi no tendremos que estar ejecutando los mismos comandos en consola.

#Uso:
#	./generador.sh 	holamundo
# 	compila 		holamundo.asm
# 	enlaza 			holamundo.o
#	ejecutable		holamundo

#Verifica que haya capturado 1 argumento
if [ $# -eq 1 ] # Cuantos comandos recibio al llamarse el bash , obviamente debe haber uno.
then # el $1 es el argumento que se mando como parametro.
	#compilar y enlazar
	echo "Compilando..."
	nasm -f elf $1.asm # Al parametro le aumentamos el .asm

	echo "Enlazzando..."
	ld -m elf_i386 -o $1 $1.o # aumentamos el .o jalando igual el argumento 1

	if [ $? -eq 0 ]
	then #Ejecutando el archivo generado
		echo -e "------------>Ejecutando<---------\n" #usamos salto de linea con-e
		./$1 #ejecutamos el prgrama usando el arguemnto.
	else
		echo "Error al compilar y enlazar">&2
	fi
else
	#Mensaje de error
	echo "<----------------ERROR------------------>"
	echo "Solo debes pasar un argumento y debe ser el archivo a compilar sin su extension"
	echo "Ejemplo : ./generador.sh HolaMundo"
	echo "obviamente debe exitir el archivo HolaMundo.asm"
fi
#Recordar que hay que darle permisos para ejecucion con chmod +x generador.sh