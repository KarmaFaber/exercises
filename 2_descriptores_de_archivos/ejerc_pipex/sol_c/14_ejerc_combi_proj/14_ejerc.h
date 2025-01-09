#ifndef SO_LONG_H
# define SO_LONG_H

/* ********** includes ********** */
# include "libft/libft.h"

#include <stdio.h> //perror
#include <unistd.h> // read, write, dup2, dup
#include <fcntl.h> // open
#include <string.h> // strerror
#include <errno.h>	//errno+referencias de error
#include <stdlib.h> //exit
#include <sys/wait.h> //wait

/* ********** main ********** */
int main(void);


/* ********** execcises ********** */
//cat_sim_stdout.c
void read_command_file(void);

//chose_comm_file.c
void chose_comm_file(void);

//count_lines_file_outputfile.c
void count_lines_file_outputfile(void);

//count_lines_file_stdout.c
void count_lines_file_stdout(void);

//encript_text.c
void encript_text(void);

//read_comm_file.c
void read_comm_file(void);

//utils.c
int count_lines_gnl(void);
int	open_fd(char *pathern, int flags, mode_t mode);
void modif_and_write_buffer(int fd, char *buffer);


#endif


