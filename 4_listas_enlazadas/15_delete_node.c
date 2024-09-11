#include <stdlib.h>
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
 * @brief Deletes a specified node from a linked list.
 *
 * This function removes a node from a linked list. It handles the case 
 * where the node to be deleted is the head of the list, as well as 
 * the case where it is a middle or last node. After the node is removed, 
 * the memory allocated for the node is freed.
 *
 * @param head Pointer to the pointer to the head of the linked list.
 * @param node_to_delete Pointer to the node that needs to be deleted.
 *
 * @return None.
 */

void ft_delete_node(t_list **head, t_list *node_to_delete)
{
    t_list *current;
    t_list *prev;

    // Verificar si la lista o el nodo a eliminar son NULL
    if (head == NULL || *head == NULL || node_to_delete == NULL)
        return;

    // Si el nodo a eliminar es el primer nodo
    if (*head == node_to_delete)
    {
        *head = (*head)->next; // Actualizar la cabeza de la lista
        free(node_to_delete);  // Liberar el nodo eliminado
        return;
    }

    // Buscar el nodo a eliminar
    current = *head;
    while (current != NULL && current->next != node_to_delete)
    {
        current = current->next;
    }

    // Si encontramos el nodo a eliminar
    if (current != NULL)
    {
        prev = current;
        prev->next = node_to_delete->next; // Reajustar el enlace
        free(node_to_delete); // Liberar el nodo eliminado
    }
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
    
    
    // Eliminar el nodo con valor 3 (nodo3)
    ft_delete_node(&nodo1, nodo3);

    // Imprimir la lista después de eliminar el nodo
    printf("List after deleting node with value 3:\n");
    print_list(nodo1);       

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
