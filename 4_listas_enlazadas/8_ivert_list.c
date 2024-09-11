/*8. Invertir una Lista Enlazada
Descripción: Escribe una función que invierta una lista enlazada simple. 
Es decir, el primer nodo se convertirá en el último y viceversa.
Puntos clave: Manipulación de punteros, lógica de inversión.*/


#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

//definicion de la estructura del nodo:
typedef struct s_list 
{
    void            *content;           //datos del nodo
    struct  s_list  *next;              //puntero al siguiente nodo

}                   t_list;             // alias del nodo

