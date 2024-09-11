/*11. Lista de Tareas Pendientes (To-Do List)
Descripción: Escribe un programa en C que simule una lista de tareas pendientes utilizando una lista enlazada simple. Cada nodo de la lista debe representar una tarea con un título y una prioridad. Debes implementar las siguientes funcionalidades:

Agregar una tarea al final de la lista.
Imprimir todas las tareas de la lista.
Eliminar la primera tarea de la lista (la que se completó).
Buscar una tarea por su título.
Requisitos:

La tarea debe contener un título (char *) y un valor de prioridad (int).
Debes permitir agregar tareas nuevas al final de la lista.
La función de búsqueda debe devolver la tarea o indicar si no se encontró.
Objetivos:

Crear una lista de tareas.
Recorrer la lista para imprimir las tareas.
Eliminar tareas y liberar la memoria.*/


#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

//definicion de la estructura del nodo:
typedef struct s_list 
{
    void            *content;           //datos del nodo
    struct  s_list  *next;              //puntero al siguiente nodo

}                   t_list;             // alias del nodo

