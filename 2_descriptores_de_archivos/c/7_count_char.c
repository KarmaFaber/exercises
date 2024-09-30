/*7.Lectura de un archivo hasta EOF: 
Crea un programa que lea un archivo hasta el final (EOF) y 
cuente cuántas veces aparece un carácter específico en el archivo.
 */

// gcc -Wall -Wextra -Werror 7_count_char.c -o 7_count_char

#include <unistd.h>         // open, read, write, close
#include <errno.h>          // errno
#include <stdio.h>          // perror, printf
#include <fcntl.h>          // O_RDONLY

static size_t ft_count_founded_char (char *buffer, ssize_t readed_bytes, int c)
{
    size_t char_counter;
    int i;

    i = 0;
    char_counter = 0;
    while (i < readed_bytes)
    {
        if (buffer[i] == c)
        {
            char_counter++;
        }
        i++;
    }
    return (char_counter);
}

int main (void)
{
    int fd;
    ssize_t readed_bytes;
    int find = 'a';
    char buffer [1000];
    int finded;

    finded = 0;
    fd = open("0_ex_text.txt", O_RDONLY);
    // Manejo de errores al abrir
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Leer el archivo en bloques y contar caracteres
    while ((readed_bytes=read(fd, buffer, sizeof(buffer))) > 0)
        finded += ft_count_founded_char(buffer, readed_bytes, find);

    // Manejo de errores en la lectura
    if (readed_bytes == -1)
    {
        perror("Error en la lectura del archivo");
        close(fd);
        return 1;
    }

    printf("El número total de caracteres encontrados es: %d\n", finded);

    // Manejo de errores al cerrar
    if (close(fd) == -1)
    {
        perror("Error al cerrar el archivo");
        return 1;
    }

    return (0);
}
