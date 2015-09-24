/*
** interface_process.c for interface_process in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:50:46 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:50:47 2015 aubess_t aubess_t
*/

#include "interface.h"

int	process(t_sceptiques *tab)
{
  int	i;

  i = -1;
  while (++i < 7)
    if (tab[i].rice > 0)
      return (0);
  return (-1);
}
