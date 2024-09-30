/*9.Intercambio de contenido entre archivos: Escribe un programa que lea dos archivos y los intercambie, 
de modo que el contenido del primer archivo se copie en el segundo y viceversa.
*/
// gcc -Wall -Wextra -Werror 9_swap_text.c -o 9_swap


#include <unistd.h>   // open, read, write, close
#include <errno.h>    // errno
#include <stdio.h>    // perror, printf
#include <fcntl.h>    // O_RDONLY, O_WRONLY
#include <stdlib.h>   // malloc, free
#include <string.h>   // memcpy

#define BUFFER_SIZE 1024  // Tamaño del búfer de lectura

// Función para leer el contenido de un archivo completo
ssize_t read_file_content(int fd, char **buffer) 
{
    ssize_t total_bytes_read = 0;
    ssize_t bytes_read;
    char temp_buffer[BUFFER_SIZE];

    // Inicializar un búfer dinámico
    *buffer = NULL;
    size_t buffer_size = 0;

    // Leer el archivo en bloques
    while ((bytes_read = read(fd, temp_buffer, BUFFER_SIZE)) > 0) 
    {
        // Reservar espacio en el buffer para los datos leídos
        *buffer = realloc(*buffer, buffer_size + bytes_read);
        if (*buffer == NULL) {
            perror("Error al reservar memoria");
            return -1;
        }

        // Copiar los datos leídos al buffer dinámico
        memcpy(*buffer + buffer_size, temp_buffer, bytes_read);
        buffer_size += bytes_read;
        total_bytes_read += bytes_read;
    }

    if (bytes_read == -1) {
        perror("Error al leer archivo");
        free(*buffer); // Liberar el buffer en caso de error
        return -1;
    }

    return total_bytes_read; // Retornar el número total de bytes leídos
}

// Función principal para intercambiar el contenido de dos archivos
int swap_file_contents(const char *file1, const char *file2) 
{
    // Abrir ambos archivos
    int fd1 = open(file1, O_RDONLY);
    int fd2 = open(file2, O_RDONLY);

    if (fd1 == -1 || fd2 == -1) 
    {
        perror("Error al abrir los archivos");
        if (fd1 != -1) close(fd1);
        if (fd2 != -1) close(fd2);
        return 1;
    }

    // Leer el contenido de ambos archivos
    char *buffer1 = NULL;
    char *buffer2 = NULL;
    ssize_t size1 = read_file_content(fd1, &buffer1);
    ssize_t size2 = read_file_content(fd2, &buffer2);

    close(fd1);
    close(fd2);

    if (size1 == -1 || size2 == -1) 
    {
        free(buffer1);
        free(buffer2);
        return 1;
    }

    // Abrir archivos en modo escritura para intercambiar los contenidos
    fd1 = open(file1, O_WRONLY | O_TRUNC);
    fd2 = open(file2, O_WRONLY | O_TRUNC);

    if (fd1 == -1 || fd2 == -1) 
    {
        perror("Error al abrir archivos en modo escritura");
        free(buffer1);
        free(buffer2);
        if (fd1 != -1) 
            close(fd1);
        if (fd2 != -1) 
            close(fd2);
        return 1;
    }

    // Escribir el contenido del segundo archivo en el primero
    if (write(fd1, buffer2, size2) != size2) 
    {
        perror("Error al escribir en el primer archivo");
        free(buffer1);
        free(buffer2);
        close(fd1);
        close(fd2);
        return 1;
    }

    // Escribir el contenido del primer archivo en el segundo
    if (write(fd2, buffer1, size1) != size1) 
    {
        perror("Error al escribir en el segundo archivo");
        free(buffer1);
        free(buffer2);
        close(fd1);
        close(fd2);
        return 1;
    }

    // Cerrar los archivos
    close(fd1);
    close(fd2);

    // Liberar la memoria asignada
    free(buffer1);
    free(buffer2);

    return 0;
}

int main(void) 
{
    const char *archivo1 = "9_archivo1.txt";
    const char *archivo2 = "9_archivo2.txt";

    // Intercambiar el contenido de los archivos
    if (swap_file_contents(archivo1, archivo2) == 0) 
        printf("Intercambio de contenido completado.\n");
    else 
        printf("Error en el intercambio de contenido.\n");

    return 0;
}