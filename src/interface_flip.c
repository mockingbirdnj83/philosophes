/*
** interface_flip.c for interface_flip in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:48:46 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:48:47 2015 aubess_t aubess_t
*/

#include "interface.h"
#include "interface_global.h"

int	flip()
{
  int	ret;

  if ((ret = SDL_Flip(g_graph.surfaces.screen)) < 0)
    console_err("SDL_Flip failed");
  return (ret);
}
