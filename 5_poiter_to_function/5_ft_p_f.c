/*Ejercicio 5: Aplicación Condicional a un Array
Escribe un programa que aplique una función a los elementos de un array sólo si cumplen con una condición especificada por otra función.

Enunciado:

Define una función es_par que determine si un número es par.
Define una función es_impar que determine si un número es impar.
Crea una función aplicar_condicional que reciba un array, su tamaño, un puntero a una función de condición (como es_par) 
y un puntero a una función de aplicación (como doble del Ejercicio 3).
En el main, aplica una operación al array sólo sobre los elementos que cumplen con una condición dada.
Ejemplo de prototipo de la función aplicar_condicional:

void aplicar_condicional(int *array, int n, int (*condicion)(int), int (*funcion)(int));*/

#include <stdio.h>

//*f_condiciones:
int es_par(int a)
{
    if (a % 2 == 0)
        return 1;
    else 
        return -1;
}
int es_impar(int a)
{
    if (a%2 != 0)
        return 1;
    else 
        return -1;
}
//*f_funciones:
int ft_double(int a)
{
    return (2*a);
}
int incremento(int a)
{
    return a+=1;
}

void aplicar_condicional(int *array, int n, int (*condicion)(int), int (*funcion)(int))
{
    int i=0;
    while (i<n)
    {
        if (condicion(array[i]))
        {
            array[i]=funcion(array[i]);
        }
        i++;
    }
}

int main (void)
{
    int array[]= {1, 5, 77, 56, 102};
    int n = sizeof(array) / sizeof(array[0]);
    
    int (*f_condicional)(int)=es_impar;
    int (*f_function)(int)=incremento;
    
    aplicar_condicional(array, n, f_condicional, f_function);
    int i=0;
    while (i<n)
    {
        printf("resultado [%i]: %i.\n", i+1, array[i]);
        i++;
    }
    
    return (0);
}
