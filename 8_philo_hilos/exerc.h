/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exerc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:01:15 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/29 19:24:45 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H


//#➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──includes:──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#
# include <stdbool.h>	//bool
# include <unistd.h> 	// write, usleep 
# include <stdlib.h> 	// malloc, free
# include <stdio.h> 	//printf
# include <string.h> 	// memset
# include <sys/time.h> 	//gettimeofday
# include <pthread.h> 	//pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock

//#➵⤐──╌╌➣⋆➣╌─⤏➵•➵⤐──╌╌➣⋆➣╌╌──Structures  :──╌╌➣⋆➣╌╌⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

typedef struct s_data 
{
    int turn;           // Variable compartida
    pthread_mutex_t mutex;  // Mutex para evitar condiciones de carrera
}	t_data;



#endif