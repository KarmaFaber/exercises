/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper_own.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:07:47 by mzolotar          #+#    #+#             */
/*   Updated: 2024/09/09 19:21:08 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Check if a character is uppercase.
 *
 * @param c	The character to check.
 *
 * @return	1 if the character is uppercase, 0 otherwise.
 */

int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
