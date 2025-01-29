/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.1_exerc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:59:32 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/29 18:35:40 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1.1 **crear n hilos pasados por argumento**
	- Usa la librería `pthread`.
   - Define una función que los hilos ejecutarán.
   - Crea n>1 hilos con `pthread_create` y pasa el ID como argumento.
   - Usa `pthread_join` para esperar a que terminen.

pthread:

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
int pthread_join(pthread_t thread, void **retval);

cc -Wall -Werror -Wextra 1.1_exerc.c -o 1.1_exerc 
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./1.1_exerc 7

*/

# include "../exerc.h"

int	ft_atoi(const char *nptr)
{
	short	sign;
	int		number;

	sign = 1;
	number = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		number = number * 10 + (*nptr - '0');
		nptr++;
	}
	return (number * sign);
}

void *print_thread_id(void *arg) 
{
    int thread_id;

    thread_id = *(int *)arg; // Obtener el ID pasado como argumento
    
    printf("ID del Hilo %d: y su identificador: %lu\n", thread_id, pthread_self());

    free(arg);
    return NULL;
}

int main (int argc, char *argv[])
{
   if (argc == 2)
   {
      int num;
      int i;
      int *id;
      pthread_t *threads;
      i=0;
      num = ft_atoi (argv[1]);
      
      if (num < 1)
      {
         perror ("El número de hilos debe ser mayor que 0\n");
         return 1;
      }

      threads = malloc(sizeof(pthread_t) * num);
      if (!threads)
      {
         perror("Error al asignar memoria para los hilos");
         return 1;
      }
      while (i<num)
      {
         id = malloc(sizeof(int));
         if (!id)
         {
            perror("Error al asignar memoria para ID del hilo");
            free(threads);
            return 1;
         }
        *id = i + 1; // Asignar un ID (personalizado) único para cada hilo.
        
        
        
         if (pthread_create(&threads[i], NULL, print_thread_id, id) != 0)
        {
            perror ("Error creating threads");
            free(id);
            free(threads);
            return (1);
        }
        
         i++;
      }
      
      i=0;
      while (i<num)
      {
         pthread_join(threads[i], NULL);
         i++;
      }
   free(threads);
   }
   else if (argc != 2)
   {
      perror("numero de argc incorrecto");
      return 1;
   }
   
	return (0);
}
