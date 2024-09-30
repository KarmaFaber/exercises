/*8.Lectura y búsqueda de palabras: Implementa un programa que abra un archivo y busque una palabra específica, 
leyendo el archivo en bloques. Indica cuántas veces aparece la palabra.*/

// gcc -Wall -Wextra -Werror 8_count_words.c -o 8_count_words

#include <unistd.h>         // open, read, write, close
#include <errno.h>          // errno
#include <stdio.h>          // perror, printf
#include <fcntl.h>          // O_RDONLY
#include <string.h>         // strlen


static size_t ft_word_count(char *buffer, ssize_t readed_bytes, const char *find_word)
{
    size_t i;
    size_t word_count;
    size_t word_length;

    i = 0;
    word_count = 0;
    word_length = strlen(find_word);
    
    // Recorremos el buffer buscando la palabra
    while (i <= readed_bytes - word_length) 
    {
        // Comparamos la subcadena en el buffer con la palabra buscada
        if (strncmp(&buffer[i], find_word, word_length) == 0) 
        {
            word_count++;
            i += word_length - 1; // Avanzar el índice para evitar contar de nuevo la misma palabra
        }
        i++;
    }
    return (word_count);
}

int main (void)
{
    int fd;
    ssize_t readed;
    char buffer[1000];
    size_t total_words;
    const char *search_word;

    total_words = 0;
    search_word = "unicornio";
    fd = open("0_ex_text.txt", O_RDONLY);
    // Manejo de errores al abrir
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Leer el archivo en bloques y contar caracteres
    while ((readed = read(fd, buffer, sizeof(buffer))) > 0)
        total_words += ft_word_count (buffer, readed, search_word); // Contar caracteres de lo que se ha leído


    // Manejo de errores en la lectura
    if (readed == -1)
    {
        perror("Error en la lectura del archivo");
        close(fd);
        return 1;
    }

    printf("El número total de palabras es: %d\n", (int)total_words); //deberia return 5 unicornio

    // Manejo de errores al cerrar
    if (close(fd) == -1)
    {
        perror("Error al cerrar el archivo");
        return 1;
    }



    return (0);
}