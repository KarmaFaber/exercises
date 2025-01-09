/*
12.0 **Concatenar archivos usando pipes:**
    - Usa un pipe para leer dos archivos `file1.txt` y `file2.txt` y concatenar sus contenidos en la salida estándar.
Enfoque:
	Crear un pipe para comunicar entre procesos.
	Abrir los archivos (archivo1.txt y archivo2.txt) con open.
	Crear un proceso hijo para manejar uno de los archivos y escribir su contenido en el pipe.
	El proceso padre leerá del pipe y lo escribirá en la salida estándar.
	Concatenar ambos archivos con el pipe.


bash: 	cat file1.txt file2.txt | cat

archivo1.txt 
archivo2.txt

cc -Wall -Werror -Wextra 12.0_ejerc.c -o 12.0_ejerc

*/

#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2, dup
#include <fcntl.h> // open
#include <stdlib.h> //exit
#include <sys/wait.h> //wait


int main(void)
{
	int fd_1;
	int fd_2;
	int pipfd[2];
	pid_t pid;
	ssize_t bytes_read;
	char buffer[1024];

	if (pipe(pipfd) == -1)
	{
		perror("error al crear pipe");
		return (1);
	}

	fd_1 = open ("archivo1.txt", O_RDONLY, 0644);
	if (fd_1==-1)
	{
		perror("error al abrir archivo1. ");
		return 1;		
	}

	pid = fork();
	if (pid == -1)
	{
		perror ("error al crear pid");
		return (1);
	}

	if (pid ==0)   // Proceso hijo
	{
		// En el hijo, redirigir la salida del pipe
        close(pipfd[0]);  // Cerrar el extremo de lectura del pipe

		while ((bytes_read = read(fd_1, buffer, sizeof(buffer))) > 0) 
		{
            write(pipfd[1], buffer, bytes_read);  // Escribir en el pipe
        }
		close(pipfd[1]);  // Cerrar el extremo de escritura del pipe
        close(fd_1);        // Cerrar el archivo

        exit(0);  // Terminar el proceso hijo
	}
	else   // Proceso padre
	{
		fd_2 = open ("archivo2.txt", O_RDONLY, 0644);
		if (fd_2==-1)
		{
			perror("error al abrir archivo2. ");
			return 1;		
		}

		// En el padre, redirigir la entrada del pipe
        close(pipfd[1]);  // Cerrar el extremo de escritura del pipe

		// Leer del pipe (contenido de archivo1.txt) y escribir en la salida estándar
		while ((bytes_read = read(pipfd[0], buffer, sizeof(buffer))) > 0) 
		{
            write(STDOUT_FILENO, buffer, bytes_read);  // Escribir en salida estándar
        }

		// Leer de archivo2.txt y escribir en la salida estándar
		while ((bytes_read = read(fd_2, buffer, sizeof(buffer))) > 0) 
		{
            write(STDOUT_FILENO, buffer, bytes_read);  // Escribir en salida estándar
        }

		close(pipfd[0]);  // Cerrar el extremo de lectura del pipe
        close(fd_2);        // Cerrar el archivo

        // Esperar a que termine el proceso hijo
        wait(NULL);
	}

	return (0);
}