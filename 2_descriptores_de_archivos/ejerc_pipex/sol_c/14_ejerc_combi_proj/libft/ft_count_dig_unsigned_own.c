/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_dig_unsigned_own.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:51:26 by mzolotar          #+#    #+#             */
/*   Updated: 2024/09/09 19:25:32 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the digits in an unsigned integer.
 *
 * This function calculates the number of digits in a given unsigned
 * integer by repeatedly dividing it by 10.
 *
 * @param number The unsigned integer whose digits are to be counted.
 *
 * @return size_t The number of digits in the unsigned integer.
 */

#include "libft.h"

size_t	ft_count_digits_unsigned(unsigned int number)
{
	size_t	count;

	count = 0;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}
