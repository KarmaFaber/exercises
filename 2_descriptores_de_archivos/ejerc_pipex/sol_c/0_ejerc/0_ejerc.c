/*
	0. **gnl_stdin**
    - coger los datos de fd 0 (stdin) y mandarlos a un archivo. 

cc -Wall -Werror -Wextra 0_ejerc.c -o 0_ejerc
*/

#include <stdio.h> //perror
#include <unistd.h> // read
#include <fcntl.h> // open

int main (void)
{
	int fd;
	char buffer[100];
	ssize_t readed_bytes;

	//open
	fd = open ("output_0.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror ("error al abrir el archivo o crearlo");
		return (1);
	}

	//read
	// Lee desde la entrada estándar (stdin) en un bucle hasta EOF (Ctrl+D)
    while ((readed_bytes = read(0, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[readed_bytes] = '\0';  // Añade el terminador nulo
        
        // Escribe en el archivo
        int i = 0;
        while (buffer[i] != '\0')
        {
            write(fd, &buffer[i], 1);
            i++;
        }
    }

	//write
	int i = 0;
	while(buffer[i] != '\0')
	{
		write(fd, &buffer[i], 1);
		i++;
	}

	//close
	if (close (fd) == -1)
	{
		perror("error al cerrar fd");
		return (1);
	}
	return (0);
}



//esta vercion solo lee una linea de FD 0, no me registra los saltos de linea 
/*
#include <stdio.h>    // perror
#include <unistd.h>   // read
#include <fcntl.h>    // open

int main(void)
{
    int fd;
    char buffer[100];
    ssize_t readed_bytes;

    // Abre el archivo
    fd = open("output_0.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd == -1)
    {
        perror("Error al abrir el archivo o crearlo");
        return (1);
    }

    // Lee desde la entrada estándar (stdin) en lugar de stdout
    readed_bytes = read(0, buffer, sizeof(buffer) - 1);  // 0 es stdin
    if (readed_bytes == -1)
    {
        perror("Error al leer desde la entrada");
        close(fd);
        return (1);
    }
    buffer[readed_bytes] = '\0';  // Añade el terminador nulo

    // Escribe en el archivo
    int i = 0;
    while (buffer[i] != '\0')
    {
        write(fd, &buffer[i], 1);
        i++;
    }

    // Cierra el descriptor de archivo
    if (close(fd) == -1)
    {
        perror("Error al cerrar fd");
        return (1);
    }

    return (0);
}

*/