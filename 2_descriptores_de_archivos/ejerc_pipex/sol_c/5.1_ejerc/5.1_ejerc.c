/*
5.1 **Redirección de salida estándar: dup(),  dup2()**
    Escribe un programa que redirija temporalmente la salida estándar a un archivo llamado temp_output.txt, 
    escriba dos líneas de texto en el archivo, y luego restaure la salida estándar para escribir "Redirection complete" en la terminal.
    Asegúrate de que el programa no elimine el contenido existente en el archivo, y agrega la línea "This is appended text.".
    Pista: Usa dup, dup2 y STDOUT_FILENO.
    Nota: modifico el mensaje por un bucle while de numeros, que se añaden al archivo cada vez que ejecutamos el programa. 

cc -Wall -Werror -Wextra 5.1_ejerc.c -o 5.1_ejerc
*/

#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2
#include <fcntl.h> // open
#include <stdlib.h> //exit


int main (void)
{
    int fd;
    int saved_stdout;

    //open
    fd = open("output1.txt",  O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd == -1)
    {
        perror ("error al abrir o crear file");
        return (1);
    }

    //save STDOUT_FILENO
    saved_stdout = dup(STDOUT_FILENO);
    if (saved_stdout == -1)
    {
        perror ("error al duplicar stdout");
        close(fd);
        return (1);
    }

    //redirigir stdout al archivo
    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("error al duplicar stdout");
        close(fd);
        close(saved_stdout);
        return (1);    
    }
    close(fd);

    //Escribir al archivo (redirigido stdout)
    int i=0;
    while(i<5)
    {
        printf("%i\n", i);
        i++;
    }

    //
    fflush(stdout); // Asegurarse de que el búfer de stdout se vacíe


    // Restaurar stdout original
    if (dup2(saved_stdout, STDOUT_FILENO) == -1)
    {
        perror("Error al restaurar stdout");
        close(saved_stdout);
        return (1);
    }
    close(saved_stdout); // Cerrar el descriptor duplicado

    printf("ester mensaje va a la consola\n");

    return (0);
}