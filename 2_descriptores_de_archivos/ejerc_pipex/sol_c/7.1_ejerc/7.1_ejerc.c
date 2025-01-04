/*
7.1 **Pipe básico-> pipe con fork:**
    - Implementa un programa que cree un pipe, escriba "Hola, pipe!" en un extremo y lo lea del otro extremo para imprimirlo en pantalla.
    - ejemplo bash: echo "Hola, pipe!" | cat 
    - ejemplo bach: ls | wc -l


	cc -Wall -Werror -Wextra 7.1_ejerc.c -o 7.1_ejerc
*/

#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2, dup
#include <fcntl.h> // open
#include <stdlib.h> //exit
#include <string.h> // strlen

int main (void)
{
	int pipfd[2];
	pid_t pid;
    char write_msg[] = "Hola, pipe!";
    char read_msg[100];

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

	//operar con procesos padre e hijo: la misma logica que en el ejerc 7.0_ejerc.c
	if (pid == 0) 	//el hijo escribe
	{
		close(pipfd[0]);
		write(pipfd[1], write_msg, strlen(write_msg)+1);
		close(pipfd[1]);
	}
	else		//el padre lee
	{
		close(pipfd[1]);
		read(pipfd[0], read_msg, sizeof(read_msg));
		printf ("el mensaje enviado es: %s\n", read_msg);
		close(pipfd[0]);
	}

	return (0);
}