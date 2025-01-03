/*
6.1 **Redirección de entrada estándar:**
    Simular Entrada desde un Archivo. 
    Escribe un programa que cree un archivo llamado simulated_input.txt, escriba la línea "42", y 
    luego redirija la entrada estándar a este archivo. 
    Usa scanf para leer el número del archivo e imprime su valor en la terminal.

	cc -Wall -Werror -Wextra 6.1_ejerc.c -o 6.1_ejerc
*/

#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2, dup
#include <fcntl.h> // open
#include <stdlib.h> //exit
#include <string.h>

int main (void)
{
	int fd;
	int saved_stdin;
	int num;

	//open 
	fd = open("simulated_input.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror ("error al abrir o crear file");
		return (1);
	}

	//saved_stdin:
	saved_stdin = dup(STDIN_FILENO);
	if (saved_stdin == -1)
    {
        perror ("error al duplicar stdout");
        close(fd);
        return (1);
    }

	//write
	write(fd, "42", 2);
	close (fd);

	// Redirigir stdin para que lea desde "simulated_input.txt"
    fd = open("simulated_input.txt", O_RDONLY);  // Reabrimos el archivo en modo lectura
    if (fd == -1)
    {
        perror("error al abrir el archivo para lectura");
        close(saved_stdin);
        return (1);
    }

	//redirigir stdin
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("error al duplicar stdin");
		close(fd);
		close(saved_stdin);
		return (1);
	}
	close (fd);
	
	 // Leer el número desde stdin (ahora redirigido al archivo)
    if (scanf("%d", &num) != 1)
    {
        perror("error al leer el número");
        // Restaurar stdin y salir
        dup2(saved_stdin, STDIN_FILENO);
        close(saved_stdin);
        return (1);
    }

	// Restaurar stdout original
    if (dup2(saved_stdin, STDIN_FILENO) == -1)
    {
        perror("Error al restaurar stdin");
        close(saved_stdin);
        return (1);
    }
    close(saved_stdin); // Cerrar el descriptor duplicado
	
	// Imprimir el valor del número
    printf("El numero del archivo es: %d\n", num);

	return (0);
}