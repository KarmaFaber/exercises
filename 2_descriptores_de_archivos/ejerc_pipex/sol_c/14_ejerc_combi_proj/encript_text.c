/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encript_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:52:08 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/09 13:52:56 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "14_ejerc.h"

void encript_text(void)
{
	int fd;
	char buffer[1000];
	ssize_t readed_bites;
	int saved_stdin;

	fd = open_fd ("input.txt", O_RDONLY, 0777);

	saved_stdin = dup(STDIN_FILENO);
	if (saved_stdin == -1)
	{
		perror("error al duplicar stdin");
		close (fd);
		exit (EXIT_FAILURE);
	}

	//redifigir stdin al archivo
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("error al duplicar stdin");
		close(fd);
		close(saved_stdin);
		exit (EXIT_FAILURE);
	}
	close(fd);

	//read fd
    readed_bites = read(STDIN_FILENO, buffer, sizeof(buffer)-1);
    if (readed_bites == -1)
    {
        perror("error al leer el archivo");
        close(saved_stdin);
        exit (EXIT_FAILURE);;
    }
    buffer[readed_bites] ='\0';


	// Restaurar stdin original
    if (dup2(saved_stdin, STDIN_FILENO) == -1)
    {
        perror("Error al restaurar stdin");
        close(saved_stdin);
        exit (EXIT_FAILURE);
    }
    close(saved_stdin); // Cerrar el descriptor duplicado

	// escribir en destination.txt
	//open write_only
    fd = open_fd ("output.txt", O_WRONLY, 0777);

	//write modif buffer in destination.txt
	modif_and_write_buffer(fd, buffer);

	//close fd
    if (close(fd) == -1)
    {
        perror ("error al cerrar el fd");
        exit (EXIT_FAILURE);
    }

	return;
}