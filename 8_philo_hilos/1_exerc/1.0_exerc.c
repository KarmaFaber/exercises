/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.0_exerc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:23:52 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/29 18:18:29 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1.0 **Crear 5 hilos con pthread y que cada hilo imprima su ID**:
   - Usa la librería `pthread`.
   - Define una función que los hilos ejecutarán.
   - Crea 5 hilos con `pthread_create` y pasa el ID como argumento.
   - Usa `pthread_join` para esperar a que terminen.

pthread:

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
int pthread_join(pthread_t thread, void **retval);

cc -Wall -Werror -Wextra 1.0_exerc.c -o 1.0_exerc -lpthread 

*/

# include "../exerc.h"

void *print_thread_id(void *arg) 
{
    int thread_id;

    thread_id = *(int *)arg; // Obtener el ID pasado como argumento
    
    printf("ID del Hilo %d: y su identificador: %lu\n", thread_id, pthread_self());

    free(arg);
    return NULL;
}

//main ID con malloc:
int main() 
{
    pthread_t threads[5];
    int *id;
    int i;
    
    i=0;
    // Crear varios hilos que impriman ID de cada hilo pasado por argumento desde print_thread_id
    while (i<5)
    {
        id = malloc(sizeof(int));
        *id = i + 1; // Asignar un ID (personalizado) único para cada hilo.
        if (pthread_create(&threads[i], NULL, print_thread_id, id) != 0)
        {
            perror ("Error creating threads");
            return (1);
        }
        i++;
    }
    
    // Esperar a que termine
    i=0;
    while (i<5)
    {
        pthread_join(threads[i], NULL);
        i++;
    }
     
    printf("\n--------Hilos finalizados.-----------\n");
    return 0;
}

//main sin malloc para los ID:
/*
int main() {
    pthread_t threads[5];
    int thread_ids[5]; 
    int i;
    
    i=0;
    // Crear varios hilos que impriman ID de cada hilo pasado por argumento desde print_thread_id
    while (i<5)
    {
        thread_ids[i] = i + 1; // Asignar un ID (personalizado) único para cada hilo.
        if (pthread_create(&threads[i], NULL, print_thread_id, &thread_ids[i]) != 0)
        {
            perror ("Error creating threads");
            return (1);
        }
        i++;
    }
    
    // Esperar a que termine
    i=0;
    while (i<5)
    {
        pthread_join(threads[i], NULL);
        i++;
    }
     
    printf("\n--------Hilos finalizados.-----------\n");
    return 0;
}

*/




