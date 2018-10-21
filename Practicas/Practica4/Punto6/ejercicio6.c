#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	char *argv[3];
	argv[0] = "/root/Documentos/ESCOM/SO/Practicas/Prueba/hola";
	argv[1] = "DESDE HIJO ";
	argv[2] = NULL;

	if((pid = fork()) == 0)
	{
		printf("Soy hijo ejecutado: %s \n",argv[0]);
		execv(argv[0],argv);
	}
	else
	{
		wait(0);
		printf("Soy el padre \n");
		exit(0);
	}
}