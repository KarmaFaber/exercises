/*Ejercicio 4: Callbacks en una Función de Búsqueda
Crea un programa que busque un valor en un array, utilizando una función de callback para definir el criterio de búsqueda.

Enunciado:

Define varias funciones de comparación que puedan ser usadas como criterios de búsqueda. Ejemplos: es_mayor_que, es_menor_que, es_igual_a.
Crea una función buscar que reciba un array, su tamaño, un valor de referencia y un puntero a una función de comparación. Esta función debe
 retornar el índice del primer elemento que cumpla con el criterio de comparación.
En el main, usa diferentes criterios de búsqueda para encontrar elementos en un array.
Ejemplo de prototipo de la función buscar:

int buscar(int *array, int n, int referencia, int (*criterio)(int, int));*/

#include <stdio.h>

int es_mayor_que (int a, int b)
{
    return a > b;  
}

int es_menor_que (int a, int b)
{
    return a < b;    
}

int es_igual (int a, int b)
{
    return a == b;      
}

int buscar(int *array, int n, int referencia, int (*criterio)(int, int))
{
    int i=0;
    while (i<n)
    {
        if (criterio(array[i], referencia) == 1)
            return i;
        i++;
    }
    return -1; // no se ha encontrado el numero referencia en el array
}

int main(void)
{
    int array[]= {1, 5, 77, 56, 102};
    int n = sizeof(array) / sizeof(array[0]);
    
    int (*f_p)(int, int)=es_mayor_que;
    int resultado =buscar(array, n, 1002, f_p);
    printf("%i\n\n", resultado);
    
    if (resultado != -1) {
        printf("El elemento se encontró en el índice: %i\n", resultado);
    } else {
        printf("El elemento no se encontró en el array.\n");
    }
    
    return 0;
}
