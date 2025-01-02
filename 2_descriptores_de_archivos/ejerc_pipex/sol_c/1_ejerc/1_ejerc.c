/*
1. **Abrir y cerrar archivos:**
    - Escribe un programa que abra un archivo `file.txt`, lea su contenido y lo imprima en la salida estándar.

cc -Wall -Werror -Wextra 1_ejerc.c -o 1_ejerc
*/
#include <stdio.h> //perror
#include <unistd.h> // read
#include <fcntl.h> // open
#include <string.h> //strlen

int main(void)
{
    int fd;
    char buffer[1000];
    ssize_t readed_bytes;

    //open fd
    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
    {
        perror ("error al abrir el archivo ");
        return (1);
    }

    //read fd
    readed_bytes= read(fd, buffer, sizeof(buffer)-1);
    if (readed_bytes == -1)
    {
        perror("error al leer el archivo");
        close (fd);
        return (1);
    }
    buffer[readed_bytes] ='\0';

    //write fd
    write(1, buffer, strlen(buffer));
    write(1, "\n", 1);


    //close fd
    if (close(fd) == -1)
    {
        perror ("error al cerrar el fd");
        return 1;
    }



    return (0);
}