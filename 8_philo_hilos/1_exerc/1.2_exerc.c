/*
 -1.2 **crear n hilos pasados por argumento con mutex**
	- Usa la librería pthread.
    - Define una función que los hilos ejecutarán.
    - Utiliza una variable compartida para almacenar el turno de ejecución de los hilos.
    - Protege el acceso a la variable compartida con un pthread_mutex_t para evitar condiciones de carrera.
    - Crea n > 1 hilos con pthread_create, pasando el ID como argumento.
    - Usa pthread_join para esperar a que todos los hilos terminen. 


cc -Wall -Werror -Wextra 1.2_exerc.c -o 1.2_exerc -lpthread 

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./1.2_exerc 7


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
bool check_argc(int argc_var)
{
	if (argc_var != 2)
	{
		perror("numero de argc incorrecto");
		return (0);
	}
	return (1);
}


void *print_thread_turn(void *arg) 
{
	t_data *data;		//variable compartida por los hilos

	data  = (t_data *)arg;
	
	while (1)
	{
		pthread_mutex_lock(&data->mutex);  // Bloquea el acceso

		if (data->turn > 15) // 🚨 Límite máximo para evitar bucle infinito
        {
            pthread_mutex_unlock(&data->mutex);
            break;
        }

		printf("turno del hilo: %d\n", data->turn); // Variable compartida

		data->turn++; // Modifica la variable compartida

		pthread_mutex_unlock(&data->mutex); // Desbloquea el acceso
		usleep(10000); // Pequeña pausa para evitar que un solo hilo tome todo el turno. Esto permite que otros hilos tengan oportunidad de ejecutar.
	}
    
    return NULL;
}


int create_treads (char *argv_var)
{
	int num;
	int i;
	pthread_t *threads; //hilos
	t_data *data;	

	data = 	malloc(sizeof(t_data)); // Se debe reservar memoria para `data`
	if (!data)
    {
        perror("Error al asignar memoria para la estructura de datos");
        return (0);
    }

	i=0;
	data->turn = 1;
	num = ft_atoi (argv_var);
	if (num < 1)
	{
		perror ("El número de hilos debe ser mayor que 0\n");
		free(data);
		return (0);
	}

	threads = malloc(sizeof(pthread_t) * num);
	if (!threads)
	{
		perror("Error al asignar memoria para los hilos");
		free(data);
		return (0);
	}

	pthread_mutex_init(&data->mutex, NULL); // Inicializar mutex

	while (i<num)
	{
	
		if (pthread_create(&threads[i], NULL, print_thread_turn, data) != 0)
		{
			perror ("Error creating threads");
			free(threads);
			free(data);
			return (0);
		}
		i++;
	}

	i=0;
	while (i < num)
	{
		pthread_join(threads[i], NULL);
		i++;
	}

	pthread_mutex_destroy(&data->mutex); // Liberar mutex
	free(data);
	free(threads);
	return (1);
}

int main (int argc, char *argv[])
{
	
	if (!check_argc(argc) || !(argv[1][0]))
		return (1);

	if (!create_treads (argv[1]))
		return (1);

	return (0);
}
