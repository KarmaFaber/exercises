/*7. Contar el Número de Nodos en la Lista
Descripción: Implementa una función que recorra la lista enlazada y devuelva el número total de nodos.
Puntos clave: Recorrer la lista, contar nodos.*/


#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

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

//f() print_list:
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

/*int ft_lstsize(t_list *lst)
{
    t_list *position = lst;
    int counter;
    
    counter=0;
    while (position != NULL) 
    {
        position = position->next;
        counter++;
    }
    return (counter);
}*/

/*int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst && ++i)
		lst = lst->next;
	return (i);
}*/

int ft_lstsize(t_list *lst)
{
    int i;
    
    i = 0;
    while (lst) 
    {
        lst = lst-> next;
        i++;
    }
    return (i);
}


int main (void)
{
    //crear los 3 nodos pedidos:
    t_list *node1;
    t_list *node2;
    t_list *node3;
    
    int *data1;
    int *data2;
    int *data3;
    
    //creamos y asignamos datos:
    data1=(int *)malloc(sizeof(int));
    if (data1 == NULL)
        return 1;
    *data1= 12;
    
    data2=(int *)malloc(sizeof(int));
    if(data2 ==NULL)
        return 1;
    *data2 =1235;
    
    data3=(int *)malloc(sizeof(int));
    if (data3 ==NULL)
        return 1;
    *data3=77;
        
    //creamos y asignamos doatos a nodos: 
    node1=create_new_node(data1);
    if (node1== NULL)
        {
            free(data1);
            return 1; 
        }
            
    node2=create_new_node(data2);
    if (node2== NULL)
        {
        free(data2);
        free(node1->content);  // Liberar contenido de node1 si node2 falla
        free(node1);            //liberar la memoria del nodo1 si node2 falla
        return 1; 
    }
        
    node3=create_new_node(data3);
    if (node3== NULL)
        {
        free(data3);
        free(node1->content);  // Liberar contenido de node1 si node3 falla
        free(node2->content);  // Liberar contenido de node2 si node3 falla
        free(node1);            //liberar la memoria del nodo1 si node3 falla
        free(node2);            //liberar la memoria del nodo2 si node3 falla
        return 1; 
    }
    
    //enzalar los nodos:
    node1->next =node2;
    node2->next=node3;
    
    //Imprimir la lista de nodos:
    print_list(node1);
    
    //tamaño de la lista
    int list_size=ft_lstsize(node1);
    printf("tamaño lista: %i", list_size);
    
    //liberar la memoria de contenido del nodos
    free(node1-> content);
    free(node2-> content);
    free(node3-> content);
    
    //liberar la memoria de los nodos
    free(node1);
    free(node2);
    free(node3);
    
    return 0;
}
