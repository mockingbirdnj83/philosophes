/*
** main.h for main in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:52:20 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:52:21 2015 aubess_t aubess_t
*/

#ifndef PHILOSOPHE_H_
# define PHILOSOPHE_H_

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define	EXIT_SUCCESS	0
#define EXIT_FAILURE	1
#define RCS(id)		(id + 1 % 7)

typedef unsigned int	uint;

typedef enum		e_status
  {
    RESTING = 0,
    EATING,
    THINKING
  }			t_status;

typedef struct		s_sceptiques
{
  uint			id;
  t_status		status;
  uint			hunger_base;
  uint			hunger;
  uint			digestion;
  uint			stamina_base;
  uint			stamina;
  uint			intelligence;
  uint			rice;
  pthread_t		nic;
}			t_sceptiques;

void	init(t_sceptiques *);

#endif			/* !PHILOSOPHE */
