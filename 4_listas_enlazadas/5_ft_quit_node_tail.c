/*5. Eliminar el Último Nodo de la Lista
Descripción: Implementa una función que elimine el último nodo de una lista enlazada. 
Asegúrate de que el nuevo último nodo apunte a NULL.
Puntos clave: Recorrer la lista, actualizar el penúltimo nodo, liberar memoria.*/

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
 * @brief Deletes the last node of a singly linked list.
 *
 * @param head Double pointer to the head of the linked list.
 *
 * @return void
 */

void delete_node_tail(t_list **head)
{
    t_list *temp;
    t_list *prev;
    
    // 1. Si la lista está vacía, no hacemos nada
    if(*head== NULL)
        return ;
    // 2. Si solo hay un nodo en la lista
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    // 3. Buscar el penúltimo nodo
    temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next; 
    }

    // Ahora 'temp' es el penúltimo nodo, y 'temp->next' es el último nodo
    prev = temp; // 'prev' apunta al penúltimo nodo
    temp = temp->next; // 'temp' apunta al último nodo

    // Desconectar el último nodo
    prev->next = NULL;

    // Liberar la memoria del último nodo
    free(temp);
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
    
    //borrar el ultimo nodo
    delete_node_tail(&nodo1);
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