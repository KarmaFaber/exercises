/*1.Lectura de un archivo de texto: Crea un programa que abra un archivo de texto, 
lea su contenido y lo muestre en la consola. 
Asegúrate de manejar correctamente los errores de apertura y lectura.*/

// gcc -Wall -Wextra -Werror 1_read_file.c -o 1_read 


#include <unistd.h>         //open read, write, close
#include <errno.h>          //errno
#include <stdio.h>          //printf()
#include <fcntl.h>          //flags y mode de open()


int main (void)
{
    int fd;
    size_t count = 10;
    ssize_t bytes_read;
    char buffer[100];           //ojo con el tamaño del buffer de lectura si no tienen suficiente capacidad solo imprimira lo que se ha almacenado en el buffer sugun el tamaño dado
    
    fd = open("0_ex_text.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("error con fd: %d\n", errno);
        return (1);
    }

    // Leer hasta 'count' bytes (10 en este caso)
    //bytes_read = read(fd, buffer, sizeof(buffer));
    bytes_read = read(fd, buffer, count);       //para leer todo el archivo: bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1)                       // Si ocurre un error al leer
    {
        perror("Error en la lectura del archivo");
        close(fd);
        return 1;
    }

    // Escribir los bytes leídos en la salida estándar (consola)
    if (write(STDOUT_FILENO, buffer, bytes_read) == -1) 
    {
        perror("Error al escribir en la salida estándar");
        close(fd);
        return 1;
    }
    write(1, "\n", 1);
    
    // Cerrar el archivo
    if (close(fd) == -1)
    {
        perror("Error al cerrar el archivo");
        return (1);
    }
    return (0);
}
