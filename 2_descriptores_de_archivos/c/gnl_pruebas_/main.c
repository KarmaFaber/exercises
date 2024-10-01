
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

// gcc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o gnl_pruebas
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl_pruebas
// valgrind --leak-check=full ./gnl_pruebas

char	*get_next_line(int fd);
int main (void)
{
    int fd;
    int count;
    char *line;

    

    count = 0;
    fd = open("0_ex_text.txt", O_RDONLY);
    // Manejo de errores al abrir
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }
    /*while (1) -> es un bucle infinito que se utoliza para leer archivo de manera continua en bloques 
    hasta que se detecte el final del archivo (readed_bytes ==0) o ocurra un error (readed_bytes < 0), 
    en cuyo caso el bucle se ropme con un break; Es una forma de leer archivos sin saber de antemano cuantos bloques 
    habra en dicho archivo. */
    while (1)   //
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        count++;
        printf("[%d]: %s\n", count, line);
        free(line);
        line=NULL;
    }

    // Manejo de errores al cerrar
    if (close(fd) == -1)
    {
        perror("Error al cerrar el archivo");
        return 1;
    }
    return (0);
}