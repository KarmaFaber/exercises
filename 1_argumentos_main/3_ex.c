/*Ejercicio 3: Comprobación de tipo de argumento
Descripción:
Escribe un programa que reciba argumentos y determine si son numéricos o no. 
Imprime cada argumento seguido de "es numérico" o "no es numérico".

Objetivo:
Aprender a trabajar con conversiones de tipos y a verificar la validez de los argumentos.*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int is_numeric(const char *str)
{
    
    if (*str == '\0')
    {
        return 0;
    }
    if (*str == '-' || *str == '+')
    {
        str++;
    }
    while (*str)
    {
        if (!isdigit((unsigned char)*str))
        {
            return 0;
        }
        str++;
    }

    return 1;
}


int main(int argc, char *argv[])
{
    printf("numero de argumentos: %d\n", argc);
    printf("el nombre del programa: %s\n", argv[0]);

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            if (is_numeric(argv[i]))
            {
                printf("'%s' es numérico\n", argv[i]);
            }
            else
            {
                printf("'%s' no es numérico\n", argv[i]);
            }
        }
    }
    else
    {
        printf("No se proporcionaron argumentos adicionales.\n");
    }

    return 0;
}


