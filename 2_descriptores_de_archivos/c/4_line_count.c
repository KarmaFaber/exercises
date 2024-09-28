/*4.Lectura de líneas: Crea un programa que lea un archivo línea por línea usando read. 
Define un tamaño fijo para las líneas y utiliza un búfer.
*/

// gcc -Wall -Wextra -Werror 4_line_count.c -o 4_line_count

#include <unistd.h>         // open, read, write, close
#include <errno.h>          // errno
#include <stdio.h>          // perror, printf
#include <fcntl.h>          // O_RDONLY
#include <string.h>         // memcpy



//en este caso solo contamos el numero de lineas limitado por count_to_read y el buffer de read
static size_t ft_line_counter (char *buffer, ssize_t bytes_read)
{
    size_t line_num = 0;
    int i=0;

    while (i < bytes_read)
    {
        if (buffer[i] == '\n')
            line_num++;
        i++;
    }
    printf("return ft_line_counter: %ld\n", line_num);
    return (line_num);
}
//en este caso contamos el numero de lineas de todo el archivo, siempre y cuando el buffer sea sufinete para almacenar todo el archivo
/*static size_t ft_line_counter (char *buffer)
{
    size_t line_num = 0;
    int i=0;

    while (buffer[i])
    {
        if (buffer[i]=='\n')
            line_num++;
        i++;
    }

    return (line_num);
}*/

int main (void)
{
    int fd;
    ssize_t bytes_readed;
    size_t count_to_read = 15;
    size_t line_count=0;
    

    fd = open("0_ex_text.txt", O_RDONLY);
    // Manejo de errores al abrir
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }
    
    while ((bytes_readed=read(fd, buffer, count_to_read)) > 0)
        line_count += ft_line_counter(buffer, bytes_readed); //contar el numero de lineas


    // Manejo de errores en la lectura
    if (bytes_readed == -1)
    {
        perror("Error en la lectura del archivo");
        close(fd);
        return 1;
    }

    printf("El número total de lineas es: %zu\n", line_count);

    // Manejo de errores al cerrar
    if (close(fd) == -1)
    {
        perror("Error al cerrar el archivo");
        return 1;
    }
    

    return (0);
}
