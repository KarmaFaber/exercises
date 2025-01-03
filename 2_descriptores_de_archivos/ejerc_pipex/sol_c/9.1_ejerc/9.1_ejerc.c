/*
9.1 **Redirección combinada:**
    escribir y leer datos de stdin, guardarlos en un archivo e imprimirlos en terminal.


	cc -Wall -Werror -Wextra 9.1_ejerc.c -o 9.1_ejerc
*/

#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2, dup
#include <fcntl.h> // open
#include <stdlib.h> //exit
#include <string.h> //strlen


int main (void)
{
	int fd;
	char buffer[1000];
	ssize_t readed_bites;

	// escribir en destination.txt
	//open write_only
    fd = open ("destination.txt", O_WRONLY);
	if (fd == -1)
	{
		perror ("error al abrir fd en write");
		return (1);
	}

	
	//read
	// Lee desde la entrada estándar (stdin) en un bucle hasta EOF (Ctrl+D)
    while ((readed_bites = read(0, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[readed_bites] = '\0';  // Añade el terminador nulo
        
        // Escribe en el archivo
        int i = 0;
        while (buffer[i] != '\0')
        {
            write(fd, &buffer[i], 1);
            i++;
        }
    }

	//write buffer in destination.txt
	write(fd, buffer, strlen(buffer));
	write(1, buffer, strlen(buffer));

	//close fd
    if (close(fd) == -1)
    {
        perror ("error al cerrar el fd");
        return 1;
    }

	return (0);
}