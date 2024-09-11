/*2. Insertar un Nodo al Principio de la Lista.

Descripción: Escribe una función que inserte un nuevo nodo al principio de una lista enlazada dada. 
La función debe tomar como parámetros un puntero a la cabeza de la lista y el valor del nuevo nodo.
Puntos clave: Manejo de punteros, actualización de la cabeza de la lista.*/


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


/*La función ft_insert_at_head tiene como objetivo insertar un nuevo nodo al inicio de una lista enlazada simple en C.
t_list **head:
Es un puntero doble (t_list **) al puntero que apunta al primer nodo de la lista enlazada. Se usa un puntero doble porque 
la función puede modificar el puntero head para que apunte al nuevo nodo insertado.*/

/**
 * @brief Inserts a new node at the beginning of the linked list.
 *
 * This function creates a new node with the given content and inserts it 
 * at the head of the list. The new node becomes the new head of the list, 
 * and its next pointer points to the previous head node.
 *
 * @param head A double pointer to the head of the linked list. This allows 
 *             modification of the head pointer itself.
 * @param content A pointer to the content to be stored in the new node. 
 *                If the content is NULL, it will still create a node, but 
 *                the node's content pointer will be NULL.
 *
 * @return void
 */

void ft_add_node_front(t_list **head, void *content)
{
    t_list *new_node; //Declara un puntero new_node que se utilizará para almacenar el nuevo nodo que se creará.
    
    if (!content)
        return ;
    new_node=create_new_node(content);
    if (new_node)
    {
        new_node -> next = *head; //El puntero next del nuevo nodo ahora apunta al nodo que anteriormente estaba al inicio de la lista (*head).
        *head = new_node; //el puntero head se actualiza para que apunte al nuevo nodo, convirtiéndolo en el nuevo primer nodo de la lista.
    }
}

void print_list(t_list *head) 
{
    t_list *position = head;
    while (position != NULL) 
    {
        printf("%d -> ", *(int *)(position->content));
        position = position->next;
    }
    printf("NULL\n");
}

int main(void) {
    t_list *head = NULL;
    
    t_list *node1;
    t_list *node2;
    t_list *node3;
    t_list *node_head;

    int *data1 = (int *)malloc(sizeof(int));
    int *data2 = (int *)malloc(sizeof(int));
    int *data3 = (int *)malloc(sizeof(int));
    int *data_head = (int *)malloc(sizeof(int));
    
    if (data1 == NULL || data2 == NULL || data3 == NULL || data_head ==NULL)
        return 1;

    *data1 = 42;
    *data2 = 84;
    *data3 = 168;
    *data_head= 77;

    node1 = create_new_node(data1);
    node2 = create_new_node(data2);
    node3 = create_new_node(data3);
    node_head= create_new_node(data_head);
    
    if (!node1 || !node2 || !node3 || !node_head)
        return 1;


    //si no hacemos enlace de nodos, lo que haremos es incertar el nodox al principio de la lista
    //enzalar los nodos:
    node1->next =node2;
    node2->next=node3;
    
    //inicializar la lista con el primer nodo:
    head =node1;
    
    // Imprimir la lista modificada sin header
    print_list(head);
    printf("\n");
    
    // Insertar los nodos en la cabeza de la lista consecutivamente
    /*
    ft_add_node_front(&head, data3);  // Lista: 168 -> NULL
    ft_add_node_front(&head, data2);  // Lista: 84 -> 168 -> NULL
    ft_add_node_front(&head, data1);  // Lista: 42 -> 84 -> 168 -> NULL
    */


    ft_add_node_frontt(&head, data_head);
    
    // Imprimir la lista modificada con header
    print_list(head);

    // Liberar la memoria
    free(data1);
    free(data2);
    free(data3);
    
    t_list *current = head;
    while (current != NULL) 
    {
        t_list *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

