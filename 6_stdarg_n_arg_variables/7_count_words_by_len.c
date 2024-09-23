/*Ejercicio 7: Contar palabras con longitud específica
Escribe una función que acepte una cantidad variable de
cadenas y un entero que represente la longitud de una palabra.
La función debe devolver cuántas de las cadenas tienen exactamente esa longitud.
Prototipo: int count_words_by_length(int length, int count, ...);*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int	count_words_by_length(int length, int count, ...)
{
	int			i;
	int			word_len;
	int			return_len_val;
	va_list		args;
	const char	*current_str;

	i = 0;
	word_len = 0;
	return_len_val = 0;
	va_start(args, count);
	while (i < count)
	{
		current_str = va_arg(args, char *);     // nos colocamos en la cadena actual en la lista de args
		word_len = strlen(current_str);         // calculamos la longuitud de arg actual
		if (word_len == length)
			return_len_val++;
		i++;
	}
	va_end(args);
	return (return_len_val);
}

int	main(void)
{
	int count_n_str = count_words_by_length(4, 2, "hola", "ll", "xxxx", "00000");// el primer argumento es el numero de argumentos que vamos a pasar, el segundo word_len que buscamos
	printf("return: %i\n", count_n_str);
	return (0);
}
