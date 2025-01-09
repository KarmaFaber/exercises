/*
11. **Redirección de errores estándar:**
    - Escribe un programa que redirija el error estándar a un archivo `error.log` y genere un error intencionado (por ejemplo, intentando abrir un archivo inexistente).

cc -Wall -Werror -Wextra 11_ejerc.c -o 11_ejerc

*/

#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2, dup
#include <fcntl.h> // open
#include <stdlib.h> //exit

int main(void)
{
	int fd;
	int fd_log;

	//open fd_log:
	fd_log = open ("error.log", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_log == -1)
	{
		perror("Error al abrir error.log");
		return (1);
	}
	
	// Redirigir STDERR_FILENO al archivo error.log
    if (dup2(fd_log, STDERR_FILENO) == -1)
    {
        perror("Error al redirigir STDERR");
        close(fd_log);
        return (1);
    }

	// Cerrar el descriptor original del archivo ya que no se necesita más
    close(fd_log);

	fd =open("notexistfile.txt", O_RDONLY, 0777);
	if (fd == -1)
	{
		perror("Error al intentar abrir notexistfile.txt");
        // Aquí el error será redirigido a error.log
	}

	


	return (0);
}

