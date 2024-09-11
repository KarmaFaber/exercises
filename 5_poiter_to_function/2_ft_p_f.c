/*/*Ejercicio 2: Ordenación de Arrays con Funciones de Comparación
Implementa un programa que permita ordenar un array de enteros, 
donde la función de comparación puede cambiarse para ordenar de manera ascendente o descendente.

Enunciado:

Define dos funciones de comparación: comparar_ascendente y comparar_descendente, que devuelvan -1, 0, o 1 dependiendo del orden de los dos elementos comparados.
Crea una función ordenar que reciba un array, su tamaño y un puntero a la función de comparación, y que ordene el array de acuerdo a esta función.
En el main, pide al usuario que seleccione el tipo de orden (ascendente o descendente) y utiliza la función ordenar con la función de comparación adecuada.
void ordenar(int *array, int n, int (*comparar)(int, int));
*/

#include <stdio.h>
void ft_swap(int *a, int *b) 
{
    int aux;
   
    aux = *b; 
    *b = *a;
    *a = aux; 
}

/**
 * -1 si el primer número es menor que el segundo.
 * 0 si ambos números son iguales.
 * 1 si el primer número es mayor que el segundo. */

int comparar_ascendente(int a, int b)
{
    if (a==b)
        return (0);
    else if (a<b)
        return (-1);
    else 
        return (1); 
}

/**
 * -1 si el primer número es mayor que el segundo.
 * 0 si ambos números son iguales.
 * 1 si el primer número es menor que el segundo.*/

int comparar_descendente(int a, int b)
{
    if (a == b)
        return (0);
    else if (a>b)
        return (-1);
    else
        return (1);
}

//n --> tamaño del array
void ordenar(int *array, int n, int (*comparar)(int, int)) 
{
    int i = 0;
    while (i < n - 1) 
    {
        int j = 0;
        while (j < n - i - 1) 
        {
            if (comparar(array[j], array[j + 1]) > 0) //Aquí, comparar es un puntero a la función real (comparar_ascendente o comparar_descendente), que se pasa cuando ordenar es llamada.
            {
                ft_swap(&array[j], &array[j + 1]);
            }
            j++;
        }
        i++;
    }
}

int main()
{
    int array[]={1,5,6,77,0};
    int n = sizeof(array) / sizeof(array[0]);

    int (*f_ascendiente)(int, int)=comparar_ascendente; //decalramos ptro a funcion comparar_ascendente
    ordenar(array, n, f_ascendiente); //llamamos a la f() ordenar
    int i=0;
    while (i<n)
    {
        printf("resultado ascendiente [%i]: %i\n", i+1, array[i]);
        i++;
    }

    return 0;
}