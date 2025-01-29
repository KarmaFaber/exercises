/*
¿Qué es un Data Race?
Un data race ocurre en programación concurrente cuando dos o más hilos acceden a la misma variable compartida simultáneamente, 
y al menos uno de los accesos es una escritura, sin una sincronización adecuada. Esto puede provocar comportamientos impredecibles 
y errores difíciles de depurar.

Se usa pthread_mutex_t para garantizar que solo un hilo acceda a la variable compartida a la vez.
* pthread_mutex_lock(&mutex): Bloquea el acceso a la variable contador.
* contador++: Se ejecuta de forma segura sin interferencias.
* pthread_mutex_unlock(&mutex): Libera el acceso para otros hilos.


cc -Wall -Werror -Wextra 0_exerc.c -o 0_exerc
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_datos 
{
    int contador;           // Variable compartida
    pthread_mutex_t mutex;  // Mutex para evitar condiciones de carrera
} t_datos;

void *incrementar(void *arg) 
{
    t_datos *datos;  // Convertimos el argumento a un puntero a estructura
	int i;
    
	datos = (t_datos *)arg;
	i = 0;
    while (i < 10) 
	{
        pthread_mutex_lock(&datos->mutex);  // Bloquea el acceso
        datos->contador++;                  // Sección crítica
        pthread_mutex_unlock(&datos->mutex); // Desbloquea el acceso
		i++;
    }
    return NULL;
}

int main() 
{
    pthread_t t1;
	pthread_t t2;
    t_datos datos;  // Crear la estructura en el stack

    datos.contador = 0;
    pthread_mutex_init(&datos.mutex, NULL); // Inicializar mutex

    pthread_create(&t1, NULL, incrementar, &datos);
    pthread_create(&t2, NULL, incrementar, &datos);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Valor final del contador: %d\n", datos.contador);

    pthread_mutex_destroy(&datos.mutex); // Liberar mutex
    return 0;
}


/*
// Crear un hilo
	if (pthread_create(&thread, NULL, hello, NULL) != 0) 
    {
		perror("Error al crear el hilo");
		return 1;
	}
*/