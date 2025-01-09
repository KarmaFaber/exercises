/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:33:57 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/09 19:37:22 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "14_ejerc.h"

int count_lines_gnl(void)
{
	int fd;
	char *line;
	int line_count;

	line_count = 0;
	fd =open_fd("commands.txt", O_RDONLY, 0777);

	while (1)
	{
		line = get_next_line(fd);
		line_count++;
		if (line == NULL)
			break ;
		free(line);
		line = NULL;
	}
	if (close(fd) == -1)
	{
		perror("Error al cerrar el archivo");
		return (-1);
	}
	return (line_count);
}

int	open_fd(char *pathern, int flags, mode_t mode)
{
	int	fd;

	fd = open(pathern, flags, mode);
	if (fd == -1)
	{
		perror("error opening file");
		exit (EXIT_FAILURE);
	}
	return (fd);
}

void modif_and_write_buffer(int fd, char *buffer)
{
	int i = 0;
	while(buffer[i] != '\0')
	{
		if (buffer[i] >= 'a' && buffer[i] <= 'z')
		{
			buffer[i] -=32;
		}
		write(fd, &buffer[i], 1);
		i++;
	}
}


void	free_split_vars(char **split_to_free)
{
	int	i;

	if (!split_to_free)
		return ;
	i = 0;
	while (split_to_free[i])
	{
		free(split_to_free[i]);
		i++;
	}
	free(split_to_free);
}