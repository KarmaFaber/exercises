/*9.Intercambio de contenido entre archivos: Escribe un programa que lea dos archivos y los intercambie, 
de modo que el contenido del primer archivo se copie en el segundo y viceversa.
*/



// gcc -Wall -Wextra -Werror 3_read_y_write.c -o 3_read_y_write

#include <unistd.h>         // open, read, write, close
#include <errno.h>          // errno
#include <stdio.h>          // perror, printf
#include <fcntl.h>          // O_RDONLY

int main(void)
{
    int fd_read;
    int fd_write;
    ssize_t count_read;
    ssize_t bytes_readed;
    ssize_t bytes_writed;
    char buffer[1000];
    char aux_buffer[1000];

    

    fd_read = open("0_ex_text.txt", O_RDONLY);
    // Manejo de errores al abrir archivo de lectura
    if (fd_read == -1)
    {
        perror("Error al abrir el archivo para lectura");
        return 1;
    }

    fd_write = open ("3_new.txt", O_WRONLY);
    // Manejo de errores al abrir archivo de escritura
    if (fd_write == -1)
    {
        perror("Error al abrir el archivo para escritura");
        return 1;
    }

    bytes_readed=read(fd_read, buffer, sizeof(buffer));
    // Manejo de errores en la lectura
    if (bytes_readed == -1)
    {
        perror("Error en la lectura del archivo");
        close(fd_read);
        return 1;
    }

    

    bytes_writed = write (fd_write, buffer, 50);
    // Manejo de errores en la escritura:
    if (bytes_writed == -1)
    {
        perror("Error en la escritura del archivo");
        close(fd_write);
        return 1;
    }

    // Manejo de errores al cerrar
    if (close(fd_read) == -1)
    {
        perror("Error al cerrar el archivo de lectura");
        return 1;
    }
    if (close(fd_write) == -1)
    {
        perror("Error al cerrar el archivo de escritura");
        return 1;
    }

    return (0);
}
