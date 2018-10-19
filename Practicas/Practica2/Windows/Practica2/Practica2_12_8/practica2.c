/*
	En este pequeño programa usando los archivos creados en el programa practica2_8
	utilizando llamadas al sistema desarrollar una programa en C qie liste todos los
	archivos creados , mostrando su tamalo , fecha y hora de accseso
	path de prueba : /root/Documentos/ESCOM/SO/Practicas/Practica2/Practica2_10
*/
#include <stdio.h>
#include "archivos.h"

int main(int argc, char const *argv[])
{
	int numero;
	archivo arch;
	int i; // contador
	int fd;
	char *pathTemp;

	printf("\n Teclea el numero de archivos a crear (Maximo=16) \n");
	scanf("%d",&numero);

	printf("\n Especifica la ruta donde se crearan los archivos : ");
	
	scanf("%s",&arch.path);
	pathTemp = arch.path;
	strcat(arch.path,"/");
	archivo archivos[16];
	// poniendo los nombres y definiendo los archivos a crear
	strcpy(archivos[0].nombre , "archivo0.txt"); 
	strcpy(archivos[1].nombre , "archivo1.txt"); 
	strcpy(archivos[2].nombre , "archivo2.txt"); 
	strcpy(archivos[3].nombre , "archivo3.txt"); 
	strcpy(archivos[4].nombre , "archivo4.txt"); 
	strcpy(archivos[5].nombre , "archivo5.txt"); 
	strcpy(archivos[6].nombre , "archivo6.txt"); 
	strcpy(archivos[7].nombre , "archivo7.txt"); 
	strcpy(archivos[8].nombre , "archivo8.txt"); 
	strcpy(archivos[9].nombre , "archivo9.txt");
	strcpy(archivos[10].nombre , "archivo10.txt");
	strcpy(archivos[11].nombre , "archivo11.txt");
	strcpy(archivos[12].nombre , "archivo12.txt");
	strcpy(archivos[13].nombre , "archivo13.txt");
	strcpy(archivos[14].nombre , "archivo14.txt");
	strcpy(archivos[15].nombre , "archivo15.txt");


	// Poniendo el contenido del archivo
	strcpy(archivos[0].contenido , "No hay caminos para la paz; la paz es el camino (Mahatma Gandhi).");
	strcat(archivos[0].contenido," \0"); 

	strcpy(archivos[1].contenido , "Haz el amor y no la guerra (John Lennon). "); 
	strcat(archivos[1].contenido," \0");	
	
	strcpy(archivos[2].contenido , "Aprende a vivir y sabrás morir bien (Confucio). "); 
	strcat(archivos[2].contenido," \0");
	
	strcpy(archivos[3].contenido , "Cada día sabemos más y entendemos menos (Albert Einstein). "); 
	strcat(archivos[3].contenido," \0");
	
	strcpy(archivos[4].contenido , "El mundo no está en peligro por las malas personas sino por aquellas que permiten la maldad (Albert Einstein). \0"); 
	strcat(archivos[4].contenido," \0");

	strcpy(archivos[5].contenido , "No hay nada que un hombre no sea capaz de hacer cuando una mujer le mira (Casanova)  "); 
	strcat(archivos[5].contenido," \0");

	strcpy(archivos[6].contenido , "La mayor declaración de amor es la que no se hace; el hombre que siente mucho, habla poco (Platón)  "); 
	strcat(archivos[6].contenido," \0");
	
	strcpy(archivos[7].contenido , "Si das pescado a un hombre hambriento lo nutres durante una jornada. Si le enseñas a pescar, le nutrirás toda su vida (Lao Tsé) "); 
	strcat(archivos[7].contenido," \0");
	
	strcpy(archivos[8].contenido , "No estoy tan enamorado de mis propias opiniones que ignore lo que los demás puedan pensar acerca de ellas (Copérnico) "); 
	strcat(archivos[8].contenido," \0");

	strcpy(archivos[9].contenido , "El sabio no dice nunca todo lo que piensa, pero siempre piensa todo lo que dice (Aristóteles) ");
	strcat(archivos[9].contenido," \0");

	strcpy(archivos[10].contenido , "Cómo desearía que estuvieras aquí. Sólo somos dos almas perdidas nadando en una pecera año tras año, corriendo sobre la misma tierra vieja. ¿Que hemos encontrado? Los mismos viejos temores…desearía que estuvieras aquí. \n – Wish you were here");
	strcat(archivos[10].contenido," \0");

	strcpy(archivos[11].contenido , "El dinero es un crimen, repártelo equitativamente pero no toques mi trozo del pastel.\n – Money");
	strcat(archivos[11].contenido," \0");

	strcpy(archivos[12].contenido , "Porque tu vida es larga y alto tu vuelo. Dedicarás sonrisas y llorarás lágrimas y todo lo que toques y todo lo que veas es todo lo que tu vida será.\n – Breathe ");
	strcat(archivos[12].contenido," \0");

	strcpy(archivos[13].contenido , "Tus labios se mueven pero no puedo oír lo que estás diciendo.\n – Comfortably numb ");
	strcat(archivos[13].contenido," \0");

	strcpy(archivos[14].contenido , "Hola mundo de los archivos y llamadas al sistema en Linux\n – Comfortably numb ");
	strcat(archivos[14].contenido," \0");


	strcpy(archivos[15].contenido , "Así que crees que puedes distinguir el Cielo del Infierno… \n – Wish you were here ");
	strcat(archivos[15].contenido," \0");

	// poniendo el mismo path a todos los archivos
	// añadimos el nombre de cada uno
	for(i = 0; i<15; i++){
		strcpy(archivos[i].path , arch.path); 
		strcat(archivos[i].path,archivos[i].nombre);
	}
	 
	if(numero > 16 || numero < 0)
	{
		// verficando si entra en rango
		printf(" Porfavor eliga un numero dentro del rango \n");
		return 0; // matamos el programa	
	}else
	{
		// aqui  comenzamos la creacion de los arvhivos
		// verificamos si la carpeta existe.
		for(i = 0; i<numero; i++)
		{
			fd = crearArchivo(&archivos[i],pathTemp);
			if(fd == -1){
				printf("Error al crear archivos \n");
			}
		}
	}
	return 0;
}