/*Ejercicio 5: Producto de números de punto flotante
Escribe una función que acepte un número indefinido de números de punto flotante (double) y devuelva su producto.
Prototipo: double multiply_floats(int count, ...);*/

#include <stdarg.h>
#include <stdio.h>

double	multiply_floats(int count, ...)
{
	int		i;
	double	multi;
	double	current_arg;
	va_list	args;

	i = 0;
	multi = 1.0;
	va_start(args, count);
	while (i < count)
	{
		current_arg = va_arg(args, double);
		multi *= current_arg;
		i++;
	}
	va_end(args);
	return (multi);
}

int	main(void)
{
	double multi;

	multi = multiply_floats(3, 2.1, 1.3, 3.6);
	printf("multi_return: %f\n", multi);
	return (0);
}