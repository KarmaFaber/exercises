/*
4.1 **uso funcion execve()**    
    -escrive un programa usando fucnion execve().
	Ejecutar un programa externo con argumentos usando execve
	-formato main: int main(void)

Escribe un programa en C que utilice la función execve para ejecutar el comando ls con los argumentos -l y -a. El programa debe:

Mostrar un mensaje indicando que está a punto de ejecutar el comando.
Reemplazar el proceso actual por el comando ls.
Si la ejecución de execve falla, debe imprimir un mensaje de error usando perror.

Detalles:

Ruta del ejecutable: /bin/ls.
Argumentos a pasar:
argv[0]: Nombre del programa (por convención, ls).
argv[1]: Argumento -l (formato largo).
argv[2]: Argumento -a (incluir archivos ocultos).
argv[3]: NULL (para indicar el final de los argumentos).
No es necesario modificar el entorno, utiliza el entorno actual del programa.

Salida esperada:

1. Antes de ejecutar ls, el programa debe imprimir:
Executing ls -l -a...

2. Si execve tiene éxito, el proceso actual se reemplazará por ls -l -a.

3.Si falla, el programa debe imprimir un mensaje de error similar a:
Error executing ls: No such file or directory


Sugerencias para implementar:
Usa printf para mostrar mensajes informativos.
Usa perror para manejar errores en caso de que execve falle.

cc -Wall -Werror -Wextra 4.1_ejerc.c -o 4.1_ejerc
*/


#include <stdio.h> //perror
#include <unistd.h> // read, execve
#include <fcntl.h> // open
#include <stdio.h>	//printf


//para un ejecutable de bash: ls

int main (void)
{
	char *exec_argv[] = {"/bin/|'", NULL};
	char *exec_envp[] ={NULL};


	//printf ("Executing command...\n");

	if (execve("/bin/|", exec_argv, exec_envp) == -1)
	{
		perror("Error executing: ...");
		return (1);
	}

	return (0);
}

