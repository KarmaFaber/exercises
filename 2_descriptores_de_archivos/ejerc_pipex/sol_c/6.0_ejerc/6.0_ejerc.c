/*
6.0 **Redirección de entrada estándar:**
    - Leer desde un Archivo en Lugar de la Terminal. 
	Redirige la entrada estándar para que lea desde un archivo `input.txt`.
    -ejemplo bash: wc -w < input.txt

	cc -Wall -Werror -Wextra 6.0_ejerc.c -o 6.0_ejerc
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

	//save_stdin:
	saved_stdin=dup(STDIN_FILENO);

	//open fd
	fd = open ("input.txt", O_RDONLY);
	if(fd ==-1)
	{
        perror ("error al abrir el archivo ");
        return (1);
    }

	// Redirige la entrada estándar para que lea desde input.txt
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("error al redirigir stdin");
		close(fd);
		return (1);
	}
	close(fd);

	//variables de execve
	char *argv[]= {"/bin/wc", "-w", NULL};
	char *envp[]={NULL};

	//execve
	if(execve("/bin/wc", argv, envp) == -1)
	{
		perror ("error al ejecutar execve");
		close(saved_stdin);
		return (1);
	}

	//restaurar stdin original
	if (dup2(saved_stdin, STDIN_FILENO) == -1)
	{
		perror("error al restaurar stdin");
		close(saved_stdin);
		return (1);
	}
	close(saved_stdin);

	return (0);
}


/*Error en la llamada execve: 
Al ejecutar execve(), el programa reemplazará el proceso actual con el proceso nuevo 
(en este caso, wc), por lo que si todo funciona correctamente, no se debería ejecutar 
ningún código posterior a la llamada de execve (es decir, no se ejecutará la restauración 
de stdin ni nada más después de execve). Sin embargo, si quieres asegurarte de que el flujo 
de entrada se restaure cuando execve no funcione, está bien dejar el código de restauración 
después de execve.*/