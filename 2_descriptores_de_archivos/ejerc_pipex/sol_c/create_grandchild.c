//crear hijos, nietos, etc.


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipe1[2], pipe2[2];  // Pipes para comunicación entre procesos
    pid_t pid_hijo, pid_nieto, pid_visnieto;

    // Crear el primer pipe entre el padre y el hijo
    if (pipe(pipe1) == -1) {
        perror("Error al crear pipe1");
        exit(1);
    }

    pid_hijo = fork();  // Crear el proceso hijo
    if (pid_hijo == -1) {
        perror("Error al crear el hijo");
        exit(1);
    }

    if (pid_hijo == 0) {
        // Hijo: Crear el proceso nieto
        close(pipe1[1]);  // El hijo cierra el extremo de escritura del primer pipe

        if (pipe(pipe2) == -1) {
            perror("Error al crear pipe2");
            exit(1);
        }

        pid_nieto = fork();  // Crear el proceso nieto
        if (pid_nieto == -1) {
            perror("Error al crear el nieto");
            exit(1);
        }

        if (pid_nieto == 0) {
            // Nieto: Crear el proceso visnieto
            close(pipe2[1]);  // El nieto cierra el extremo de escritura del segundo pipe

            pid_visnieto = fork();  // Crear el proceso visnieto
            if (pid_visnieto == -1) {
                perror("Error al crear el visnieto");
                exit(1);
            }

            if (pid_visnieto == 0) {
                // Visnieto: Imprimir un mensaje
                printf("Soy el visnieto (PID: %d)\n", getpid());
                exit(0);
            } else {
                // Nieto espera a que el visnieto termine
                wait(NULL);
                printf("Soy el nieto (PID: %d), mi visnieto ya terminó.\n", getpid());
                exit(0);
            }

        } else {
            // Hijo espera a que el nieto termine
            wait(NULL);
            printf("Soy el hijo (PID: %d), mi nieto ya terminó.\n", getpid());

            // El hijo lee del pipe1 y envía el mensaje al padre
            char buffer[100];
            close(pipe1[0]);  // El hijo cierra el extremo de lectura del pipe1
            write(pipe1[1], "Mensaje desde el hijo", 21);
            close(pipe1[1]);
            exit(0);
        }

    } else {
        // Padre: Espera a que el hijo termine
        wait(NULL);
        printf("Soy el padre (PID: %d), mi hijo ya terminó.\n", getpid());

        // El padre lee del pipe1
        char buffer[100];
        close(pipe1[1]);  // El padre cierra el extremo de escritura del pipe1
        read(pipe1[0], buffer, sizeof(buffer));
        close(pipe1[0]);

        printf("El mensaje recibido en el padre: %s\n", buffer);
    }

    return 0;
}
