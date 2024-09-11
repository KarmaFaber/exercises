/*12. Implementación de Colas (Queues)
Descripción: Escribe un programa en C que implemente una cola utilizando una lista enlazada simple. En una cola, los elementos se agregan al final (operación de enqueue) y se eliminan del principio (operación de dequeue). Debes implementar las siguientes funcionalidades:

Encolar (agregar) un elemento al final de la cola.
Desencolar (eliminar) un elemento del principio de la cola.
Imprimir todos los elementos de la cola.
Ver el primer elemento de la cola sin eliminarlo (operación peek).
Requisitos:

La cola debe almacenar valores enteros en cada nodo.
Los nodos deben estar conectados en el orden en que los elementos fueron encolados.
El programa debe manejar correctamente los casos de cola vacía.
Objetivos:

Implementar las operaciones básicas de una cola (enqueue, dequeue, peek).
Manejar condiciones especiales como cola vacía.*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

//definicion de la estructura del nodo:
typedef struct s_list 
{
    void            *content;           //datos del nodo
    struct  s_list  *next;              //puntero al siguiente nodo

}                   t_list;             // alias del nodo

