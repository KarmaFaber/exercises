/*Ejercicio 4: Modificación de Miembros a Través de un Puntero
Descripción: Define una estructura llamada Rectangulo que contenga los siguientes miembros:
largo (flotante)
ancho (flotante)
Escribe una función que reciba un puntero a un Rectangulo y modifique sus dimensiones (largo y ancho). Luego, imprime los valores modificados.

Pista: La función puede tener la siguiente firma: void modificarRectangulo(struct Rectangulo *r);
*/

#include <stdio.h>
struct Rectangulo
{
    float largo;
    float ancho;
};

void imprimir(struct Rectangulo r)
{
    printf("rectangulo: (%.2f, %.2f)\n", r.largo, r.ancho);
}

void modificar_largo (struct Rectangulo *r, float new_largo)
{
    r -> largo = new_largo;
}

void modificar_ancho (struct Rectangulo *r, float new_ancho)
{
    r -> ancho = new_ancho;
}

void modificar_rectangulo(struct Rectangulo *r, float new_largo, float new_ancho)
{
    r -> largo = new_largo;
    r -> ancho = new_ancho;
}

void swap (struct Rectangulo *r)
{
    float aux;

    aux = r -> largo;
    r -> largo = r -> ancho;
    r -> ancho = aux;
}

int main(void)
{
    struct Rectangulo rec1;
    rec1.largo=1.20;
    rec1.ancho=3.2;

    printf("\nrectangulo original:\n");
    imprimir(rec1);

    printf("\nrectangulo modificado:\n");
    modificar_largo(&rec1, 6.223);
    imprimir(rec1);

    printf("\nrectangulo swap:\n");
    swap(&rec1);
    imprimir(rec1);
    
    printf("\nrectangulo modificado los dos:\n");
    modificar_rectangulo(&rec1, 2.00, 7.55);
    imprimir(rec1);

    printf("\n\n");
    
    return 0;
}