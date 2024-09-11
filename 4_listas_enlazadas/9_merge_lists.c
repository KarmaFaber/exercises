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







int main(void) 
{
    // Declaración e inicialización de los datos
    int dato1 = 1;
    int dato2 = 2;
    int dato3 = 3;
    int dato4 = 4;
    int dato5 = 5;

    // Creación de los nodos
    t_list *nodo1 = create_new_node(&dato1);
    if (!nodo1) return 1; // Control de errores en la creación del nodo

    t_list *nodo2 = create_new_node(&dato2);
    if (!nodo2) {
        free(nodo1);
        return 1;
    }

    t_list *nodo3 = create_new_node(&dato3);
    if (!nodo3) {
        free(nodo2);
        free(nodo1);
        return 1;
    }

    t_list *nodo4 = create_new_node(&dato4);
    if (!nodo4) {
        free(nodo3);
        free(nodo2);
        free(nodo1);
        return 1;
    }

    t_list *nodo5 = create_new_node(&dato5);
    if (!nodo5) {
        free(nodo4);
        free(nodo3);
        free(nodo2);
        free(nodo1);
        return 1;
    }

    // Enlazar los nodos
    nodo1->next = nodo2;
    nodo2->next = nodo3;
    nodo3->next = nodo4;
    nodo4->next = nodo5;
    nodo5->next = NULL;

    // Imprimir la lista
    printf("\n");
    print_list(nodo1);
    printf("\n");
    
    
    //funcition:
           

    // Liberar la memoria asignada para los nodos
    t_list *current = nodo1;
    t_list *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}