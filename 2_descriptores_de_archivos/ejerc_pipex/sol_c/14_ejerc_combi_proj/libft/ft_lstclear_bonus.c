/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:56:56 by mzolotar          #+#    #+#             */
/*   Updated: 2024/09/17 12:56:57 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	if (!*lst)
		return ;
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
