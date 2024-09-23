/*Ejercicio 9: Sumar sólo los números pares
Escribe una función que acepte una cantidad variable de números enteros 
y devuelva la suma de solo los números pares.
Prototipo: int sum_even_numbers(int count, ...);*/

#include <stdarg.h>
#include <stdio.h>

int sum_even_numbers(int count, ...)
{
    int i;
    int even_sum;
    int current_arg;
    va_list args;

    i=0;
    even_sum=0;
    va_start(args, count);
    while (i<count)
    {
        current_arg=va_arg(args, int);
        if (current_arg % 2 ==0)        //si son pares
            even_sum += current_arg;
        i++;
    }
    va_end(args);
    return(even_sum);
}

int	main(void)
{
    int	even_sum;
    even_sum=sum_even_numbers(10, 2, -2, 3, 1, 0, 6, 22, 13, -20, 100);
	printf("suma de pares: %i\n", even_sum); // el primer argumento en sum_integers es el numero de argumentos que vamos a pasar.
	return (0);
}