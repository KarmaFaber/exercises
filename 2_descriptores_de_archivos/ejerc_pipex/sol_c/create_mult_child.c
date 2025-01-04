
//crear varios procesos hijos

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
    int num_children = 5;  // Número de procesos hijos a crear
    int created_children = 0;  // Contador de hijos creados
    pid_t pid;

    while (created_children < num_children) {
        pid = fork();  // Crear un proceso hijo

        if (pid == -1) {
            perror("Error al crear el proceso hijo");
            exit(1);
        } else if (pid == 0) {
            // Código del proceso hijo
            printf("Soy el hijo %d con PID %d\n", created_children + 1, getpid());
            exit(0);  // Finalizar el proceso hijo
        } else {
            // Código del proceso padre
            printf("Padre creó al hijo %d con PID %d\n", created_children + 1, pid);
            created_children++;  // Incrementar contador en el proceso padre
        }
    }

    // El padre espera a que todos los hijos terminen
    while (num_children > 0) {
        wait(NULL);  // Espera a que un hijo termine
        num_children--;  // Decrementa el número de hijos restantes
    }

    printf("Todos los procesos hijos han terminado\n");

    return 0;
}
