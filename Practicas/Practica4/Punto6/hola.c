#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char mensaje[100];
	strcpy(mensaje,"Hola mundo");
	strcat(mensaje,argv[1]);
	printf("%s\n", mensaje);
	exit(0);
	return 0;
}