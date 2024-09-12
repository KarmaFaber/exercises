/*Ejercicio 1: Suma de números enteros
Escribe una función que acepte un número indefinido de enteros y devuelva su suma. Usa stdarg.h para manejar los argumentos variables.
Prototipo: int sum_integers(int count, ...);*/

#include <stdarg.h>
#include <stdio.h>

int sum_integers(int count, ...)
{
    int i;
    int total; 
    va_list args;

    i = 0;
    total = 0;

    va_start(args, count); // Inicializa la lista con el número de argumentos fijos (count)
    while(i < count)
    {
        total += va_arg(args, int);
        i++;
    }
    va_end(args);
    return(total);
}


int main(void)
{
    printf("suma: %d\n", sum_integers(3, 2, 3, 1)); // el primer argumento en sum_integers es el numero de argumentos que vamos a pasar. 
    return (0);
}
