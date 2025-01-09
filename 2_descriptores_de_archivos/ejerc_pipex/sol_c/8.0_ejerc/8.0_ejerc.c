/*
8.0 **Multiprocesos con `fork` y pipes && wait o waitpid:**
    - Crea un programa donde el proceso padre escriba en el pipe y el proceso hijo lea del pipe e imprima el contenido.
    - utiliza las fucniones wait o waitpid

	cc -Wall -Werror -Wextra 8.0_ejerc.c -o 8.0_ejerc
*/


#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2, dup
#include <fcntl.h> // open
#include <stdlib.h> //exit
#include <string.h> // strlen
#include <sys/wait.h> //wait

int main (void)
{
	int pipfd[2];
	pid_t pid;
    char write_msg[] = "Hola, pipe!";
    char read_msg[100];
	int status;

	//crear pipe:
	if (pipe(pipfd) == -1)
	{
		perror("error al crear pipe");
		return (1);
	}

	//crear proceso hijo:
	pid=fork();
	if (pid == -1)
	{
		perror("error al crear proceso hijo");
		return (1);
	}

	printf("pid: %i\n", pid);
	
	//operar con procesos padre e hijo: la misma logica que en el ejerc 7.0_ejerc.c
	if (pid == 0) 	//el hijo escribe
	{
		close(pipfd[0]);
		write(pipfd[1], write_msg, strlen(write_msg)+1);
		close(pipfd[1]);
		printf("El hijo terminó y sale.\n");
		_exit(0); // Terminar el hijo
	}
	else		//el padre lee
	{
		close(pipfd[1]);
		read(pipfd[0], read_msg, sizeof(read_msg));
		//wait(NULL); // Espera a que el hijo termine
		waitpid(pid, &status, 0); // Espera al hijo específico
		printf ("el mensaje enviado es: %s\n", read_msg);
		close(pipfd[0]);
		printf("El hijo terminó con estado %d\n", WEXITSTATUS(status));
		printf("El padre terminó.\n");
	}

	return (0);
}