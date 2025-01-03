/*
5. **Redirección de salida estándar:**
    - Escribe un programa en C que redirija la salida estándar (stdout) a un archivo llamado stdout_redirect.txt utilizando la función dup.
    ejemplo bash: "ls > list.tx"

Objetivo:
El programa debe:

Abrir o crear un archivo llamado stdout_redirect.txt en modo de escritura.
Utilizar dup para duplicar el descriptor de archivo de stdout y redirigirlo al archivo stdout_redirect.txt.
Escribir algunos mensajes a la salida estándar y asegurarse de que estos mensajes se escriban en el archivo stdout_redirect.txt en lugar de en la consola.
Restaurar la salida estándar original después de realizar la redirección.
Requisitos:
El archivo stdout_redirect.txt debe ser creado o sobrescrito si ya existe.
El programa debe redirigir la salida estándar utilizando dup para lograr que todo lo que normalmente se imprimiría en la consola se escriba en el archivo.
El programa debe restaurar la salida estándar original utilizando dup2.
Formato de entrada:
El programa no necesita entrada de usuario.
Salida esperada:
El archivo stdout_redirect.txt debe contener los mensajes que el programa haya intentado imprimir a la salida estándar.


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


