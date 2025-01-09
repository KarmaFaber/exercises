/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_own.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:08:08 by mzolotar          #+#    #+#             */
/*   Updated: 2024/09/09 19:20:47 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief   Checks if the given character is a whitespace character.
 *
 * This function checks if the character passed as an argument is a whitespace
 * character, which includes space, tab, newline, vertical tab,
 * form feed, and carriage return.
 *
 * @param   c The character to be checked, represented as an integer.
 *
 * @return  1 if the character is a whitespace character, 0 otherwise.
 */

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}
