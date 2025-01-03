/*
5.0 **Redirección de salida estándar: dup(), dup2()**
    Escribe un programa en C que cree un archivo llamado output1.txt y redirija la salida estándar a este archivo. 
    Luego, utiliza printf para escribir la frase "Hello, world!" en el archivo.
    Después de escribir, asegúrate de restaurar la salida estándar al terminal.

    Pista: Usa dup, dup2 y STDOUT_FILENO.

cc -Wall -Werror -Wextra 5.0_ejerc.c -o 5.0_ejerc
*/

#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2, dup
#include <fcntl.h> // open
#include <stdlib.h> //exit


int main (void)
{
    int fd;
    int saved_stdout;

    //open
    fd = open("output1.txt",  O_RDWR | O_CREAT | O_TRUNC, 0644);
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
    printf("hola Mundo de unicornios: esto va al archivo\n");

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

/*
se imprimen los dos mensajen en consola en vez de 1 en archivo y 1 en consola:
error y solucion: buffer de stdout no se libera -> solucion: liberar el buffer de stdoput con fflush(stdout);

El comportamiento que describes ocurre porque el búfer de salida estándar 
(stdout) no se vacía inmediatamente cuando usas la redirección en un programa en C. 
Los mensajes que se imprimen en consola son enviados al búfer de stdout, y cuando rediriges 
stdout a un archivo, el contenido de ese búfer podría no haberse escrito aún en el archivo antes de que se restaure la redirección.

La razón detrás de que los mensajes sigan apareciendo en la consola incluso después de redirigir stdout es 
que el mensaje ya estaba en el búfer de stdout antes de que se hiciera la redirección. La redirección de stdout 
afecta solo a los mensajes posteriores que se impriman después de realizar la redirección.

Para solucionar este problema, puedes forzar el vaciado del búfer de stdout antes de 
restaurarlo usando la función fflush(stdout), que vacía el búfer de salida estándar.*/

