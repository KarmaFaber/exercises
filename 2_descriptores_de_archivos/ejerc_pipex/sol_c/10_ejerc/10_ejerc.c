/*
10. **Pipes múltiples:**
    - Implementa un programa que use dos pipes para conectar tres procesos:
        - Proceso 1 escribe en el pipe 1.
        - Proceso 2 lee del pipe 1, transforma el contenido y escribe en el pipe 2.
        - Proceso 3 lee del pipe 2 y lo imprime.
		- se puede hacer con pipes o con fork. ver 2 procesos ejerc 7.0 y 7.1


	cc -Wall -Werror -Wextra 10_ejerc.c -o 10_ejerc
*/

#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2, dup
#include <fcntl.h> // open
#include <stdlib.h> //exit
#include <string.h> // strlen

int main (void)
{


	return (0);
}