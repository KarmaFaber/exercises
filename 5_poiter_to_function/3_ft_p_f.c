/*Ejercicio 3: Aplicación de Funciones a un Array
Escribe un programa que aplique una función a cada elemento de un array.

Enunciado:

Define una función doble que reciba un entero y devuelva el doble de este.
Define una función incremento que reciba un entero y devuelva el siguiente número.
Crea una función aplicar_a_array que reciba un array, su tamaño y un puntero a una función que se aplicará a cada elemento del array.
Dentro del main, aplica las funciones doble e incremento al array y muestra el resultado.
Ejemplo de prototipo de la función aplicar_a_array:

void aplicar_a_array(int *array, int n, int (*funcion)(int));*/
#include <stdio.h>

int doble(int a)
{
    return (2*a);
}
int incremento(int a)
{
    return a+=1;
}

void aplicar_a_array(int *array, int n, int (*funcion)(int))
{
    int i=0;
    while (i<n)
    {
        array[i]=funcion(array[i]);
        i++;
    }
    return funcion(array);
}

int main (void)
{

    int array[]={1,5,6,77,0};
    int n = sizeof(array) / sizeof(array[0]);

    int (*f_pointer)(int)=incremento;
    aplicar_a_array(array, n, f_pointer);

    int i=0;
    while (i<n)
    {
        printf("resultado [%i]: %i\n", i+1, array[i]);
        i++;
    }

    return 0;
}