#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
    void            *content;
    struct s_list    *next;
} t_list;

void print_list(t_list *head)
{
    t_list *position;

    position = head;
    while (position != NULL)
    {
        printf("%d -> ", *(int *)(position->content)); // Cast to int
        position = position->next;
    }
    printf("NULL\n");
}

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *head;
    t_list *temp;

    if (!*lst)
        return;

    head = *lst;

    while (head)
    {
        temp = head->next;
        (*del)(head->content);
        free(head);
        head = temp;
    }
    *lst = NULL;
}

// A simple function to be used with ft_lstmap
void *increment_value(void *data)
{
    int *input = (int *)data;          // Cast the void* to int*
    int *result = (int *)malloc(sizeof(int)); // Allocate memory for the result

    if (result == NULL)               // Check if malloc failed
        return NULL;                 // Return NULL if memory allocation failed

    *result = *input + 1;            // Increment the value and store it
    return result;                   // Return the new value
}

t_list *ft_lstnew(void *content)
{
    t_list *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->content = content;
    new_node->next = NULL;
    return (new_node);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp;

    temp = *lst;
    if (!new)
        return;
    if (!*lst)
    {
        *lst = new;
        return;
    }
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}


t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			(del)(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	new_node->next = NULL;
	return (new_lst);
}

int main(void)
{
    // Declaration and initialization of the data
    int *dato1 = (int *)malloc(sizeof(int));
    int *dato2 = (int *)malloc(sizeof(int));
    int *dato3 = (int *)malloc(sizeof(int));
    int *dato4 = (int *)malloc(sizeof(int));
    int *dato5 = (int *)malloc(sizeof(int));

    if (!dato1 || !dato2 || !dato3 || !dato4 || !dato5)
    {
        free(dato1);
        free(dato2);
        free(dato3);
        free(dato4);
        free(dato5);
        return 1;
    }

    *dato1 = 1;
    *dato2 = 2;
    *dato3 = 3;
    *dato4 = 4;
    *dato5 = 5;

    // Create nodes
    t_list *nodo1 = ft_lstnew(dato1);
    t_list *nodo2 = ft_lstnew(dato2);
    t_list *nodo3 = ft_lstnew(dato3);
    t_list *nodo4 = ft_lstnew(dato4);
    t_list *nodo5 = ft_lstnew(dato5);

    if (!nodo1 || !nodo2 || !nodo3 || !nodo4 || !nodo5)
    {
        ft_lstclear(&nodo1, free);
        ft_lstclear(&nodo2, free);
        ft_lstclear(&nodo3, free);
        ft_lstclear(&nodo4, free);
        ft_lstclear(&nodo5, free);
        return 1;
    }

    // Link the nodes
    nodo1->next = nodo2;
    nodo2->next = nodo3;
    nodo3->next = nodo4;
    nodo4->next = nodo5;

    // Print the original list
    printf("Original list:\n");
    print_list(nodo1);

    // Apply ft_lstmap with increment_value function
    t_list *new_list = ft_lstmap(nodo1, increment_value, free);

    // Print the new list
    printf("New list:\n");
    if (new_list)
        print_list(new_list);
    else
        printf("The list is empty or there was an error.\n");

    // Free the original list
    ft_lstclear(&nodo1, free);

    // Free the new list
    ft_lstclear(&new_list, free);

    return 0;
}
