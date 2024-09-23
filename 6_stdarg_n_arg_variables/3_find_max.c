/*Ejercicio 3: Encontrar el máximo de una lista de números
Escribe una función que acepte una cantidad variable de números enteros
y devuelva el valor máximo entre ellos.
Prototipo: int find_max(int count, ...);*/

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

int	find_max(int count, ...)
{
	int		i;
	int		max;
	int		current_arg;
	va_list	args;

	i = 0;
	max = INT_MIN;
	va_start(args, count);
	while (i < count)
	{
		current_arg = va_arg(args, int);
		if (current_arg > max)
			max = current_arg;
		i++;
	}
	va_end(args);
	return (max);
}

int	main(void)
{
	int	max;

	max = find_max(5, 0, 7, -2, 10, 2);
	printf("max_return: %i\n", max);
	return (0);
}
