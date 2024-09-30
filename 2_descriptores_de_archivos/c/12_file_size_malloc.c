/*12. calcular el tamaño exacto del archivo en bytes y asignar memoria dinamica malloc exata para el buffer de read.*/

// gcc -Wall -Wextra -Werror 12_file_size_malloc.c -o 12_count_file_bytes_malloc

#include <unistd.h>  // open, read, close
#include <fcntl.h>   // O_RDONLY
#include <stdio.h>   // perror, printf
#include <stdlib.h>  // malloc, free
#include <string.h>  //strlen. 

int main(void)
{
    int fd;
    int i;
    ssize_t bytes_read;
    size_t total_size = 0;
    size_t total_read = 0;
    char *file_content;
    char buffer[1024];  // Buffer temporal para leer el archivo

    // Abrir el archivo
    fd = open("0_ex_text.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Leer el archivo en bloques y contar el total de bytes
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
        total_size += bytes_read;

    // Manejo de errores en la lectura
    if (bytes_read == -1)
    {
        perror("Error en la lectura del archivo");
        close(fd);
        return 1;
    }

    // Asignar memoria exacta con malloc
    file_content = (char *)malloc(total_size + 1);  // +1 para el terminador '\0'
    if (file_content == NULL)
    {
        perror("Error al asignar memoria");
        close(fd);
        return 1;
    }

    // Volver a leer el archivo para almacenarlo en la memoria
    lseek(fd, 0, SEEK_SET);  // Volver al inicio del archivo
    i = 0;
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
    {
        // Copiar los datos del buffer temporal al buffer final
        while (i < bytes_read)
        {
            file_content[total_read + i] = buffer[i];
            i++;
        }
        total_read += bytes_read;
    }

    // Cerrar el archivo
    close(fd);

    // Agregar el terminador de cadena al final
    file_content[total_size] = '\0';

    printf("El archivo tiene un tamaño de %zu bytes\n", total_size);

    // Usar el contenido del archivo (por ejemplo, imprimirlo)
    
    printf("Contenido del archivo:\n%s\n", file_content);


    // Liberar la memoria
    free(file_content);
    return 0;
}
