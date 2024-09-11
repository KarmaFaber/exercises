/*9. Fusionar Dos Listas Enlazadas
Descripción: Implementa una función que tome dos listas enlazadas como 
entrada y las fusione en una sola lista. La función debe devolver un puntero a la cabeza de la nueva lista fusionada.
Puntos clave: Manipulación de múltiples punteros, creación de una lista combinada.*/


#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

//definicion de la estructura del nodo:
typedef struct s_list 
{
    void            *content;           //datos del nodo
    struct  s_list  *next;              //puntero al siguiente nodo

}                   t_list;             // alias del nodo

