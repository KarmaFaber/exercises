/*
10. **Pipes múltiples:**
    - Implementa un programa que use dos pipes para conectar tres procesos:
        - Proceso 1 escribe en el pipe 1.
        - Proceso 2 lee del pipe 1, transforma el contenido (alfa -> hexadec) y escribe en el pipe 2.
        - Proceso 3 lee del pipe 2 y lo imprime.
		- se puede hacer con pipes o con fork. ver 2 procesos ejerc 7.0 y 7.1

    opciones para hacer el ejerc:
        - abuelo | padre | hijo ->  bash: "echo "hello world" | tr '[:lower:]' '[:upper:]' | cat"
        - pipe1 y pipe2: padre | hijo 2 veces. 
    
    procesos/comandos:
    ./10.1_ejerc

    input: process4.sh
        echo "abcdefxyz"
    output esperado:
        012345678f


cc -Wall -Werror -Wextra -g 10.1_ejerc.c -o 10.1_ejerc

(alpha -> hexadec)      ./10.1_ejerc process1.sh process4.sh process4.sh 

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(void) {
    int pipe1[2];
    int pipe2[2];
    pid_t pid_child, pid_grandchild;

    // Crear pipe1 para Proceso 1 -> Proceso 2
    if (pipe(pipe1) == -1) {
        perror("Error creando pipe1");
        return (1);
    }

    // Crear el proceso hijo (Proceso 2)
    pid_child = fork();
    if (pid_child == -1) {
        perror("Error al crear el proceso hijo");
        return (1);
    }

    if (pid_child == 0) {
        // En el proceso hijo (Proceso 2)
        if (pipe(pipe2) == -1) {
            perror("Error creando pipe2");
            exit(1);
        }

        pid_grandchild = fork();
        if (pid_grandchild == -1) {
            perror("Error al crear el proceso nieto");
            exit(1);
        }

        if (pid_grandchild == 0) {
            // Proceso nieto (Proceso 3)
            close(pipe2[1]);  // Cerrar el extremo de escritura del pipe2
            dup2(pipe2[0], STDIN_FILENO); // Redirigir entrada estándar al pipe2
            close(pipe2[0]);  // Cerrar el extremo de lectura original

            execlp("./process3.sh", "process3.sh", NULL);
            perror("Error ejecutando Proceso 3");
            exit(1);
        } else {
            // Proceso hijo (Proceso 2)
            close(pipe1[1]);  // Cerrar el extremo de escritura del pipe1
            dup2(pipe1[0], STDIN_FILENO); // Redirigir entrada estándar al pipe1
            close(pipe1[0]);  // Cerrar el extremo de lectura original

            close(pipe2[0]);  // Cerrar el extremo de lectura del pipe2
            dup2(pipe2[1], STDOUT_FILENO); // Redirigir salida estándar al pipe2
            close(pipe2[1]);  // Cerrar el extremo de escritura original

            execlp("./process4.sh", "process4.sh", NULL);
            perror("Error ejecutando Proceso 2");
            exit(1);
        }
    } else {
        // Proceso padre (Proceso 1)
        close(pipe1[0]);  // Cerrar el extremo de lectura del pipe1
        dup2(pipe1[1], STDOUT_FILENO); // Redirigir salida estándar al pipe1
        close(pipe1[1]);  // Cerrar el extremo de escritura original

        execlp("./process1.sh", "process1.sh", NULL);
        perror("Error ejecutando Proceso 1");
        exit(1);
    }

    // Esperar a que todos los procesos hijos terminen
    wait(NULL); // Proceso padre espera al hijo
    return 0;
}
