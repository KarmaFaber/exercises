/*
6.2 **Redirección de entrada estándar:**
    Redirección Temporal de Entrada. 
    Escribe un programa que redirija temporalmente la entrada estándar a un archivo llamado temp_input.txt, 
    lea una línea de texto del archivo y la almacene en un buffer.  (lee, todo el texto del archivo).
    Luego restaura la entrada estándar y muestra el contenido leído en la terminal.


	cc -Wall -Werror -Wextra 6.2_ejerc.c -o 6.2_ejerc
*/

#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2, dup
#include <fcntl.h> // open
#include <stdlib.h> //exit
#include <string.h> // strlen


int main (void)
{
	int fd;
	char buffer[1000];
	ssize_t readed_bites;
	int saved_stdin;

	fd = open ("temp_input.txt", O_RDONLY);
	if (fd == -1)
	{
		perror ("error al abrir fd");
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


	// Restaurar stdout original
    if (dup2(saved_stdin, STDIN_FILENO) == -1)
    {
        perror("Error al restaurar stdin");
        close(saved_stdin);
        return (1);
    }
    close(saved_stdin); // Cerrar el descriptor duplicado

	// Imprimir el valor del número
    printf("El contenido del archivo es %s\n", buffer);

	return (0);
}