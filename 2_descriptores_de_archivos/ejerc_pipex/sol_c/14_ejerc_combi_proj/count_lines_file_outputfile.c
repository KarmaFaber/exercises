/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines_file_outputfile.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:34:01 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/09 13:46:24 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "14_ejerc.h"

void count_lines_file_outputfile(void)
{
	int fd;
	int lines;
	int saved_stdout;

	lines = count_lines_gnl();
	fd = open_fd("output.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);

	//save STDOUT_FILENO
    saved_stdout = dup(STDOUT_FILENO);
    if (saved_stdout == -1)
    {
        perror ("error al duplicar stdout");
        close(fd);
        exit (EXIT_FAILURE);
    }

	//redirigir stdout al archivo
	if (dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("error al duplicar stdout");
        close(fd);
		close(saved_stdout);
        exit (EXIT_FAILURE);   
    }
    close(fd);

	//Escribir al archivo (redirigido stdout)
	printf("lines: %i\n", lines);

	fflush(stdout); // Asegurarse de que el búfer de stdout se vacíe

	// Restaurar stdout original
    if (dup2(saved_stdout, STDOUT_FILENO) == -1)
    {
        perror("Error al restaurar stdout");
        close(saved_stdout);
       	exit (EXIT_FAILURE);
    }
    close(saved_stdout); // Cerrar el descriptor duplicado

}
