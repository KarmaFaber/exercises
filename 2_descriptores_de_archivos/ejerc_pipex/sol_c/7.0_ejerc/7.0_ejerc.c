/*
7.0 **Pipe básico-> pipe sin fork:**
    - Implementa un programa que cree un pipe, escriba "Hola, pipe!" en un extremo y lo lea del otro extremo para imprimirlo en pantalla.
    - ejemplo bash: echo "Hola, pipe!" | cat 
    - ejemplo bach: ls | wc -l

	cc -Wall -Werror -Wextra 7.0_ejerc.c -o 7.0_ejerc
*/

#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2, dup
#include <fcntl.h> // open
#include <stdlib.h> //exit
#include <string.h> // strlen

int main (void)
{
	int pipfd[2];
	char write_msg[]="hello pipe";
	char read_msg[100];

	//crear pipe:
	if (pipe(pipfd)== -1)
	{
		perror("error al crear pipe");
		return (1);
	}

	//escribir el pipe:
	write(pipfd[1], write_msg, strlen(write_msg)+1);

	//cerrar pipfd[1] escritura:
	close(pipfd[1]);

	//read pipe en pipfd[0]
	read(pipfd[0], read_msg, sizeof(read_msg));

	//cerrar pipfd[0] lectura:
	close(pipfd[0]);

	printf("datos leidos por pipfd[0]: %s\n", read_msg);

	return (0);
}