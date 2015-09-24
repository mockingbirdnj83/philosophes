/*
** philosophes_init.c for philosophes_init in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:52:43 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:52:44 2015 aubess_t aubess_t
*/

#include "philosophes.h"

pthread_mutex_t g_m = PTHREAD_MUTEX_INITIALIZER;
unsigned int	g_chopsticks[7];

void	init(t_sceptiques *tab)
{
  int	i;

  i = -1;
  while (++i < 7)
    {
      tab[i].id = i;
      tab[i].status = EATING;
      tab[i].hunger_base = 10 + rand() % 10;
      tab[i].hunger = tab[i].hunger_base;
      tab[i].digestion = 0;
      tab[i].stamina_base = 5 + rand() % 5;
      tab[i].stamina = tab[i].stamina_base;
      tab[i].intelligence = 5 + rand() % 5;
      tab[i].rice = 100;
      g_chopsticks[i] = 0;
      pthread_create(&(tab[i].nic), NULL, start_meeting, &(tab[i]));
    }
}
