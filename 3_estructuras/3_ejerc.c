/*Ejercicio 3: Función que Recibe una Estructura
Descripción: Define una estructura llamada Punto que contenga los siguientes miembros:

x (entero)
y (entero)
Escribe una función que reciba un Punto como argumento y que imprima las coordenadas del punto en el formato "(x, y)".

Pista: La función puede tener la siguiente firma:

void imprimirPunto(struct Punto p);
*/

#include <stdio.h>
#include <string.h>

struct Punto
{
    int x;
    int y;
};

void imprimir(struct Punto p)
{
    printf("coordenadas: (%i, %i)\n", p.x, p.y);
}

int main (void)
{
    struct Punto punto;
    punto.x=10;
    punto.y =20;
    
    imprimir(punto);
    return 0;
}