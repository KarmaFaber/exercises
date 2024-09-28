/*2.Contador de caracteres: Implementa un programa que abra un archivo y cuente el número de caracteres en él. 
Usa read para leer el contenido del archivo en bloques y actualizar el contador.
en esta verción el contador de chars devolvera el numero de caracteres totales de todo el archivo. 
deberemos asegurarnos que el tamaño del buffer soporta el archivo entero, para no perder datos a contar.
*/

// gcc -Wall -Wextra -Werror 2_count_chars_v01.c -o 2_count_v1


//contar el numero de caracteres en todo el archivo


#include <unistd.h>         // open, read, write, close
#include <errno.h>          // errno
#include <stdio.h>          // perror, printf
#include <fcntl.h>          // O_RDONLY

// Contar caracteres imprimibles en el buffer utilizando un bucle while
static size_t ft_char_counter(char *buffer, ssize_t bytes_read)
{
    size_t char_counter = 0;
    ssize_t i = 0;

    while (i < bytes_read) // Continuar hasta que hayamos contado todos los bytes leídos
    {
        int character = buffer[i];
        if (character >= 33 && character <= 126) // Contar solo caracteres imprimibles
        {
            char_counter++;
        }
        i++; // Incrementar el índice
    }

    return char_counter;
}

int main(void)
{
    int fd;
    ssize_t readed;
    char buffer[1000];
    size_t total_characters = 0;

    fd = open("0_ex_text.txt", O_RDONLY);
    // Manejo de errores al abrir
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Leer el archivo en bloques y contar caracteres
    while ((readed = read(fd, buffer, sizeof(buffer))) > 0)
        total_characters += ft_char_counter(buffer, readed); // Contar caracteres de lo que se ha leído


    // Manejo de errores en la lectura
    if (readed == -1)
    {
        perror("Error en la lectura del archivo");
        close(fd);
        return 1;
    }

    printf("El número total de caracteres es: %zu\n", total_characters);

    // Manejo de errores al cerrar
    if (close(fd) == -1)
    {
        perror("Error al cerrar el archivo");
        return 1;
    }
    
    return 0;
}
