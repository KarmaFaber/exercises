/*
5.2 **Redirección de salida estándar: dup(),  dup2()**
    Escribe un programa en C con una función llamada write_message_to_file. 
    Esta función debe recibir el nombre de un archivo como argumento, redirigir la salida estándar al archivo, 
    y luego escribir el mensaje "Message written by function." dentro del archivo. Después de la ejecución de la función, 
    el programa debe restaurar la salida estándar y escribir "Operation completed" en la terminal.
    Pista: Usa funciones auxiliares como dup y dup2 para gestionar los descriptores de archivo.


	cc -Wall -Werror -Wextra 5.2_ejerc.c -o 5.2_ejerc
*/


#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2
#include <fcntl.h> // open
#include <stdlib.h> //exit

void redirect_stdout_to_file(char *file_name, void (*func_to_execute)(void)) 
{
    int fd = open(file_name,  O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd == -1) 
	{
        perror("Error opening file");
        return;
    }

    int saved_stdout = dup(STDOUT_FILENO);
    if (saved_stdout == -1) 
	{
        perror("Error duplicating stdout");
        close(fd);
        return;
    }

    if (dup2(fd, STDOUT_FILENO) == -1) 
	{
        perror("Error redirecting stdout");
        close(fd);
        close(saved_stdout);
        return;
    }
    close(fd);

    if (func_to_execute) 
	{
        func_to_execute();
    }

    fflush(stdout); // Asegurarse de que el búfer de stdout se vacíe

    if (dup2(saved_stdout, STDOUT_FILENO) == -1) 
	{
        perror("Error restoring stdout");
        return;
    }
    close(saved_stdout);
}

// Call example
void sample_function() 
{
    printf("This will go into the file!\n");
}

int main() 
{
    redirect_stdout_to_file("output.txt", sample_function);
    return 0;
}