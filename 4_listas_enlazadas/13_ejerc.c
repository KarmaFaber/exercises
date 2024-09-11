/*13. Implementación de Pilas (Stacks)
Descripción: Escribe un programa en C que implemente una pila utilizando una lista enlazada simple. En una pila, los elementos se agregan y eliminan del mismo extremo (operación de push y pop). Debes implementar las siguientes funcionalidades:

Apilar (agregar) un elemento al principio de la pila (push).
Desapilar (eliminar) un elemento del principio de la pila (pop).
Imprimir todos los elementos de la pila.
Ver el elemento en la cima de la pila sin eliminarlo (peek).
Requisitos:

La pila debe almacenar valores enteros en cada nodo.
Los elementos se deben apilar y desapilar del mismo extremo (LIFO - Last In, First Out).
El programa debe manejar correctamente los casos de pila vacía.
Objetivos:

Implementar las operaciones básicas de una pila (push, pop, peek).
Usar punteros correctamente para modificar la estructura de la pila.*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

//definicion de la estructura del nodo:
typedef struct s_list 
{
    void            *content;           //datos del nodo
    struct  s_list  *next;              //puntero al siguiente nodo

}                   t_list;             // alias del nodo

