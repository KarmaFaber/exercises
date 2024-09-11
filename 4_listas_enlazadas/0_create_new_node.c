/*0. Crear un nodo nuevo. asignarle valor a content e impirmir el dato guardado en el nodo. 
*/

#include <stdlib.h>
#include <stdio.h>

//definicion de la estructura del nodo:
typedef struct s_list 
{
    void    *content;        //datos del nodo
    struct  s_list  *next;  //puntero al siguiente nodo

}   t_list;                 // alias del nodo

/**
 * @brief Creates a new node for a linked list.
 *
 * This function allocates memory for a new node, initializes the node's 
 * content with the provided value, and sets the next pointer to NULL.
 *
 * @param content Pointer to the data that will be stored in the new node.
 *
 * @return t_list* Pointer to the newly created node, or NULL if allocation 
 * fails.
 */
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

int main (void)
{
    t_list *node1;
    int *data;
    
    //crear un dato tipo int dinamicamente, asignamos memoria al valor real que almacenamos en 'data'. node1-> content apunta a esa memoria.
    data = (int *)malloc(sizeof(int));       
    if (data==NULL)
    {
        printf("error memoria enasignacion a 'data'");
        return 1;
    }
    
    *data = 12;         //asignar valor a data del node1
    
    //creamos 'node1' con data dentro:
    node1 = create_new_node(data);
    if (node1 ==NULL)
    {
        printf("error al asignar memoria a 'node1'");
        free(data);
        return 1;
    }
    
    printf("data node1: %d", *(int *)(node1 -> content));  //imprimir el contenido del nodo 'node1' que es puntero a int
     
    free(node1->content); //liberar memoria del contenido
    free(node1);           //liberar la memoria del nodo
    
    return 0;
}