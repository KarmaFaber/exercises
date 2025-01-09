/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_char_own.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:05:57 by mzolotar          #+#    #+#             */
/*   Updated: 2024/09/09 19:14:56 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief  Converts an integer to its string representation.
 *
 * @param  n The integer to be converted.
 * @param  new_char A pointer to the allocated memory
	where the result will be stored.
 * @param  size The size of the string, including the sign and '\0'.
 *
 * @return A pointer to the resulting string.
 */

void	ft_int_to_char(int n, char *new_char, size_t size)
{
	new_char[size] = '\0';
	if (n == 0)
	{
		new_char[0] = '0';
		return ;
	}
	if (n < 0)
	{
		new_char[0] = '-';
		if (n == INT_MIN)
		{
			new_char[--size] = '8';
			n /= 10;
		}
		n = -n;
	}
	while (n > 0)
	{
		new_char[--size] = (n % 10) + '0';
		n /= 10;
	}
}
