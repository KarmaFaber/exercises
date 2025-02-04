
/*
9.0 **Simulación de los filósofos con 2 filósofos y 2 tenedores**:
    - Usa `pthread_mutex_t` para representar los tenedores.
    - Controla el acceso a los tenedores con `pthread_mutex_lock` y `pthread_mutex_unlock`.
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_program
{
	unsigned short int num_philos;
	unsigned int num_times_to_eat;

	time_t	start_time;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;

	bool dead;

	pthread_mutex_t *forks;
	pthread_mutex_t write_lock;
	pthread_mutex_t dead_lock;
	pthread_mutex_t meal_lock;
	struct s_philo *philos;

}	t_program;

typedef struct s_philo
{
	pthread_t thread;
	unsigned short int id;
	unsigned int meals_eaten;
	time_t last_meal;

	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
	
	bool dead_philo;
	
	t_program *program;

}	t_philo;

time_t timestamp(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void print_action(t_philo *philo, const char *action)
{
	pthread_mutex_lock(&philo->program->write_lock);
	if (!philo->program->dead)
		printf("%ld %hu %s\n", timestamp() - philo->program->start_time, philo->id, action);
	pthread_mutex_unlock(&philo->program->write_lock);
}

void *philosopher_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	while (!philo->program->dead)
	{
		// Tomar tenedores
		pthread_mutex_lock(philo->l_fork);
		print_action(philo, "ha tomado un tenedor");
		pthread_mutex_lock(philo->r_fork);
		print_action(philo, "ha tomado un tenedor");

		// Comer
		print_action(philo, "está comiendo");
		philo->last_meal = timestamp();
		usleep(philo->program->time_to_eat * 1000);
		philo->meals_eaten++;

		// Soltar tenedores
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);

		// Dormir
		print_action(philo, "está durmiendo");
		usleep(philo->program->time_to_sleep * 1000);

		// Pensar
		print_action(philo, "está pensando");
	}
	return NULL;
}

int init_program(t_program *program)
{
	program->num_philos = 2;
	program->time_to_die = 600;
	program->time_to_eat = 200;
	program->time_to_sleep = 200;
	program->num_times_to_eat = -1;
	program->dead = false;
	program->start_time = timestamp();

	// Inicializar mutexes
	program->forks = malloc(sizeof(pthread_mutex_t) * program->num_philos);
	for (int i = 0; i < program->num_philos; i++)
		pthread_mutex_init(&program->forks[i], NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);

	// Inicializar filósofos
	program->philos = malloc(sizeof(t_philo) * program->num_philos);
	for (int i = 0; i < program->num_philos; i++)
	{
		program->philos[i].id = i + 1;
		program->philos[i].meals_eaten = 0;
		program->philos[i].last_meal = timestamp();
		program->philos[i].l_fork = &program->forks[i];
		program->philos[i].r_fork = &program->forks[(i + 1) % program->num_philos];
		program->philos[i].program = program;
	}
	return (1);
}

int init_philo(t_program *program)
{
	for (int i = 0; i < program->num_philos; i++)
		pthread_create(&program->philos[i].thread, NULL, philosopher_routine, &program->philos[i]);

	for (int i = 0; i < program->num_philos; i++)
		pthread_join(program->philos[i].thread, NULL);
	return (1);
}

void free_all(t_program *program)
{
	for (int i = 0; i < program->num_philos; i++)
		pthread_mutex_destroy(&program->forks[i]);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	free(program->forks);
	free(program->philos);
}

int main(void)
{
	t_program program;

	if (!init_program(&program))
		return (1);
	init_philo(&program);
	free_all(&program);
	return (0);
}
