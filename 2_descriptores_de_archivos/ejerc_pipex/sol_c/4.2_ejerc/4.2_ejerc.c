/*
4.1 **uso funcion execve()**    
    -escrive un programa usando fucnion execve().
	Ejecutar un programa externo con argumentos usando execve
	--formato main: int main(void)


	Enunciado: Uso de execve para ejecutar un comando externo con argumentos
Título: Ejecutar el comando date con opciones usando execve

Escribe un programa en C que utilice la función execve para ejecutar el comando date con las opciones +%Y-%m-%d y +%T, 
que muestran la fecha y hora en un formato específico.

El programa debe:

Mostrar un mensaje indicando que está a punto de ejecutar el comando.
Reemplazar el proceso actual por el comando date.
Si la ejecución de execve falla, debe imprimir un mensaje de error utilizando perror.
Detalles:

Ruta del ejecutable: /bin/date.
Argumentos a pasar:
argv[0]: Nombre del programa (por convención, date).
argv[1]: Opción +%Y-%m-%d para mostrar la fecha en formato YYYY-MM-DD.
argv[2]: Opción +%T para mostrar la hora en formato HH:MM:SS.
argv[3]: NULL (para indicar el final de los argumentos).
No es necesario modificar el entorno, utiliza el entorno actual del programa.
Salida esperada:

1. Antes de ejecutar date, el programa debe imprimir:
	Executing date with custom format...
2. Si execve tiene éxito, el proceso actual se reemplazará por date +%Y-%m-%d +%T, mostrando la fecha y hora en el formato YYYY-MM-DD y HH:MM:SS.
3.Si falla, el programa debe imprimir un mensaje de error similar a:
	Error executing date: No such file or directory

Sugerencias para implementar:

Usa printf para mostrar mensajes informativos.
Usa perror para manejar errores en caso de que execve falle.

cc -Wall -Werror -Wextra 4.2_ejerc.c -o 4.2_ejerc
*/


#include <stdio.h> //perror
#include <unistd.h> // read, execve
#include <fcntl.h> // open
#include <stdio.h>	//printf


int main (void)
{

	char *argv[] = {"/bin/date", "+%Y-%m-%d-%T", NULL};
	char *envp[]={NULL};

	printf ("Executing date");

	if (execve("/bin/date", argv, envp) == -1)
	{
		perror ("Error executing date: No such file or directory");
		return (1);
	}
	
	return (0);
}