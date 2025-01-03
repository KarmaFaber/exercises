/*
5. **Redirección de salida estándar:**
    - Usa `dup2` para redirigir la salida estándar a un archivo llamado `stdout_redirect.txt`.
    ejemplo bash: "ls > list.tx"


NOTAS:

man dup:
dup, dup2, dup3 - duplicate a file descriptor

int dup(int oldfd);
int dup2(int oldfd, int newfd);
int dup3(int oldfd, int newfd, int flags);



cc -Wall -Werror -Wextra 5.1_ejerc.c -o 5.1_ejerc
*/

#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2
#include <fcntl.h> // open
#include <stdlib.h> //exit


