/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_own.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:06:49 by mzolotar          #+#    #+#             */
/*   Updated: 2024/09/09 19:06:50 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Swaps the values of two integers.
 *
 * This function takes two integer pointers as arguments and swaps
 * the values they point to. The value of the integer pointed to
 * by `a` is exchanged with the value of the integer pointed to by `b`.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */

void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *b;
	*b = *a;
	*a = aux;
}
