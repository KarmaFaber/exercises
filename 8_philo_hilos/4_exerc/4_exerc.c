#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>

// Estructura de una tarea en la cola
typedef struct s_task
{
    void (*function)(void *arg);  // Puntero a la función de la tarea
    void *arg;                    // Argumento de la tarea
    struct s_task *next;           // Siguiente tarea en la cola
}   t_task;

// Estructura de la cola de tareas
typedef struct s_task_queue
{
    t_task *front;               // Primer tarea en la cola
    t_task *rear;                // Última tarea en la cola
    pthread_mutex_t mutex;       // Mutex para proteger la cola
}   t_task_queue;

// Estructura del filósofo
typedef struct s_philo
{
    pthread_t thread;             // Hilo del filósofo
    unsigned short int id;        // ID del filósofo
    unsigned int meals_eaten;     // Número de comidas consumidas
    time_t last_meal;             // Última vez que comió

    pthread_mutex_t *l_fork;      // Puntero al mutex del tenedor izquierdo
    pthread_mutex_t *r_fork;      // Puntero al mutex del tenedor derecho

    bool dead_philo;
    
    struct s_program *program;    // Referencia a la estructura principal

}   t_philo;

// Estructura del programa principal
typedef struct s_program
{
    unsigned short int num_philos; // Número total de filósofos
    unsigned int num_times_to_eat; // Número de veces que deben comer

    time_t start_time;
    time_t time_to_die;
    time_t time_to_eat;
    time_t time_to_sleep;

    bool dead;                     // Bandera de estado de muerte

    pthread_mutex_t *forks;         // Array de mutex para los tenedores
    pthread_mutex_t write_lock;     // Mutex para controlar impresiones
    pthread_mutex_t dead_lock;      // Mutex para proteger la variable `dead`
    pthread_mutex_t meal_lock;      // Mutex para verificar si todos comieron

    t_philo *philos;                // Array de filósofos
    t_task_queue task_queue;        // Cola de tareas

}   t_program;

// Inicializa la cola de tareas
void init_task_queue(t_task_queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
    pthread_mutex_init(&queue->mutex, NULL);
}

// Agrega una tarea a la cola
void enqueue_task(t_task_queue *queue, void (*function)(void *), void *arg)
{
    t_task *new_task = malloc(sizeof(t_task));
    if (!new_task)
        return;
    
    new_task->function = function;
    new_task->arg = arg;
    new_task->next = NULL;

    pthread_mutex_lock(&queue->mutex);
    if (queue->rear)
        queue->rear->next = new_task;
    else
        queue->front = new_task;
    queue->rear = new_task;
    pthread_mutex_unlock(&queue->mutex);
}

// Extrae y ejecuta una tarea de la cola
void *dequeue_task(void *arg)
{
    t_task_queue *queue = (t_task_queue *)arg;
    while (1)
    {
        pthread_mutex_lock(&queue->mutex);
        t_task *task = queue->front;
        if (task)
        {
            queue->front = task->next;
            if (!queue->front)
                queue->rear = NULL;
            pthread_mutex_unlock(&queue->mutex);

            // Ejecuta la tarea
            task->function(task->arg);
            free(task);
        }
        else
        {
            pthread_mutex_unlock(&queue->mutex);
            usleep(1000);  // Pequeña espera para evitar consumo excesivo de CPU
        }
    }
    return NULL;
}

// Funciones de los filósofos
void take_forks(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    pthread_mutex_lock(philo->l_fork);
    pthread_mutex_lock(philo->r_fork);
    printf("Filósofo %d ha tomado los tenedores\n", philo->id);
}

void eat(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    printf("Filósofo %d está comiendo\n", philo->id);
    usleep(philo->program->time_to_eat * 1000);
    philo->meals_eaten++;
}

void release_forks(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
    printf("Filósofo %d ha soltado los tenedores\n", philo->id);
}

void sleep_philo(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    printf("Filósofo %d está durmiendo\n", philo->id);
    usleep(philo->program->time_to_sleep * 1000);
}

void think(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    printf("Filósofo %d está pensando\n", philo->id);
}

// Hilo del filósofo
void *philosopher_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    t_program *program = philo->program;

    while (!program->dead)
    {
        enqueue_task(&program->task_queue, take_forks, philo);
        enqueue_task(&program->task_queue, eat, philo);
        enqueue_task(&program->task_queue, release_forks, philo);
        enqueue_task(&program->task_queue, sleep_philo, philo);
        enqueue_task(&program->task_queue, think, philo);
    }
    return NULL;
}

// Inicialización de los filósofos y la cola de tareas
void init_simulation(t_program *program)
{
	int i; 
    // Inicializar la cola de tareas
    init_task_queue(&program->task_queue);
    
    // Crear el hilo de la cola de tareas
    pthread_t queue_thread;
    pthread_create(&queue_thread, NULL, dequeue_task, &program->task_queue);

    // Crear los hilos de los filósofos
	i=0;
    while (i < program->num_philos)
    {
		program->philos[i].id = i + 1;  // Asignar un ID único a cada filósofo
        pthread_create(&program->philos[i].thread, NULL, philosopher_routine, &program->philos[i]);
		i++;
    }

    // Esperar a los filósofos
	i=0;
    while (i < program->num_philos)
    {
        pthread_join(program->philos[i].thread, NULL);
		i++;
    }

    // Terminar la cola de tareas
    pthread_cancel(queue_thread);
    pthread_join(queue_thread, NULL);
}

// Función principal
int main(void)
{
    t_program program;
    program.num_philos = 5;
    program.time_to_eat = 2000;
    program.time_to_sleep = 3000;
    program.dead = false;
    program.philos = malloc(sizeof(t_philo) * program.num_philos);

    init_simulation(&program);
    
    free(program.philos);
    return 0;
}
