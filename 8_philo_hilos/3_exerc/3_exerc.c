/*
3. **Medir tiempo de ejecución con gettimeofday**:
   - Usa `gettimeofday` para obtener el tiempo antes y después de ejecutar una función.
   - Calcula la diferencia entre ambos valores.


cc -Wall -Werror -Wextra 3_exerc.c -o 3_exerc -lpthread 
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./3_exerc
*/

#include "../exerc.h"    

// Función para calcular el tiempo transcurrido en microsegundos
long long time_diff(struct timeval start, struct timeval end) 
{
    long long start_usec = (long long) start.tv_sec * 1000000LL + start.tv_usec;
    long long end_usec = (long long) end.tv_sec * 1000000LL + end.tv_usec;
    return (end_usec - start_usec);  // Retorna la diferencia en microsegundos
}

int main() 
{
    struct timeval start, end;

    // Obtener la hora de inicio
    gettimeofday(&start, NULL);
    
    // Simular algún proceso (espera de 2 segundos)
    usleep(2000000);

    // Obtener la hora de fin
    gettimeofday(&end, NULL);

    // Calcular el tiempo transcurrido
    long long elapsed_time = time_diff(start, end);

    // Mostrar el tiempo en milisegundos para mayor claridad
    printf("Tiempo transcurrido: %lld microsegundos (%.3f segundos)\n", elapsed_time, elapsed_time / 1e6);

    return 0;
}

