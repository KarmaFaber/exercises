



// gcc -Wall -Wextra -Werror 5_line_read_cpt.c -o 5_line_read_cgt
//valgrind --leak-check=full ./5_line_read_cgt
//valgrind --leak-check=full --show-leak-kinds=all ./5_line_read_cgt


#include <unistd.h>         // open, read, write, close
#include <errno.h>          // errno
#include <stdio.h>          // perror, printf
#include <fcntl.h>          // O_RDONLY
#include <stdlib.h>         // malloc, free

#define BUFFER_SIZE 10

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strdup(const char *s)
{
    size_t len;
    size_t i;

    len = ft_strlen(s);
    char *dup = (char *)malloc(len + 1);
    if (!dup)
        return NULL;

    i = 0;
    while (i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[len] = '\0';
    return (dup);
}

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    size_t i;
    size_t s_len;
    char *substr ;

    s_len = ft_strlen(s);
    if (start >= s_len)
        return ft_strdup("");
    if (len > s_len - start)
        len = s_len - start;
    substr = (char *)malloc(len + 1);
    if (!substr)
        return NULL;
    i = 0;
    while (i < len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[len] = '\0';
    return substr;
}

char *ft_strjoin(char *s1, const char *s2)
{
    size_t i;
    size_t j;
    char *new_char;

    i=0;
    j=0;
    if (!s1)
        return ft_strdup(s2);
    if (!s2)
        return ft_strdup(s1);
    new_char = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!new_char)
        return NULL;
    while (i < ft_strlen(s1))
        new_char[j++] = s1[i++];  
    i = 0;
    while (i < ft_strlen(s2))
        new_char[j++] = s2[i++];
    new_char[ft_strlen(s1) + ft_strlen(s2)] = '\0';
    free(s1);
    return (new_char);
}



static char *get_next_line(int fd)
{
    static char *remainder = NULL; // Resto de línea de una lectura previa
    char *readed_buffer;
    char *line = NULL;
    char *temp;
    ssize_t readed_bytes;
    ssize_t i;

    if (remainder) // Si hay un fragmento de línea pendiente
    {
        line = ft_strdup(remainder);
        free(remainder);
        remainder = NULL;
    }

    // Reservamos el buffer de lectura
    readed_buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!readed_buffer)
        return NULL;

    readed_buffer[BUFFER_SIZE] = '\0';

    while ((readed_bytes = read(fd, readed_buffer, BUFFER_SIZE)) > 0)
    {
        i = 0;
        while (i < readed_bytes)
        {
            if (readed_buffer[i] == '\n') // Encontramos un salto de línea
            {
                temp = ft_substr(readed_buffer, 0, i); // Extraemos la línea
                line = ft_strjoin(line, temp); // Concatenamos si es necesario
                free(temp);

                // Guardamos lo que queda después del salto de línea
                remainder = ft_substr(readed_buffer, i + 1, readed_bytes - (i + 1));
                free(readed_buffer);
                return line; // Retornamos la línea completa
            }
            i++;
        }

        // Si no hay salto de línea, acumulamos todo lo leído
        temp = ft_substr(readed_buffer, 0, readed_bytes);
        line = ft_strjoin(line, temp);
        free(temp);
    }

    free(readed_buffer);

    // Si hemos llegado al final del archivo y hay datos acumulados, los devolvemos
    if (line && ft_strlen(line) > 0)
        return line;

    free(line); // Liberamos si no hay nada que retornar
    return NULL; // EOF o error
}

int main(void)
{
    int fd;
    int count = 0;
    char *line;

    fd = open("0_ex_text.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        count++;
        printf("[%d]: %s\n", count, line);
        free(line);
    }

    if (close(fd) == -1)
    {
        perror("Error al cerrar el archivo");
        return 1;
    }

    return 0;
}


