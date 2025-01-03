/*
9.4 **delete file con unlink**
    -usar fucnion unlink en un programa.

	cc -Wall -Werror -Wextra 9.4_ejerc.c -o 9.4_ejerc
*/

#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2, dup
#include <fcntl.h> // open
#include <stdlib.h> //exit

int main (void)
{
	int fd;

	//open
	fd = open("output.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);     	//escritura y lectura (O_RDWR) con añadir datos al archivo (APPEND)
	if (fd == -1)
	{
		perror ("error al abrir el archivo o crearlo");
		return (1);
	}

	//	write
	write(fd, "hola", 4);


	//close
	if (close (fd) == -1)
	{
		perror("error al cerrar fd");
		return (1);
	}

	unlink("output.txt");

	return (0);
}