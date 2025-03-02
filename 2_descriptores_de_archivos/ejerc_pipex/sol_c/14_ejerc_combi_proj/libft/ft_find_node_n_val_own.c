/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_node_n_val_own.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:06:06 by mzolotar          #+#    #+#             */
/*   Updated: 2024/09/09 19:18:45 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Searches for a specific value in a linked list.
 *
 * @param head Pointer to the head of the linked list.
 * @param val Integer value to search for in the list.
 *
 * @return Pointer to the node containing the value, or NULL if not found.
 */

t_list	*ft_find_node_n_val(t_list *head, int val)
{
	while (head != NULL)
	{
		if (*(int *)(head->content) == val)
			return (head);
		head = head->next;
	}
	return (NULL);
}
