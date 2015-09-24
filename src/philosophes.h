/*
** philosophes.h for philosophes in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:52:31 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:52:32 2015 aubess_t aubess_t
*/

#ifndef			PHILOSOPHE_H_
# define		PHILOSOPHE_H_

#include		<pthread.h>
#include		<stdio.h>
#include		<unistd.h>
#include		<stdlib.h>

#define RCS(id)		(id + 1 % 7)

#define RICE_MAX	(100)
#define STAMINA_MAX	(10)
#define HUNGER_MAX	(19)
#define INTELLI_MAX	(9)
#define DIGESTION_MAX	(3)
#define	SPEED		(300000)

typedef unsigned int	uint;

typedef enum		e_status
  {
    RESTING = 0,
    EATING,
    THINKING,
    LEFT
  }			t_status;

typedef struct		s_sceptiques
{
  uint			id;
  char			*name;
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

void			init(t_sceptiques *);
void			*start_meeting(void *);

#endif			/* !PHILOSOPHE */
