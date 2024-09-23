/*Ejercicio 6: Calcular la media de números
Escribe una función que acepte una cantidad variable de números y devuelva su media.
Prototipo: double calculate_average(int count, ...);*/

#include <stdarg.h>
#include <stdio.h>

double	calculate_average(int count, ...)
{
	double	med;
	int		i;
	double	sum;

	va_list(args);
	i = 0;
	va_start(args, count);
	while (i < count)
	{
		sum += va_arg(args, double);
		i++;
	}
	va_end(args);
	med = sum / count;
	return (med);
}

int	main(void)
{
	double med;

	med = calculate_average(3, 2.1, 1.3, 3.6);
	printf("med_return: %f\n", med);
	return (0);
}