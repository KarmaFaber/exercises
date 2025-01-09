/*
4.3 **uso funcion execve() y access**    
    -escrive un programa usando fucnion execve(), access y variebles de entorno.
	-formato main: int main(int argc, char *argv[], char *envp[])

Enunciado: Ejecutar un programa con execve y verificar su existencia con access
Título: Ejecutar un comando externo utilizando execve y comprobar su existencia con access

Objetivo: 
	Escribir un programa en C que reciba un comando (como un programa ejecutable) 
	como argumento, verifique si el archivo del comando existe utilizando la función access, 
	y si es así, ejecute el comando utilizando execve. Además, el programa debe mostrar el 
	valor de una variable de entorno antes de ejecutar el comando.

Requerimientos:
	El programa debe tomar el nombre de un archivo ejecutable como argumento en la línea de comandos.
	Usando la función access(), el programa debe comprobar si el archivo proporcionado existe y si tiene permisos de ejecución.
	Si el archivo existe y tiene permisos de ejecución:
	El programa debe mostrar el valor de la variable de entorno PATH antes de ejecutar el comando.
	Luego, usar la función execve para ejecutar el archivo proporcionado como argumento.
	Si el archivo no existe o no tiene permisos de ejecución, el programa debe imprimir un mensaje de error.

Detalles:
	Ruta de ejecución: El archivo ejecutable puede ser proporcionado como argumento en la línea de comandos. Ejemplo de ejecución:
	./programa /bin/ls


Acción:
	Verificar si el archivo existe y tiene permisos de ejecución con access(argv[1], X_OK).
	Si el archivo tiene permisos, ejecutar el comando usando execve.
	Antes de ejecutar, mostrar el valor de la variable de entorno PATH.
	Si el archivo no existe o no tiene permisos, imprimir un mensaje de error adecuado.


Formato de entrada:
	El programa debe recibir un único argumento en la línea de comandos, el cual es la ruta al ejecutable.

Salida esperada:
Si el archivo proporcionado existe y tiene permisos de ejecución:
	Valor de PATH: /usr/bin:/bin:/usr/sbin:/sbin
	Ejecutando: /bin/ls

Si el archivo no existe o no tiene permisos:
	Error: El archivo /bin/ls no existe o no tiene permisos de ejecución

Sugerencias para implementar:
	Usa access() para verificar si el archivo existe y si es ejecutable (modo X_OK).
	Usa execve() para ejecutar el archivo proporcionado como argumento.
	Usa getenv("PATH") o accede directamente a envp[] para obtener el valor de la variable de entorno PATH.
	Asegúrate de que el programa maneje correctamente los errores si el archivo no existe o no tiene los permisos adecuados.

cc -Wall -Werror -Wextra 4.3_ejerc.c -o 4.3_ejerc

./4.3_ejerc ex1.sh 
*/

#include <stdio.h> //perror
#include <unistd.h> // read, execve
#include <fcntl.h> // open
#include <stdio.h>	//printf
#include <string.h> 
#include <stdbool.h>

bool is_logname(char **envp, char *find)
{   
    int i = 0;

    // Recorremos el array envp hasta encontrar un NULL (final de la lista)
    while (envp[i] != NULL)
    {
        // Comparamos cada variable de entorno con "LOGNAME=" seguido del valor
        if (strncmp(envp[i], "LOGNAME=", 8) == 0) // 8 es la longitud de "LOGNAME="
        {
            // Si la comparación es exitosa, verificamos si los valores coinciden
            if (strcmp(&envp[i][8], find) == 0)
            {
                return true; // Si el valor de LOGNAME coincide con el `find`, lo hemos encontrado
            }
        }
        i++;
    }
    return false; // Si no se encuentra en ninguna parte
}

int main(int argc, char *argv[], char **envp)
{

	if (argc < 2) {
        perror("Error: Debes proporcionar un archivo ejecutable como argumento.\n");
        return 1;
    }
	
	char *exec_argv[] = {argv[1], NULL};  // Solo el archivo a ejecutar
    char *exec_envp[] = {NULL};


	//envp: 8, LOGNAME=mzolotar
	/*
	int i=0;
	while(envp[i] != NULL)
	{
		printf("%i, %s\n", i, envp[i]);
		i++;
	}
	printf("\n\n\n");
	*/

	//access + execve:
	
	if (access( "./ex1.sh", F_OK | X_OK) == -1)
	{
		perror("error al comprobar permisos de ex1.sh");
		return (1);
	}
	else if  (!is_logname(envp, "mzolotar"))
	{
		perror("error en encontrar LOGNAME=mzolotar ");
		return (1);
	}
	else
	{	
		printf("Ejecutando: %s\n", argv[1]);
		if (execve("./ex1.sh", exec_argv, exec_envp) == -1)
		{

			perror("error al ejecutar .sh");
			return (1);
		}
	}
	

	return (0);
}