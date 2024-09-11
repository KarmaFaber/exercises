/*6. Buscar un Valor en la Lista Enlazada
Descripción: Escribe una función que busque un valor específico en la lista enlazada 
y devuelva un puntero al nodo que lo contiene, o NULL si no se encuentra.
Puntos clave: Recorrer la lista, comparar valores.*/


#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

//definicion de la estructura del nodo:
typedef struct s_list 
{
    void            *content;           //datos del nodo
    struct  s_list  *next;              //puntero al siguiente nodo

}                   t_list;             // alias del nodo

t_list *create_new_node(void *content)  //funcion para crear un nodo nuevo
{
    t_list *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));    // asignamos memoria a la estuctura del nodo 't_list' que contiene puntero a 'content' y 'next'
    if(!new_node)
        return (NULL);
    new_node -> content = content;
    new_node -> next = NULL;
    return (new_node);
}

void print_list(t_list *head)
{
    t_list *position;
    
    position=head;
    while(position != NULL)
    {
        printf("%i -> ", *(int *)(position -> content)); //casteo del puntero a int,  ya que content es void *.
        position=position->next;
    }
    printf("NULL\n");  // Añadir para indicar el final de la lista
}

/**
 * @brief Searches for a specific value in a linked list.
 *
 * @param head Pointer to the head of the linked list.
 * @param val Integer value to search for in the list.
 *
 * @return Pointer to the node containing the value, or NULL if not found.
 */

t_list *find_node_n_val(t_list *head, int val)
{
    // Recorrer la lista hasta encontrar el valor o llegar al final
    while (head != NULL)
    {
        if (*(int *)(head->content) == val)
            return head; // Devolver el nodo si se encuentra el valor
        head = head->next;
    }
    return NULL; // Devolver NULL si no se encuentra el valor
}

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
    
    //encontrar nodo con n valor en la lista enlazada:
    t_list *n_node= find_node_n_val(nodo1, 5);
    if (n_node)
        printf("El nodo encontrado por valor contiene: %d\n", *(int *)n_node->content);
    else
        printf("La lista está vacía o hubo un error.\n");
            

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