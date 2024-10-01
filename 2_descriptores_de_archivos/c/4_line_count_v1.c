/*4.Lectura de líneas: Crea un programa que lea un archivo línea por línea usando read. 
Define un tamaño fijo para las líneas y utiliza un búfer.
*/

// gcc -Wall -Wextra -Werror 4_line_count_v1.c -o 4_line_count_v1

#include <unistd.h>         // open, read, write, close
#include <errno.h>          // errno
#include <stdio.h>          // perror, printf
#include <fcntl.h>          // O_RDONLY
#include <string.h>         // memcpy

#define BUFFER_SIZE 100
//#define LINE_BUFFER_SIZE 100 

//en este caso solo contamos el numero de lineas limitado por count_to_read y el buffer de read
static size_t ft_line_counter (char *buffer, ssize_t bytes_read)
{
    size_t line_num = 0;
    int i=0;

    while (i < bytes_read)
    {
        if (buffer[i] == '\n')
            line_num++;
        i++;
    }
    printf("return ft_line_counter: %ld\n", line_num);    //comprobacion de line_num retornadas
    return (line_num);
}

int main (void)
{
    int fd;
    ssize_t i = 0;
    ssize_t bytes_readed;
    size_t line_count = 0;
    char buffer [BUFFER_SIZE];                      
    

    fd = open("0_ex_text.txt", O_RDONLY);
    // Manejo de errores al abrir
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }
    
    //leer el archivo en bloques y contar las lineas
    while ((bytes_readed=read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        //contar las lineas del buffer leido:
        line_count += ft_line_counter(buffer, bytes_readed);

        //comprobar si el ultimo caracter de la linea es un salto delinea
        if (buffer[bytes_readed -1] != '\n')
        {
            //mover los caracteres restantes no terminados en linea a la siguiente iteracion 
            while (i< bytes_readed && buffer[bytes_readed -i -1] != '\n')
                i++;
        }
        else
            i = 0;        //no hay lineas incompletas
      
    }

    // Manejo de errores en la lectura
    if (bytes_readed == -1)
    {
        perror("Error en la lectura del archivo");
        close(fd);
        return 1;
    }

    printf("El número total de lineas es: %ld\n", line_count);

    // Manejo de errores al cerrar
    if (close(fd) == -1)
    {
        perror("Error al cerrar el archivo");
        return 1;
    }
    

    return (0);
}


//version muuuy larga
/*
int main (void)
{
    int fd;
    ssize_t bytes_readed;
    size_t line_count = 0;
    size_t copy_len = 0;
    size_t remaining_len = 0;
    size_t line_buffer_len = 0;              //Longuitud actual del buffer de líneas
    char buffer [BUFFER_SIZE];                      
    char line_buffer[LINE_BUFFER_SIZE];     //buffer para lineas incompletas

    

    fd = open("0_ex_text.txt", O_RDONLY);
    // Manejo de errores al abrir
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }
    
    //leer el archivo en bloques y contar las lineas
    while ((bytes_readed=read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        //procesar las lineas que ya estan en el buffer incompleto(line_buffer)
        if(line_buffer_len > 0)
        {
            copy_len = LINE_BUFFER_SIZE - line_buffer_len;      //espacio disponible en line_buffer
            if(bytes_readed < copy_len)
                copy_len = bytes_readed;                        //no copiamos mas de lo que se ha leido
            memcpy(line_buffer + line_buffer_len, buffer, copy_len); 
            line_buffer_len += copy_len;

            //contar lineas en el buffer acumulado
            line_count += ft_line_counter(line_buffer, line_buffer_len);

            //ajustar el buffer para el proximo bloque si aun queda contenido:
            if (line_buffer[line_buffer_len -1] != '\n' && line_buffer_len == LINE_BUFFER_SIZE)
            {
                //si hay contenido incompleto, moverlo al principio del buffer:
                while (line_buffer_len > 0 && line_buffer[line_buffer_len - 1] != '\n')
                {
                    remaining_len ++;
                    line_buffer_len--;
                }
                //mover el contenido uncompleto al principio del buffer
                memcpy(line_buffer, buffer + (bytes_readed - remaining_len), remaining_len);
                line_buffer_len = remaining_len;
            }
            else
            {
                line_buffer_len = 0;
            }

        }


        //contar las lineas del buffer actual 
        line_count += ft_line_counter(buffer, bytes_readed); //contar el numero de lineas

        //manejar el caso en el que el bloque actual no termina con una nueva linea
        if (buffer[bytes_readed -1 ] != '\n')
        {
            //si no termino con un salto de linea, almacenar los bytes restantes en line_buffer
            remaining_len =bytes_readed;
            if (remaining_len > LINE_BUFFER_SIZE)
                remaining_len = LINE_BUFFER_SIZE;   //limitar al tamaño del buffer
            memcpy(line_buffer, buffer +  (bytes_readed -remaining_len), remaining_len);
            line_buffer_len=remaining_len;

        }
    }

    // Manejo de errores en la lectura
    if (bytes_readed == -1)
    {
        perror("Error en la lectura del archivo");
        close(fd);
        return 1;
    }

    printf("El número total de lineas es: %ld\n", line_count);

    // Manejo de errores al cerrar
    if (close(fd) == -1)
    {
        perror("Error al cerrar el archivo");
        return 1;
    }
    

    return (0);
}
*/

