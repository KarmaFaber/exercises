/*2.Contador de caracteres: Implementa un programa que abra un archivo y cuente el número de caracteres en él. 
Usa read para leer el contenido del archivo en bloques y actualizar el contador.
en esta verción el contador de chars devolvera el numero de caracteres que tenemos en el buffer leido. 
si leemos 15 bytes del archivo, nos devolvera el numero de caracteres que tenemos en ese buffer provisional.*/

// gcc -Wall -Wextra -Werror 2_count_chars.c -o 2_count

//contar el numero de caracteres que tendremos en el buffer leido 

#include <unistd.h>         //open read, write, close
#include <errno.h>          //errno
#include <stdio.h>          //printf()
#include <fcntl.h>          //flags y mode de open()


static size_t ft_char_counter(char *buffer)
{
    size_t char_counter = 0;
    int character;
    int i=0;
    
    while (buffer[i])
    {   
        character=buffer[i];
        if (character >= 33 && character <= 126)
        
            char_counter++;
        i++;
    }


    return (char_counter);
}

int main (void)
{
    int fd;
    ssize_t readed;
    char buffer[1000];
    size_t count_read;
    size_t char_counter;

    count_read = 15;

    fd = open("0_ex_text.txt", O_RDONLY);
    //gestion errores de open
    if(fd == -1)
    {
        printf("error con fd: %d\n", errno);
        return (1);
    }

    readed = read(fd, buffer, count_read);
    //gesion de errores de read
    if (readed == -1)                       // Si ocurre un error al leer
    {
        perror("Error en la lectura del archivo");
        close(fd);
        return 1;
    }
    
    char_counter = ft_char_counter(buffer);

    printf("el numero de caracteres es de: %ld en la lectura de: %ld bytes.", char_counter, count_read);

    //gestion de errores de close
    if (close(fd) == -1)
    {
        perror("Error al cerrar el archivo");
        return (1);
    }
    return (0);
}



