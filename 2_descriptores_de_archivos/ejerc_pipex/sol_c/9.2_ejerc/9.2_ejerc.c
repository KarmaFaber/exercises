/*
9.2 **Redirección combinada:**
    Modificar Texto Durante la Copia. 
    Escribe un programa que redirija la entrada estándar a un archivo llamado input.txt y la salida estándar a 
    un archivo llamado output.txt. El programa debe leer línea por línea el contenido de input.txt, convertirlo a mayúsculas, 
    y escribir el resultado en output.txt.


	cc -Wall -Werror -Wextra 9.2_ejerc.c -o 9.2_ejerc
*/

#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2, dup
#include <fcntl.h> // open
#include <stdlib.h> //exit
#include <string.h> //strlen


void modif_and_write_buffer(int fd, char *buffer)
{
	int i = 0;
	while(buffer[i] != '\0')
	{
		if (buffer[i] >= 'a' && buffer[i] <= 'z')
		{
			buffer[i] -=32;
		}
		write(fd, &buffer[i], 1);
		i++;
	}
}

int main (void)
{
	int fd;
	char buffer[1000];
	ssize_t readed_bites;
	int saved_stdin;

	fd = open ("input.txt", O_RDONLY);
	if (fd == -1)
	{
		perror ("error al abrir fd en read");
		return (1);
	}

	saved_stdin = dup(STDIN_FILENO);
	if (saved_stdin == -1)
	{
		perror("error al duplicar stdin");
		close (fd);
		return (1);
	}

	//redifigir stdin al archivo
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("error al duplicar stdin");
		close(fd);
		close(saved_stdin);
		return (1);
	}
	close(fd);

	//read fd
    readed_bites = read(STDIN_FILENO, buffer, sizeof(buffer)-1);
    if (readed_bites == -1)
    {
        perror("error al leer el archivo");
        close(saved_stdin);
        return (1);
    }
    buffer[readed_bites] ='\0';


	// Restaurar stdin original
    if (dup2(saved_stdin, STDIN_FILENO) == -1)
    {
        perror("Error al restaurar stdin");
        close(saved_stdin);
        return (1);
    }
    close(saved_stdin); // Cerrar el descriptor duplicado

	// escribir en destination.txt
	//open write_only
    fd = open ("output.txt", O_WRONLY);
	if (fd == -1)
	{
		perror ("error al abrir fd en write");
		return (1);
	}

	//write modif buffer in destination.txt
	modif_and_write_buffer(fd, buffer);
	//write(fd, buffer, strlen(buffer));

	//close fd
    if (close(fd) == -1)
    {
        perror ("error al cerrar el fd");
        return 1;
    }

	return (0);
}