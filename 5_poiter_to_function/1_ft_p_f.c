/*Ejercicio 1: Operaciones Matemáticas con Funciones
Crea un programa que pueda realizar diferentes operaciones matemáticas (suma, resta, multiplicación, división)
sobre dos números. Usa punteros a funciones para seleccionar la operación deseada.

Enunciado:
1. Define cuatro funciones que realicen las operaciones básicas: suma, resta, multiplicación, y división.
2. Crea una función calcular que reciba tres argumentos: dos números y un puntero a una función que realice la operación sobre estos números.
*/

#include <stdio.h>
int suma_f(int a, int b)
{
    return (a+b);
}
int resta_f(int a, int b)
{
    return (a-b);
}
int divicion_f(int a, int b)
{
    return (a/b);
}
int multiplicacion_f(int a, int b)
{
    return (a*b);
}

int calcular(int a, int b, int (*f)(int, int))
{
    return f(a, b);
}


int main(void)
{
    int a=10;
    int b =2;

    int (*funcion_suma)(int, int); // declaracion de puntero a funcion suma_f().
    funcion_suma=suma_f; //inicializamos puntero a funcion suma
    int resultado_suma;
    resultado_suma=calcular(a, b, funcion_suma); // llamar a la funcion calcular a traves de punteros
    printf("el resultado de la suma es: %i\n", resultado_suma);


    int (*f_resta)(int, int);
    f_resta=resta_f;
    int resultado_resta;
    resultado_resta=calcular(a, b, f_resta);
    printf("el resultado de la resta es: %i\n", resultado_resta);


    int (*f_div)(int, int);
    f_div=divicion_f;
    int resultado_div;
    resultado_div=calcular(a, b, f_div);
    printf("el resultado de la division es: %i\n", resultado_div);



    int (*f_multi)(int, int);
    f_multi = multiplicacion_f;
    int resultado_multi;
    resultado_multi=calcular(a, b, f_multi);
    printf("el resultado de lamiltiplicacion es: %i\n", resultado_multi);
    return 0;
}
