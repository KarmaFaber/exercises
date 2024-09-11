/*3. Insertar un Nodo al Final de la Lista
Descripción: Implementa una función que inserte un nodo al final de la lista enlazada. 
La función debe recibir un puntero a la cabeza de la lista y el valor del nuevo nodo.
Puntos clave: Recorrer la lista hasta el final, actualización del último nodo.*/

#include <stdio.h>
#include <stdlib.h>

//definicion de la estructura del nodo:
typedef struct s_list 
{
    void            *content;           //datos del nodo
    struct  s_list  *next;              //puntero al siguiente nodo

}                   t_list;             // alias del nodo

//definicion de la fucnion create_new_node
t_list *create_new_node(void *content)
{
    t_list *new_node;
    
    new_node = (t_list *)malloc(sizeof(t_list));
    if(!new_node)
        return (NULL);
    new_node -> content=content;
    new_node -> next = NULL;
    return (new_node);
}


void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp; //usamos puntero pempotral para no modificar el puntero original *lst
    
    temp=*lst; 
    if(!new)
        return ;
    if (!*lst)
    {
        *lst =new;
        return ;
    }
    while (temp -> next) //temp->next en el bucle while para recorrer la lista hasta que encuentre el último nodo.
        temp = temp -> next;
    temp -> next = new; // asigno temp->next = new;, lo que conecta el último nodo actual con el nuevo nodo.

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
    //crear los 3 nodos pedidos:
    t_list *node1;
    t_list *node2;
    t_list *node3;
    t_list *last_node;
    
    int *data1;
    int *data2;
    int *data3;
    int *data_last_node;
    
    //creamos y asignamos datos:
    data1=(int *)malloc(sizeof(int));
    if (data1 == NULL)
        return 1;
    *data1= 12;
    
    data2 = (int *)malloc(sizeof(int));
    if (data2 == NULL)
    {
        free(data1);
        return 1;
    }
    *data2 = 1235;
    
   data3 = (int *)malloc(sizeof(int));
    if (data3 == NULL)
    {
        free(data1);
        free(data2);
        return 1;
    }
    *data3 = 77;
    
    data_last_node = (int *)malloc(sizeof(int));
    if (data_last_node == NULL)
    {
        free(data1);
        free(data2);
        free(data3);
        return 1;
    }
    *data_last_node = 999;
        
    //creamos y asignamos doatos a nodos: 
     node1 = create_new_node(data1);
    if (node1 == NULL)
    {
        free(data1);
        free(data_last_node);
        return 1;
    }
            
    node2 = create_new_node(data2);
    if (node2 == NULL)
    {
        free(data2);
        free(data1);
        free(data_last_node);
        free(node1->content);
        free(node1);
        return 1;
    }

    node3 = create_new_node(data3);
    if (node3 == NULL)
    {
        free(data3);
        free(data2);
        free(data1);
        free(data_last_node);
        free(node1->content);
        free(node2->content);
        free(node1);
        free(node2);
        return 1;
    }

    last_node = create_new_node(data_last_node);
    if (last_node == NULL)
    {
        free(data_last_node);
        free(data3);
        free(data2);
        free(data1);
        free(node1->content);
        free(node2->content);
        free(node3->content);
        free(node1);
        free(node2);
        free(node3);
        return 1;
    }
    
    
    //enzalar los nodos:
    node1->next =node2;
    node2->next=node3;
    node3-> next = NULL;
    
    //Imprimir la lista nodos inicial:
    print_list(node1);
    
    //añadimos el nodo al final 
    ft_lstadd_back(&node1, last_node);
    
    //Imprimir la lista nodos despues de añadir el nodo nuevo:
    print_list(node1);
    
    // Liberar la memoria de los nodos y sus contenidos
    t_list *temp;
    while (node1)
    {
        temp = node1;
        node1 = node1->next;
        free(temp->content); // Liberar el contenido del nodo
        free(temp);          // Liberar el nodo
    }

    return 0;
}