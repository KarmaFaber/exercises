/*Ejercicio 2: Concatenación de cadenas
Escribe una función que acepte un número indefinido de cadenas 
y devuelva una nueva cadena que sea la concatenación de todas ellas. 
Usa memoria dinámica para almacenar el resultado.
Prototipo: char *concat_strings(int count, ...);*/

#include <stdarg.h>
#include <stdio.h>

char *concat_strings(int count, ...)
{
    va_list args;
    char *dest;

    va_start(args, count);


    va_end(args);
    return(dest);
}

int main (void)
{


    return (0);
}