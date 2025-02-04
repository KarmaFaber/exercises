/*
6. **Temporizador que imprime un mensaje cada segundo**:
    - Usa un bucle con `usleep(1000000)` dentro de un hilo.

Compilación:
cc -Wall -Werror -Wextra 6_exerc.c -o 6_exerc -lpthread 

Ejecutar con Valgrind:
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./6_exerc
*/

#include "../exerc.h"   

// Función que ejecutará el hilo
void *temporizador(void *arg)
{
    (void)arg; // Evita advertencias de compilación si no se usa el argumento
    
    while (1) 
    {
        printf("Temporizador: Ha pasado 1 segundo\n");
        usleep(1000000); // Pausa de 1 segundo (1,000,000 microsegundos)
    }

    return NULL;
}

int main(void)
{
    pthread_t hilo;

    // Crear el hilo del temporizador
    if (pthread_create(&hilo, NULL, temporizador, NULL) != 0) 
    {
        perror("Error al crear el hilo");
        return EXIT_FAILURE;
    }

    // Esperar unos segundos antes de terminar el programa
    sleep(5);  // Detén el programa después de 5 segundos

    printf("Finalizando el programa\n");

    // Terminar el hilo (en este caso, lo cancelamos)
    pthread_cancel(hilo);
    pthread_join(hilo, NULL);

    return EXIT_SUCCESS;
}
