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


/*
	DESCRIPTION :
	The function ft_lstadd_front adds a new node to the front of a list:
		[NEW]->[.]->[.]->[.]->[NULL]

	RETURN VALUE :
	None.
*/

/**
 * @brief Adds a new node at the beginning of a linked list.
 *
 * This function checks if the list is empty. If it is, the new node
 * becomes the first and only node. If the list is not empty, the new
 * node is linked to the current first node, and then it becomes the
 * new head of the list.
 *
 * @param lst A pointer to the head of the list.
 * @param new The new node to be added at the beginning of the list.
 *
 * @return void
 */

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!*lst)
    {
        *lst = new; //Si la lista está vacía, simplemente se hace que *lst apunte al nuevo nodo new. Esto convierte a new en el primer y único nodo de la lista.
        return ;
    }
    if (new)
    {
        new -> next = *lst; //El puntero next del nuevo nodo ahora apunta al nodo que anteriormente estaba al inicio de la lista (*head).
        *lst = new; //el puntero head se actualiza para que apunte al nuevo nodo, convirtiéndolo en el nuevo primer nodo de la lista.
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


int main (void)
{
    
    t_list *head = NULL;

    t_list *node1;
    t_list *new_node;
    
    int *data;
    int *data_head;
    
    //crear un dato tipo int dinamicamente, asignamos memoria al valor real que almacenamos en 'data'. node1-> content apunta a esa memoria.
    
    data = (int *)malloc(sizeof(int));       
    if (data == NULL)
    {
        printf("error memoria enasignacion a 'data'");
        return 1;
    }
    
    data_head = (int *)malloc(sizeof(int));       
    if (data_head == NULL)
    {
        printf("error memoria enasignacion a 'data'");
        free(data);
        return 1;
    }
    
    *data = 12;         //asignar valor a data del node1
    *data_head = 77;
    
    //creamos 'node1' con data dentro:
    node1 = create_new_node(data);
    if (node1 == NULL)
    {
        printf("error al asignar memoria a 'node1'");
        free(data);
        free(data_head);
        return 1;
    }
    
    head=node1;
    
    new_node = create_new_node(data_head);
    if (new_node == NULL)
    {
        printf("error al asignar memoria a 'new_node'\n");
        free(data);
        free(data_head);
        free(node1);
        return 1;
    }
    
    //añadir nuevo nodo a la cabecera:
    ft_lstadd_front(&head, new_node);
    
    print_list(head);
    
    // Liberar memoria de la lista
    t_list *current = head;
    t_list *next_node;
    
    while (current != NULL)
    {
        next_node = current->next;
        free(current->content);
        free(current);
        current = next_node;
    }
    
    return 0;
}
