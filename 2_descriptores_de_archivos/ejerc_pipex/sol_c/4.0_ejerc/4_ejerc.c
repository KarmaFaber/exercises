/*
4. **Copiar el contenido de un archivo:**
    - Escribe un programa que copie el contenido de `source.txt` a `destination.txt`.


cc -Wall -Werror -Wextra 4_ejerc.c -o 4_ejerc
*/

#include <stdio.h> //perror
#include <unistd.h> // read
#include <fcntl.h> // open
#include <string.h> // strerror
#include <errno.h>	//errno+referencias de error

int main (void)
{
	int fd_1;	//source.txt
	int fd_2;	// destination.txt
	char buffer[100];
	ssize_t readed_bytes;

	//open
	//open fd_1:
	fd_1 = open ("sources.txt", O_RDONLY);
	if (fd_1 == -1)
	{
		perror(strerror(ENOENT));
		return (1);
	}
	
	//open fd_2:
	fd_2 = open ("destination.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_2 == -1)
	{
		perror(strerror(errno));
		return (1);

	}


	//read
	readed_bytes = read(fd_1, buffer, sizeof(buffer) - 1);  // 0 es stdin
    if (readed_bytes == -1)
    {
        perror("Error al leer desde la entrada");
        close(fd_1);
		close(fd_2);
        return (1);
    }
    buffer[readed_bytes] = '\0'; 

	//	write
	int i=0;
	while(buffer[i] != '\0')
	{
		write(fd_2, &buffer[i], 1);
		i++;
	}
	//close
	if(close(fd_1) == -1)
		return (1);
	if(close(fd_2) == -1)
		return (1);


	return (0);
}