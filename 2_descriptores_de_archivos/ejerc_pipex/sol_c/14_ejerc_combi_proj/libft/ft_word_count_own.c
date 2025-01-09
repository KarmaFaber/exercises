/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count_own.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 08:20:28 by mzolotar          #+#    #+#             */
/*   Updated: 2024/09/25 08:24:37 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of words in a string separated by a delimiter.
 *
 * @param s Pointer to the input string to analyze.
 * @param delimiter Character used to separate words in the input string.
 *
 * @return The number of words found in the string.
 */

size_t	ft_count_words(const char *s, char delimiter)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (*s != delimiter && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == delimiter)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}
